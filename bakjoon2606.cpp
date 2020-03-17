#include <stdio.h>
#include <stdlib.h>

int main(){
	int graph[101][101]={0,};
	int n,k;
	int i,j,m;
	int stack[101];
	int top=0;
	int start,end;
	int mark[101];
	int result;
	
	scanf("%d",&n);
	scanf("%d",&k);
	
	for(i=0;i<k;i++){
		scanf("%d %d",&start,&end);
		j=0;
		while(1){
			if(graph[start][j]==0)
				break;
			else
				j++;
		}
		graph[start][j]=end;
		j=0;
		while(1){
			if(graph[end][j]==0)
				break;
			else
				j++;
		}
		graph[end][j]=start;
	}
	
	stack[1]=1;
	top++;
	result=0;
	mark[1]=1;
	
	while(1){
		if(top==0)
			break;
		i=stack[top];
		//printf("%d %d\n",i,result);
		j=0;
		while(1){
			if(graph[i][j]==0){
				top--;
				break;
			}
			else{
				k=graph[i][j];
				if(mark[k]==0){
					result++;
					top++;
					stack[top]=k;
					mark[k]=1;
					break;
				}
				else{
					j++;
				}
			}
		}
	}
	
	printf("%d\n",result);
	
	
}
