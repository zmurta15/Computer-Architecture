
/* teste de mylib
 * le o ficheiro indicado e envia todo o seu conteudo usando
 * myPutChar de mylib, para o fazer sair pela "porta serie"
 */
#include <stdio.h>
#include <unistd.h>

#include "hw.h"  // so' para iniciar com hwInit
#include "driver.h"


int main(int argc, char *argv[]) {
    FILE *f;
    int c;
    
    hwInit( "/dev/tty" );  // inicia hw

    // Verificar os argumentos da linha de comando
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Tentar abrir o ficheiro para leitura
    f=fopen (argv[1], "r");
    if (f== NULL) {
        printf("Invalid file: %s\n", argv[1]);
        return 1;
    }
 
    // Ler os caracteres do ficheiro e "envia-os" 
    while ( (c=fgetc(f))!=EOF ) {
         sendSerial(c);
    }

    // Fechar o ficheiro
    fclose(f);

    // aguardar pelo fim da transferencia
    waitSerial();
 
    return 0;
}
