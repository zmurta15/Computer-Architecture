
#include <stdio.h>
#include <unistd.h>

#include "hw.h"
#include "driver.h"


#define TXBIT (1<<5)
#define RXBIT 1

void sendSerial( unsigned char c ) {
	while ((in(0x3fd) & 0x20) == 0);    /*polling STATUS*/        
    out( 0x3f8, c );
}

unsigned char recvSerial( void ) { 
	while((in(0x3fd) & 0x01) ==0);
    return in( 0x3f8 );
}

void waitSerial(void) {
    while ( 0 ) // TODO
       usleep(1);
}

