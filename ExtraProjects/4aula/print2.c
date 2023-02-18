#include <stdio.h>
#include <string.h>

int main (int argc, char *arvg[]) {
	char vec[60];
	char* s2 ="fim!\n";
	while (argc<60) {
		char* s1 = fgets(vec, 60, stdin);
		int igual = strcmp(s1, s2);
		if(igual !=0) {
			printf("->%s", s1);
			}
		else {
			printf ("->%s", s2);
			break;
			}
	}	
	return 0;
}