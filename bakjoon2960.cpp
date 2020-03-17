#include <stdio.h>
#include <stdlib.h>

int main(){
	int n,k;
	int num[1001]={0,};
	int i,j;
	int temp;
	int result=0;
	int count=0;
	
	scanf("%d %d",&n,&k);
	num[0]=0;
	num[1]=0;
	
	j=2;
	temp=0;
	
	while(1){
		for(i=2;i<=n;i++){
			if(num[i]==0)
				break;
		}
		if(i==1000)
			break;
		for(j=1;j*i<=n;j++){
			if(num[j*i]==0){
				num[i*j]=1;
				count++;
			}
			if(count==k){
				printf("%d\n",i*j);
				return 0;
			}
		}
	}
}
