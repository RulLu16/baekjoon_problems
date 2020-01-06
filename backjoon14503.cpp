#include <stdio.h>
#include <stdlib.h>

struct vacumm{
	int r;
	int d;
	int dir;
};
int isClean(int**, vacumm*);
int isBack(int**, vacumm*);

int main(){
	int n,m;
	int i,j;
	int command;
	int result=1;
	int** floor;
	vacumm v;
	
	scanf("%d %d",&n,&m);
	floor=(int**)malloc(sizeof(int*)*n);
	for(i=0;i<n;i++)
		floor[i]=(int*)malloc(sizeof(int)*m);
		
	scanf("%d %d %d",&v.r,&v.d,&v.dir);
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%1d",&floor[i][j]);
		}
	}
	
	floor[v.r][v.d]=2;
	
	while(1){
		command=isClean(floor,&v);
		if(command==0){
			floor[v.r][v.d]=2;
			result++;
			continue;
		}
		else{
			if(isBack(floor,&v)==1)
				continue;
			else
				break;
		}	
	}
	printf("%d\n",result);
	/*for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%d ",floor[i][j]);
		}
		printf("\n");
	}*/
}

int isClean(int** floor, vacumm* v){
	int i;
	int find=0;
	for(i=0;i<4;i++){
		switch(v->dir){
			case 0:
				if(floor[v->r][v->d-1]==0){
					find=1;
					v->d--;
				}
				v->dir=3;
				break;
			case 1:
				if(floor[v->r-1][v->d]==0){
					find=1;
					v->r--;
				}
				v->dir=0;
				break;
			case 2:
				if(floor[v->r][v->d+1]==0){
					find=1;
					v->d++;
				}
				v->dir=1;
				break;
			case 3:
				if(floor[v->r+1][v->d]==0){
					find=1;
					v->r++;
				}
				v->dir=2;
				break;
		}
		if(find==1)
			return 0;
	}
	return 1;
}

int isBack(int** floor, vacumm* v){
	int canBack=0;
	
	switch(v->dir){
		case 0:
			if(floor[v->r+1][v->d]==1)
				return 0;
			else{
				v->r++;
				return 1;
			}
			break;
		case 1:
			if(floor[v->r][v->d-1]==1)
				return 0;
			else{
				v->d--;
				return 1;
			}
			break;
		case 2:
			if(floor[v->r-1][v->d]==1)
				return 0;
			else{
				v->r--;
				return 1;
			}
			break;
		case 3:
			if(floor[v->r][v->d+1]==1)
				return 0;
			else{
				v->d++;
				return 1;
			}
			break;
	}
}
