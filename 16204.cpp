#include <stdio.h>

int minVal(int a, int b){
	if(a<b) return a;
	else return b;
}

int main(){
	int n,m,k;
	
	scanf("%d %d %d",&n,&m,&k);
	
	printf("%d\n",minVal(m,k)+minVal(n-m,n-k));
}
