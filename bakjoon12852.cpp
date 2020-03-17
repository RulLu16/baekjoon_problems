#include <stdio.h>
#include <stdlib.h>

int min(int, int);

int main(){
	int n;
	int i,j;
	int a,b,c;
	int* test;

	
	scanf("%d",&n);
	
	test=(int*)malloc(sizeof(int)*(n+1));
		
	test[0]=0;
	test[1]=0;
	if(n<2){
		printf("0\n");
		return 0;
	}
	else{
		
		for(i=2;i<=n;i++){
			test[i]=test[i-1]+1;
			
			if(i%3==0)
				test[i]=min(test[i/3]+1,test[i]);
			if(i%2==0)
				test[i]=min(test[i/2]+1,test[i]);
			
		}
		printf("%d\n",test[n]);
		i=n;
		while(1){
			if(i==1)
				break;
			
			printf("%d ",i);
			if(i%3 ==0 && test[i]==test[i/3]+1){
				i=i/3;
			}
			else if(i%2 ==0 && test[i]==test[i/2]+1){
				i=i/2;
			}
			else{
				i=i-1;
			}
			
		}
		printf("1\n");
	}
	
}

int min(int a, int b){
	if(a<b)
		return a;
	else
		return b;
}

