
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char *maiusculas( char *str ) {
   int i=0;
   while(str[i] != '\0') {
	str[i] = toupper(str[i]);
   i=i+1;
   } 
   return str;
} 

int main (int argc, char *argv[]) {
    int d;	// for storing an integer number
    float f;	// for storing a floating point number
    int i;

    for (i=1; i < argc; i++) {
        if (isdigit(argv[i][0])) { // if first char is a digit
	    // then it's a number
            f = atof (argv[i]);
            d = (int)f;
            if (f - d == 0) // it is an integer
                printf("int: %d\n", d );	
            else            // it is a float
                printf("float: %f\n", f );
        }
        else	// it is a string (non-number)
            printf("str: %s\n", maiusculas(argv[i]) );
    }
    return 0;
}

