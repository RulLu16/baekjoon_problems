#include <stdio.h>

int main(){
	int r,c,a,b;
	int flag=0;
	int change;
	
	scanf("%d %d",&r,&c);
	scanf("%d %d",&a,&b);
	change=a;
	
	for(int i=0;i<r;i++){
		for(int j=0;j<a;j++){
			for(int k=0;k<c;k++){
				if((i+k)%2==0){
					for(int m=0;m<b;m++)
						printf("X");
				}
				else{
					for(int m=0;m<b;m++)
						printf(".");
				}
			}
			printf("\n");
		}
	}
}
