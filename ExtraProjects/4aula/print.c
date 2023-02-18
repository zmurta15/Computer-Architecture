#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
	char str [60];
	char* str1 ="fim\n";
	char* c =fgets(str, 60, stdin);
	int i = strcmp(c, str1);
	while(argc<60) {
	if(i!=0) {
			printf("-> %s", str );
	}
	scanf ("-> %s", str1);
	printf("-> %s", str1);
	}
	return 0;
}