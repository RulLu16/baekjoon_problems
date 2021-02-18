#include <stdio.h>
#include <vector>

using namespace std;

int n;
int w[11]={0,};
int x[9]={0,};
int result = 0;

int getEnergy(){
	vector <int> energy;
	int sum = 0;

	for(int i=0;i<n;i++){
		energy.push_back(w[i]);
	}
	
	for(int i=0;i<n-2;i++){
		sum += energy[x[i]-1]*energy[x[i]+1];
		energy.erase(energy.begin() + x[i]);
	}
	
	return sum;
}

void dfs(int depth, int reduce){
	if(depth == n-2){
		int sum = getEnergy();
		
		if(sum > result) result = sum;
		return;
	}
	
	for(int i=1;i<=reduce-2;i++){
		x[depth] = i;
		dfs(depth+1, reduce-1);
	}
}

int main(){
	scanf("%d", &n);
	
	for(int i=0;i<n;i++){
		scanf("%d", &w[i]);
	}
	
	dfs(0, n);
	
	printf("%d\n", result);
}
