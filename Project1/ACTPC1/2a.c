#include <stdio.h>

float mult2 (float val) {
	float f = val;
	int num = 1;
	num = num<<23;
	int i = *(int*)&f;
	int sum = i + num;
	float g = *(float*)&sum;

	
	
	return g;	
}
