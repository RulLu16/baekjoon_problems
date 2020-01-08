#include <stdio.h>
#include <stdlib.h>

int min(int, int, int);

int main(){
	int n;
	int** cal;
	int i,j;
	int a,b,c;
	int flag=0;
	
	scanf("%d",&n);
	if(n==1){
		printf("0\n");
		return 0;
	}
	
	cal=(int**)malloc(sizeof(int*)*(n+1));
	for(i=0;i<n+1;i++){
		cal[i]=(int*)malloc(sizeof(int)*3);
	}
	for(i=0;i<3;i++)
		cal[0][i]=n;

	for(i=1;i<n+1;i++){
		for(j=0;j<3;j++){
			a=cal[i-1][0];
			b=cal[i-1][1];
			c=cal[i-1][2];
			switch(j){
				case 0:
					if(a%3==0)
						a=a/3;
					if(b%3==0)
						b=b/3;
					if(c%3==0)
						c=c/3;
					cal[i][j]=min(a,b,c);
					printf("%d ",cal[i][j]);
					break;
				case 1:
					if(a%2==0)
						a=a/2;
					if(b%2==0)
						b=b/2;
					if(c%2==0)
						c=c/2;
					cal[i][j]=min(a,b,c);
					printf("%d ",cal[i][j]);
					break;
				case 2:
					cal[i][j]=min(a-1,b-1,c-1);
					printf("%d ",cal[i][j]);
					break;
			}
			if(cal[i][j]==1){
				flag=1;
				break;
			}
		}
		printf("\n");
		if(flag==1)
			break;
	}
	
	printf("%d\n",i);
}

int min(int a, int b, int c){
	if(a<b){
		if(a<c)
			return a;
		else
			return c;
	}
	else{
		if(b<c)
			return b;
		else
			return c;
	}
}
