#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int x;
	int y;
}snake;
int map[101][101]={0,};
int mark[101][101]={0,};
int up[4]={-1,0,1,0};
int right[4]={0,1,0,-1};
int dir=1;
snake que[10001];
int head=0;
int tail=0;
int n;

int move(){
	int x=que[head].x;
	int y=que[head].y;
	int xt=que[tail].x;
	int yt=que[tail].y;
	
	x+=up[dir];
	y+=right[dir];
	
	//printf("%d %d\n",x,y);
	if(x<0 || x>n-1 || y<0 || y>n-1)
		return 1;
		
	if(mark[x][y]==1)
		return 1;
	
	if(map[x][y]==0){
		mark[xt][yt]=0;
		tail++;
	}
	else{
		map[x][y]=0;
	}
			
	head++;
	que[head].x=x;
	que[head].y=y;		
	mark[x][y]=1;
		
	return 0;	
}

int main(){
	int k;
	int i,j;
	int l;
	int t1,t2;
	int num[101]={0,};
	int second=0;
	int end=0;
	int temp;
	char doc[101]={0,};
	mark[0][0]=1;
	que[0].x=0;
	que[0].y=0;
	
	scanf("%d",&n);
	scanf("%d",&k);
	for(i=0;i<k;i++){
		scanf("%d %d",&t1,&t2);
		map[t1-1][t2-1]=1;
	}
	
	scanf("%d",&l);
	scanf("%d %1c",&num[0],&doc[0]);
	for(i=1;i<l;i++){
		scanf("%d %1c",&num[i],&doc[i]);
		//printf("%c",doc[i]);
	}
	//temp=num[0];
	i=0;
	j=0;
	while(1){
		if(i==num[j]){
			if(doc[j]=='L'){
				dir=(dir+3)%4;
			}
			else
				dir=(dir+1)%4;
			j++;
		}
		
		if(move()){
			break;
		}
		second++;
		i++;
	}
	
	printf("%d\n",second+1);
}
