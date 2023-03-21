#include <stdio.h>
#include <string.h>

//meter um counter como parametro
int addIntChar (char n1, char n2, int lastcarry, char* res) {

	int x = n1 - '0';
	
	int y = n2 - '0';
	
	int lc = lastcarry;
	
	int sum = x+y+lc;
	
	//res[0] = sum % 10 + '0';
	
	lc = sum/10;
	
	return lc; 

}
void addIntStrings(char *n1, char *n2, char *res) {
	int i = strlen(n1)-1;
	int j = strlen(n2)-1;
	int counter=0;
	int carry = 0;
	char tmp[1000];
	
	while (i>=0 ||j>=0) {
		int x = n1[i] - '0';
		int y = n2[j] - '0';	
		int result = x + y + carry;
		carry = addIntChar(n1[i], n2[j], carry, tmp);
		
		if(result >= 10){
			tmp[counter] = result % 10 + '0';
		}else{
			tmp[counter] = result + '0';
		}
		counter++;
		i--;
		j--;
	}
	if(carry !=0){
		tmp[counter] = 1 +'0';
		counter++;
	}
	
	for (int i = 0; i < counter; i++){
		res[i] = tmp[counter-i-1];
	}
	
}	

int main() {
	char a[100]; char b[100];
	char res[100];
	scanf("%s", a); getchar();
	scanf("%s", b); getchar();
	addIntStrings( a, b, res );
	printf("\n%s\n", res);
	return 0;
}	