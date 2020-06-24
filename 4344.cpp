#include <stdio.h>

int main(){
	int c,n;
	int stu[1000];
	int sum=0;
	float avg;
	int over=0;
	
	scanf("%d",&c);
	
	for(int i=0;i<c;i++){
		sum=0;
		over=0;
		
		scanf("%d",&n);
		
		for(int j=0;j<n;j++){
			scanf("%d",&stu[j]);
			sum+=stu[j];
		}
		
		avg=(float)sum/n;
		//printf("%f",avg);
		for(int j=0;j<n;j++){
			if(stu[j]>avg){
				over++;
			}
		}
		printf("%.3f%%\n",(float)over/n*100);
	}
}
