#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int x;
	int y;
}coor;

int result;
int n, m;

void copy(int** lab, int** temp){
	int i,j;

	for(i=0;i<n;i++){
		for(j=0;j<m;j++)
			temp[i][j]=lab[i][j];
	}
	
	return;
}

void dfs(int** temp){
	coor* stack;
	int x,y;
	int top=0;
	int i,j;
	int emp=0;
	int** after;
	
	after=(int**)malloc(sizeof(int*)*n);
	for(i=0;i<n;i++)
		after[i]=(int*)malloc(sizeof(int)*m);
	stack=(coor*)malloc(sizeof(coor)*(n*m+1));
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++)
			after[i][j]=temp[i][j];
	}
	
	//stack=(coor*)malloc(sizeof(coor)*(n*m));
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(after[i][j]==2){
				top++;
				stack[top].x=i;
				stack[top].y=j;	
			}
		}
	}
	
	while(1){
		if(top==0)
			break;
		
		x=stack[top].x;
		y=stack[top].y;
			
		if(x>0 && after[x-1][y]==0){
			top++;
			after[x-1][y]=2;
			stack[top].x=x-1;
			stack[top].y=y;
		} //up
		else if(x<n-1 && after[x+1][y]==0){
			top++;
			after[x+1][y]=2;
			stack[top].x=x+1;
			stack[top].y=y;
		} //down
		else if(y>0 && after[x][y-1]==0){
			top++;
			after[x][y-1]=2;
			stack[top].x=x;
			stack[top].y=y-1;
			
		} //left
		else if(y<m-1 && after[x][y+1]==0){
			top++;
			after[x][y+1]=2;
			stack[top].x=x;
			stack[top].y=y+1;
			
		} //right
		else
			top--;
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(after[i][j]==0)
				emp++;
		}
	}
	
	if(emp>result)
		result=emp;
		
	free(stack);
	return;
}

void makewall(int num, int** temp){
	int i,j;
	
	if(num==3){
		dfs(temp);
		return;
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(temp[i][j]==0){
				temp[i][j]=1;
				makewall(num+1,temp);
				temp[i][j]=0;
			}
		}
	}
}

int main(){
	int** lab;
	int** temp;
	int i,j,x,y;
	
	result=0;
	scanf("%d %d",&n,&m);
	lab=(int**)malloc(sizeof(int*)*n);
	temp=(int**)malloc(sizeof(int*)*n);
	
	for(i=0;i<n;i++){
		lab[i]=(int*)malloc(sizeof(int)*m);
		temp[i]=(int*)malloc(sizeof(int)*m);
	}

	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&lab[i][j]);
			temp[i][j]=0;
		}
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(lab[i][j]==0){
				copy(lab, temp);	

				temp[i][j]=1;
				makewall(1,temp);
				temp[i][j]=0;
			}
		}
	}
	
	
	printf("%d\n",result);
}
