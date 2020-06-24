#include <stdio.h>

int main(){
	int n;
	float arr[1000];
	float max=0;
	float sum=0;
	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		scanf("%f",&arr[i]);
		if(arr[i]>max){
			max=arr[i];
		}
	}
	
	for(int i=0;i<n;i++){
		sum+=arr[i]/max*100;
	}
	
	printf("%f\n",sum/n);
}
