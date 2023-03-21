/*  AC - ficha 7 2017/18 MIEI
 *  DI/FCT/UNL
 */
#include <stdio.h>
#include <stdlib.h>

extern int fib(int n);

/*int fibonacci( int n ) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}*/

int main( int argc, char *argv[] ) {
    if (argc != 2) {
        fprintf( stderr, "use: %s <int_num>\n", argv[0] );
        return 1;
    }
    int n = atoi( argv[1] );
    int f = fib( n );

    // print the results
    printf( "Fibonacci(%d)=%d\n", n, f );
    return 0;
}
