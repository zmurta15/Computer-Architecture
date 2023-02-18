#include <stdio.h>

float mult2 (float val) {
	int mantissa;
	mantissa = val;
	float exponent;
	exponent = val - mantissa;
	exponent = exponent/0.1;
	int i;
	i = (int)exponent;
	i = i<<1;
	float z = (float)i;
	
	
	
	
	return z;	
}


int main() {
	float f;
	scanf("%f", &f);
	float r =mult2(f);
	printf ("%f\n", r);
	return 0;
}