#include <stdio.h>
#include <vector>

using namespace std;

int n; int result = 200*15;
int map[10][10] = {0,};
int visit[10][10] = {0,};
vector <pair<int, int> > seed;

int check(){
	int sum = 0;
	
	for(int i=0;i<3;i++){
		int x = seed[i].first;
		int y = seed[i].second;
		
		int temp = map[x][y] + map[x-1][y] + map[x][y+1];
		temp += map[x][y-1] + map[x+1][y];
		
		sum += temp;
	}
	
	return sum;
}

void brute(int depth){
	if(depth == 3){
		int price = check();
		
		if(result > price){
			result = price;
		}
		
		return;
	}
	
	for(int i=1;i<n-1;i++){
		for(int j=1;j<n-1;j++){
			if(!visit[i][j] && !visit[i-1][j] && 
			!visit[i][j-1] && !visit[i+1][j] && !visit[i][j+1]){
				
				visit[i][j] = visit[i-1][j] = visit[i][j+1] = 1;
				visit[i][j-1] = visit[i+1][j] = 1;
				
				seed[depth].first = i;
				seed[depth].second = j;
				
				brute(depth+1);
				visit[i][j] = visit[i-1][j] = visit[i][j+1] = 0;
				visit[i][j-1] = visit[i+1][j] = 0;
			}
		}
	}
}

int main(){
	scanf("%d", &n);
	seed.assign(3, make_pair(0, 0));
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d", &map[i][j]);
		}
	}
	
	brute(0);
	printf("%d\n", result);
}
