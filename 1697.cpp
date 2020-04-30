#include <stdio.h>
#include <stdlib.h>

typedef struct Que{
	int x;
	int sec;
}que;

que q[200000];
int visit[100001]={0,};

int main(){
	int k, n;
	int temp;
	int i=0;
	int start=0;
	int end=1;
	//que* q=(que*)malloc(sizeof(que)*200001);
	
	scanf("%d %d",&n,&k);
	
	if(n==k){
		printf("0\n");
		return 0;
	}
	
	q[0].x=n;
	q[0].sec=0;
	visit[n]=1;
	
	while(1){
		temp=q[start].x;
		
		if(temp==k){
			printf("%d\n",q[start].sec);
			return 0;
		}
		
		if(temp-1>=0 && visit[temp-1]==0){
			q[end].x=temp-1;
			q[end].sec=q[start].sec+1;
			visit[temp-1]=1;
			end++;
		}	
		
		if(temp+1<=100000 && visit[temp+1]==0){
			q[end].x=q[start].x+1;
			q[end].sec=q[start].sec+1;
			visit[temp+1]=1;
			end++;
		}	
		
		if(temp*2<=100000 && visit[temp*2]==0){
			q[end].x=q[start].x*2;
			q[end].sec=q[start].sec+1;
			visit[temp*2]=1;
			end++;
		}	
		start++;
	}
}
