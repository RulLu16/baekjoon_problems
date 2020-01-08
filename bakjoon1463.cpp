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
		/*test[1]=isdivide(n);
		test[2]=min(n,isdivide(test[1]),isdivide(n-1));
		test[3]=min(isdivide(test[0]-2),isdivide(test[2]),isdivide(test[1]-1));
		for(i=1;i<4;i++){
			printf("%d ",test[i]);
			if(test[i]==1){
				printf("%d\n",i);
				return 0;
			}
		}
		
		for(i=4;i<n+1;i++){
			test[i]=min(isdivide(test[i-3]-2),isdivide(test[i-2]-1),isdivide(test[i-1]));
			printf("%d ",test[i]);
			if(test[i]==1)
				break;
		}*/
		for(i=2;i<=n;i++){
			test[i]=test[i-1]+1;
			
			if(i%3==0)
				test[i]=min(test[i/3]+1,test[i]);
			if(i%2==0)
				test[i]=min(test[i/2]+1,test[i]);
			
		}
		printf("%d\n",test[n]);
	}
	
}

int min(int a, int b){
	if(a<b)
		return a;
	else
		return b;
}

