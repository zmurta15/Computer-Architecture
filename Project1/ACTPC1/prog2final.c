#include <stdio.h>

float mult2 (float val) {
	float f = val;
	f = f*10;
	int i = (int)f<<1;
	i = i/10;
	float g=(float)i;
	
	
	return g;	
}
