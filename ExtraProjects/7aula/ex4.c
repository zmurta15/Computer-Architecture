#include <stdio.h>

extern void printSoma( char *str1, char *str2 );

int main( int argc, char*argv[] ) {
	if (argc != 3) {
	fprintf( stderr, "Usage: %s <int_num> <int_num>\n", argv[0] );
	return 1;
	}
	printSoma( argv[1], argv[2] );
	return 0;
}


//se em c
/*int printSoma(char *arg1, char *arg2) {
	int x = atoi(arg1);
	int y = atoi(arg2);
	x = x+y;
	printf("%d\n", x);

}*/