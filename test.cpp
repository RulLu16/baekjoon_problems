#include <stdio.h>

int c;

int pow(int a, int b){
	if(b==1){
		return a;
	}
	
	if(b%2==0){
		return pow(a,b/2)*pow(a,b/2);
	}
	else{
		return a*pow(a,(b-1)/2) * pow(a,(b-1)/2);
	}
}

int main(){
	int a, b;
	
	scanf("%d %d",&a,&b);
	
	printf("%d\n",pow(a,b));
}
