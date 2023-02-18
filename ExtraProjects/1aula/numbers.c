#include <stdio.h>
int main () {
	int result;
	for (int i=0; i<11; i++) {
		if(i==0) {
			result=1;
			printf("%d\n", result);
		}
		else {
			result=2*result;
			printf("%d\n", result);
		}
	}
	return 0;	
}