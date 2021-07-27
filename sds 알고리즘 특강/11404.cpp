#include <stdio.h>
#include <vector>

using namespace std;

int MAX = 10000001; // 최대 INF값 잘 세팅하기 

int n;
vector<vector<int> > dist;

int main(){
	int m;
	
	scanf("%d", &n);
	scanf("%d", &m);
	
	dist.assign(n+1, vector<int>(n+1, MAX));
	
	for(int i=0;i<m;i++){
		int a, b, c;
		
		scanf("%d %d %d", &a, &b, &c);
		
		if(c < dist[a][b])
			dist[a][b] = c;
	}
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	} // 플로이드 와샬 알고리즘.
	// 그냥 3중 for문 돌리면서 전체 비용을 계산 
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i == j) printf("0 ");
			else if(dist[i][j] == MAX) printf("0 ");
			else printf("%d ", dist[i][j]);
		}
		printf("\n");
	}
}
