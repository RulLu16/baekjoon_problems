#inclue <stdio.h>
#include <stdlib.h>

struct que{
	int x;
	int y;
	que* link;
};

void que_push(int i, int j);
void que_pop();
void BFS();

que* start;
que* end;

int main(){
	int m,n,i,j;
	int** basket;
	int temp;
	int total=0;
	int fresh=0;
	int temp_x,temp_y;
	scanf("%d %d",&m,&n);
	
	basket=(int**)malloc(sizeof(int*)*m);
	for(i=0;i<m;i++)
		basket[i]=(int*)malloc(sizeof(int)*n);
	
	start=(que*)malloc(sizeof(que));
	start->link=NULL;
	end=start;
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%1d",&temp);
			if(temp==0)
				fresh++;
			else if(temp==1)
				que_push(i,j);
			basket[i][j]=temp;
		}
	}
	
	while(1){
		if(start==NULL)
			break;
		if(end->x>0 && basket[end->x-1][end->y]==0){
			total++;
			basket[end->x][end->y]=1;
			que_push(end->x-1,end->y);
		}
		if(end->y>0 && basket[end->x][end->y-1]==0){
			total++;
			basket[end->x][end->y]=1;
			que_push(end->x,end->y-1);
		}
		if(end->x<m-1 && basket[end->x+1][end->y]==0){
			total++;
			basket[end->x][end->y]=1;
			que_push(end->x+1,end->y);
		}
		if(end->y<n-1 && basket[end->x][end->y+1]==0){
			total++;
			basket[end->x][end->y]=1;
			que_push(end->x,end->y+1);
		}
		que_pop();
	}
	
	if(total==fresh)
		printf("")
	
}

void que_push(int i, int j)
{
	que* temp=(que*)malloc(sizeof(que));
	temp->x=i;
	temp->y=j;
	temp->link=end->link;
	end->link=temp;
	end=temp;
}

void que_pop()
{
	que* temp=start;
	start=start->link;
	free(temp);
}
