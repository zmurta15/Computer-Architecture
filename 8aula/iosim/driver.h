
/****
 * driver - "device driver" para porta serie 1
 * AC - MIEI - FCT/UNL
 * 2018/19 vad
 ****/

/* operacoes suportadas:
 * - enviar um byte 
 * - receber byte 
 * - esperar confirmacao do envio do ultimo byte
 */


void sendSerial( unsigned char c );

unsigned char recvSerial( void );

void waitSerial(void);
