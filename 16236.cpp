#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct{
	int x;
	int y;
	int depth;
}sharkMove;

int map[20][20];
int visit[20][20]={0,};
queue <sharkMove> shark;
vector <sharkMove> fish;
int n;
int seconds=0;
int sharkSize=2;
int sharkEat=0;
int xMove[4]={-1,0,0,1};
int yMove[4]={0,-1,1,0};

void init(){
	while(!shark.empty()){
		shark.pop();
	}
	
	fish.clear();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			visit[i][j]=0;
		}
	}
	return;
}

bool sortRule(sharkMove A, sharkMove B){
	 if (A.depth <= B.depth)
    {
        if (A.depth == B.depth)
        {
            if (A.x <= B.x)
            {
                if (A.x == B.x)
                {
                    if (A.y < B.y)
                    {
                        return true;
                    }
                    return false;
                }
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

void bfs(){
	while(!shark.empty()){
		sharkMove pre=shark.front();
		shark.pop();
		
	//printf("%d %d\n",pre.x,pre.y);
		
	/*	if(map[pre.x][pre.y]<sharkSize && map[pre.x][pre.y]>0){
			sharkEat++;
			map[pre.x][pre.y]=0;
			seconds+=pre.depth;
			
			if(sharkEat==sharkSize){
				sharkSize++;
				sharkEat=0;
			}
			
			init();
			sharkMove start;
			start.x=pre.x; start.y=pre.y;
			start.depth=0; 
			que.push(start);
			visit[pre.x][pre.y]=1;
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					printf("%d ",map[i][j]);
				}
				printf("\n");
			}
			continue;
		} // eat fish
		*/
		for(int i=0;i<4;i++){
			int nextX=pre.x+xMove[i];
			int nextY=pre.y+yMove[i];
			
			if(nextX<0 || nextX>=n || nextY<0 || nextY>=n){
				continue;
			}
			
			if(visit[nextX][nextY]==0 && map[nextX][nextY]<=sharkSize){
				//printf("%d %d\n",nextX,nextY);
				sharkMove next;
				visit[nextX][nextY]=1;
				next.x=nextX; next.y=nextY;
				next.depth=pre.depth+1;
				shark.push(next);
				if(map[nextX][nextY]<sharkSize && map[nextX][nextY]>0){
					fish.push_back(next);
				}
			}
		}
	}
}

int main(){
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int temp;
			scanf("%d",&temp);
			
			if(temp==9){
				visit[i][j]=1;
				sharkMove start;
				start.x=i; start.y=j;
				start.depth=0; 
				shark.push(start);
				map[i][j]=0;
			}
			else
				map[i][j]=temp;
		}
	}
	
	while(1){
		bfs();
		int x, y;
		
		if(fish.size()==0){
			printf("%d\n",seconds);	
			break;
		}
		else if(fish.size()>1){
			sort(fish.begin(), fish.end(), sortRule);
		}
		x=fish[0].x; y=fish[0].y;
		sharkEat++;
		map[x][y]=0;
		seconds+=fish[0].depth;
			
		if(sharkEat==sharkSize){
			sharkSize++;
			sharkEat=0;
		}
			
		init();
		sharkMove start;
		start.x=x; start.y=y;
		start.depth=0; 
		shark.push(start);
		visit[x][y]=1;
	}	
}  
