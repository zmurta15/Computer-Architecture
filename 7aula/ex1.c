/************
 * AC - ficha 7 2017/18 MIEI
 * DI/FCT/UNL
 ***********/
#include <stdio.h>
#include <stdlib.h>

/*int 
calc2(int a) {
    return a + 1;
}*/

extern int calc(int a);

int 
main(int argc, char *argv[]) {
    int x, y;
    if (argc != 2) {
    	fprintf(stderr, "use: %s <int num>\n", argv[0]);
    	return 1;
    }
    x = atoi(argv[1]);
    y = calc(x);
    printf("y=%d\n", y);
    return 0;
}
