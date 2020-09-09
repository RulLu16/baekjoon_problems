#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int map[51][51]={0,};
int n,m;

int repaint(int x, int y){
	int Bnum=0;
	int Wnum=0;
	int changeB=0;
	int changeW=1;
	
	for(int i=x;i<x+8;i++){
		for(int j=y;j<y+8;j++){
			if(changeB!=map[i][j]) Bnum++;
			if(changeW!=map[i][j]) Wnum++;
			changeB=(changeB+1)%2;	
			changeW=(changeW+1)%2;		
		}
		changeB=(changeB+1)%2;	
		changeW=(changeW+1)%2;	
	}
	
	if(Bnum>Wnum) return Wnum;
	else return Bnum;
}

int main(){
	int ans=65;
	scanf("%d %d",&n,&m);
	getchar();
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			char temp;
			scanf("%1c",&temp);
			
			if(temp=='W') map[i][j]=1;
		}
		getchar();
	}
	
	for(int i=0;i<n-7;i++){
		for(int j=0;j<m-7;j++){
			int paintNum=repaint(i,j);
			
			if(paintNum<ans) ans=paintNum;
			
			if(ans<1){
				printf("0\n");
				return 0;
			}
		}
	}
	
	printf("%d\n",ans);
}
