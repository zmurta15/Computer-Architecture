#include <stdio.h>
#include <ctype.h>

#define SZ 5 // o texto tem de ter pelo menos estes caracteres

int main( int argc, char *argv[] ) {
	 FILE *f;
	 // Verificar o num. argumentos na linha de comando
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
	
// TODO: completar . . .

	return 0;
 }
