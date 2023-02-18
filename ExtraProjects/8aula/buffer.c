#include <stdio.h>
#include <unistd.h>

#define NSEC 10
int main( ) {
	 printf("Contando tempo: ");
	 for ( int i=0; i<NSEC; i++ ) {
		// putchar('\n');
		 printf(" %d", i );
		 fflush(stdout);
		 //putchar('\n');
		 sleep(1); // espera 1 segundo
 }
 putchar('\n');
 return 0;
}
