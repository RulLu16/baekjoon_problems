#include <stdio.h>
#include <stdlib.h>

int main(){
	int a, b;
	int three, four, five;
	int result;
	
	scanf("%d",&a);
	scanf("%d",&b);
	
	three=a*(b%10);
	four=a*(b/10%10);
	five=a*(b/100);
	
	printf("%d\n%d\n%d\n",three, four, five);
	result=three+four*10+five*100;
	printf("%d\n",result);
}
