#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int r,c,t;
int pixel[40][40];

int filter(int x, int y){
	vector <int> middle;
	
	for(int i=x;i<x+3;i++){
		for(int j=y;j<y+3;j++){
			middle.push_back(pixel[i][j]);
		}
	}
	sort(middle.begin(), middle.end());

	return middle[4];
}

int solve(){
	int result=0;
	
	for(int i=0;i<r-2;i++){
		for(int j=0;j<c-2;j++){
			if(filter(i,j)>=t) result++;
		}
	}
	
	return result;
}

int main(){
	scanf("%d %d",&r,&c);
	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			scanf("%d",&pixel[i][j]);
		}
	}
	scanf("%d",&t);
	
	printf("%d\n",solve());
		
}
