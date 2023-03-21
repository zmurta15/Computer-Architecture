#include<stdio.h>

void main() {

	int mantissa;
	float exponent,num;
	printf("\nEnter any floating point number\n);
	scanf("%f",&num);
	mantissa = num;
	exponent = num - mantissa;
	printf(" The mantissa part of the entered number is %d\n",mantissa);
	printf(" The exponent part of the entered number is %f\n",exponent);
 
}