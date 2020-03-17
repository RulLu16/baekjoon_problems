#include <stdio.h>
#include <stdlib.h>

int dfs(int graph[][101], int i, int j){
	int stack[101]={0,};
	int mark[101]={0,};
	int top=1;
	int find=0;
	int temp;
	int k;
	
	if(graph[i][0]==j)
		return 1;
	
	stack[top]=i;
	mark[i]=1;
	
	while(1){
		if(top==0)
			return 0;
		
		temp=stack[top];
		k=0;
		while(1){
			if(graph[temp][k]==-1){
				top--;
				break;
			}
			else{
				if(graph[temp][k]==j)
					return 1;
				
				if(mark[graph[temp][k]]==0){
					top++;
					stack[top]=graph[temp][k];
					mark[graph[temp][k]]=1;
					break;
				}
				else
					k++;
			}
		}
		
	}	
	
}

int main(){
	int n;
	int graph[101][101];
	//int stack[101]={0,};
	//int mark[101]={0,};
	//int top=0;
	//int find=0;
	int temp,k;
	int i,j;
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			graph[i][j]=-1;
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&temp);
			if(temp==1){
				k=0;
				while(1){
					if(graph[i][k]==-1)
						break;
					else
						k++;
				}
				graph[i][k]=j;
			}
		}
	}	
	
	/*for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",graph[i][j]);
		}
		printf("\n");
	}*/
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			temp=dfs(graph,i,j);
			printf("%d ",temp);
		}
		printf("\n");
	}
}
