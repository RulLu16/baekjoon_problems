#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int x;
	int y;
	int num;
}que;

int n,m;
int visit1[20][20];
int visit2[20][20];
char board[20][20];
que q1[400];
que q2[400];

int main(){
	int flag=0;
	int start1
	scanf("%d %d",&n,&m);
	getchar();
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%1c",&board[i][j]);
			if(board[i][j]=='o'){
				if(flag==0){
					flag=1;
					q1[0].x=i;
					q1[0].y=j;
					q1[0].num=0;
					visit1[i][j]=1;
				}
				else{
					q2[0].x=i;
					q2[0].y=j;
					q2[0].num=0;
					visit2[i][j]=1;
				}
			}
		}
		getchar();
	}
	
}
