#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#include "hw.h"

#define MAXPORTS  0x400

/* configuracao dos ports dos perifericos */
static BYTE (*readPort[MAXPORTS])(void);  // operacoes para simular a sua leitura
static void (*writePort[MAXPORTS])(int);  // operacoes para simular a sua escrita


/************************************************************/

BYTE in( int port ) {
    return readPort[port]();  // ler do port
}

void out( int port, BYTE data ) {
    writePort[port]( data );  // escrever no port
}

/************************************************************/

/* IBM/PC UART/serial port COM1: (usually BASE = 0x3f8)
 * IO ports:
 * BASE+0 DATA  (1Byte; envio quando escrito; recepcao quando lido)
 * BASE+1 CONTROL 
 * BASE+5 STATUS
 */
/* internal registers */
volatile BYTE DATA_TX = 0;
volatile BYTE DATA_RX = 0;
volatile BYTE CONTROL = 0;
volatile BYTE STATUS = 0;

char *dev = NULL;

/* Status bits */
#define RXREADY (1)    // bit 0
#define TXREADY (1<<5) // bit 5

/***/
pthread_cond_t dataready = PTHREAD_COND_INITIALIZER;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *devSender( void *arg ) {
    // device is working...
    FILE *outdev; 
    if ( dev == NULL ) outdev = stdout;
    else outdev = fopen( dev, "w" );
    if ( outdev == NULL ) {
        perror("dev: can't send");
    }
    while (1) {
        pthread_mutex_lock( &lock );
        while ( (STATUS&TXREADY)!=0) 
           pthread_cond_wait( &dataready, &lock ); // wait for work
        pthread_mutex_unlock( &lock );
        // do work
        fputc( DATA_TX, outdev );
        fflush( outdev );
        usleep( 200 );
        STATUS = STATUS | TXREADY;  // again ready to send
    }
}

void *devReceiver( void *arg ) {
    // device is working...
    FILE *indev; 
    if ( dev == NULL ) indev = stdin;
    else indev = fopen( dev, "r" );
    if ( indev == NULL ) {
        perror("dev: can't receive");
    }
    while (1) {
        usleep( 50 );
        DATA_RX = fgetc( indev ); // wait for work
        STATUS = STATUS | RXREADY;  // new byte to read
    }
}

void devInit( char *file ) {
    pthread_t tid;
    dev = file; // "/dev/tty" e' o proprio terminal onde executa
                // pode ser um device /dev/tty* (fazer sleep 999 nesse terminal)
                // para usar ficheiros normais so' pode correr um dos threads
                // seguintes
    int status1 = pthread_create( &tid, NULL, devSender, NULL );
    int status2 = pthread_create( &tid, NULL, devReceiver, NULL );

    if ( status1 != 0 || status2 != 0 || dev == NULL ) {
        perror( "devInit: device failed to start!" );
	    exit(1);
    }
    STATUS = TXREADY;  // ready to send
    //printf("UART ready!\n");
}


BYTE getStatus(void) {
    usleep(1);
    return STATUS;
}

BYTE getData(void) {
    usleep(1);
    STATUS = STATUS & ~RXREADY;
    return DATA_RX;
}

void setData( BYTE data ) {
    usleep(1);
    DATA_TX = data;
    pthread_mutex_lock(&lock);
    // start sending
    STATUS = STATUS & ~TXREADY;
    pthread_cond_signal( &dataready );
    pthread_mutex_unlock( &lock );
}

void setControl( BYTE cmd ) {
    usleep(1);
    CONTROL = cmd;
    // do some work
}

/******************************************************/


void none(void) { } // funcao que nao faz nada

void hwInit( char *args ) {
    /* iniciar o device semelhante a UART e registar os seus ports */
    devInit( args );
#pragma GCC diagnostic ignored "-Wincompatible-pointer-types"
    readPort[0x3f8] = getData;
    writePort[0x3f8] = setData;
    readPort[0x3f9] = none;
    writePort[0x3f9] = setControl;
    readPort[0x3fd] = getStatus;
    writePort[0x3fd] = none;
    // todos os outros ports deviam estar a none, mas vamos deixar abortar
    // para ser mais facil encontrar erros
    printf("hwInit done!\n");
}
