#include <stdio.h>

int addIntChar (char n1, char n2, int lastcarry, char* res) {

	int x = n1 - '0';
	
	int y = n2 - '0';
	
	int lc = lastcarry;
	
	int sum = x+y+lc;
	
	res[0] = sum % 10 + '0';
	
	lc = sum/10;
	
	return lc; 

}
