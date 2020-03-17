#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)    // 오름차순 비교 함수 구현
{
    int num1 = *(int *)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
    int num2 = *(int *)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

    if (num1 < num2)    // a가 b보다 작을 때는
        return -1;      // -1 반환
    
    if (num1 > num2)    // a가 b보다 클 때는
        return 1;       // 1 반환
        
    return 0;    // a와 b가 같을 때는 0 반환
}

int main(){
	int n,m,v;
	int** graph;
	int stack[1001]={0,};
	int que[1001]={0,};
	int mark[1001]={0,};
	int* size;
	int top=0;
	int start, end;
	int v1,v2;
	int i,j,k;
	
	scanf("%d %d %d",&n,&m,&v);
	
	graph=(int**)malloc(sizeof(int*)*(n+1));
	size=(int*)malloc(sizeof(int)*(n+1));
	
	for(i=0;i<=n;i++){
		size[i]=0;
		graph[i]=(int*)malloc(sizeof(int)*(m+1));
		for(j=0;j<=m;j++)
			graph[i][j]=0;
	}
	
	
	for(i=0;i<m;i++){
			scanf("%d %d",&v1,&v2);
			j=0;
			while(1){
				if(graph[v1][j]==0)
					break;
				else
					j++;
			}
			graph[v1][j]=v2;
			size[v1]++;
			//printf("%d",size[v1]);
			j=0;
			while(1){
				if(graph[v2][j]==0)
					break;
				else
					j++;
			}
			graph[v2][j]=v1;
			size[v2]++;
	}
	
	for(i=1;i<=n;i++){
		
		if(graph[i][0]==0)
			continue;
		qsort(graph[i],size[i],sizeof(int),compare);
	}
	
	/*for(i=1;i<=n;i++){
		for(j=0;j<m;j++)
			printf("%d ",graph[i][j]);
		printf("\n");
	}*/
	
	stack[1]=v;
	top=1;
	mark[v]=1;
	printf("%d ",v);
	
	while(1){
		if(top==0)
			break;
		i=stack[top];
		//printf("%d\n",i);
		j=0;
		while(1){
			if(graph[i][j]==0){
				top--;
				break;
			}
			else{
				k=graph[i][j];
				if(mark[k]==0){
					top++;
					stack[top]=k;
					mark[k]=1;
					printf("%d ",k);
					break;
				}
				else{
					j++;
				}
			}
		}
	}
	printf("\n");
	for(i=0;i<1001;i++)
		mark[i]=0;
	
	que[1]=v;
	end=2;
	start=1;
	mark[v]=1;
	printf("%d ",v);
	
	while(1){
		if(start==end)
			break;
		i=que[start];
		j=0;
		while(1){
			if(graph[i][j]==0){
				start++;
				break;
			}
			else{
				k=graph[i][j];
				if(mark[k]==0){
					mark[k]=1;
					que[end]=k;
					j++;
					end++;
					printf("%d ",k);
				}
				else
					j++;
			}
		}
		
	}
	printf("\n");
	
	
}
