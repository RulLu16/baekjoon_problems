#include <stdio.h>
#include <stdlib.h>

struct vacumm{
	int r;
	int d;
	int dir
	vacumm* next;
};

void push(int, int, int);
void pop();
int isClean(int**, vacumm*);
int isBack(int**, vacumm*);

vacumm* top;

int main(){
	int n,m;
	int i,j;
	int command;
	int result=1;
	int** floor;
	int r,d,dir

	top=(vacumm*)malloc(sizeof(vacumm));
	
	scanf("%d %d",&n,&m);
	floor=(int**)malloc(sizeof(int*)*n);
	for(i=0;i<n;i++)
		floor[i]=(int*)malloc(sizeof(int)*m);
		
	scanf("%d %d %d",&r,&d,&dir);
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%1d",&floor[i][j]);
		}
	}
	top->r=r;
	top->d=d;
	top->dir=dir;
	top->next=NULL;
	floor[r][d]=2; //2=clean
	
	while(1){
		command=isClean(floor,top);
		if(command<0){
			pop();
			if(isBack(floor,top)==0)
				break;
			
		}
		else{
			floor[top->r][top->d]=2;
			result++;
			continue;
			
		}	
	}
	printf("%d\n",result);
	
}

int isClean(int** floor, vacumm* v){
	int i;
	int find=-1;
	
	for(i=0;i<4;i++){
		switch(v->dir){
			case 0:
				if(floor[v->r][v->d-1]==0){
					push(v->r,v->d-1,3);
					find=3;
				}
				break;
			case 1:
				if(floor[v->r-1][v->d]==0){
					find=0;
					push(v->r-1,v->d,0);
				}
				break;
			case 2:
				if(floor[v->r][v->d+1]==0){
					find=1;
					push(v->r,v->d+1,1);
				}
				break;
			case 3:
				if(floor[v->r+1][v->d]==0){
					find=2;
					push(v->r+1,v->d,2);
				}
				break;
		}
		if(find>0)
			return find;
	}
	return -1;
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
