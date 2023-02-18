
/****
 * hw - simulacao do hardware para IO e de um controlador de porta serie
 *    fortemente baseado na UART dos PC para a porta serie 1
 * AC - MIEI - FCT/UNL
 * 2018 vad
 ****/

/* tipo BYTE que representa um byte (8bits)*/
typedef unsigned char BYTE;

/* iniciar simulador de IO e perifericos
 * args - indicar o ficheiro ou terminal que simula a porta serie
 *        ou NULL para usar o stdou e stdin do programa
 */
void hwInit( char *args );

/* simulacao das instrucoes IN e OUT do CPU */
BYTE in( int port );
void out( int port, BYTE data );
