#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n, first, second;
	vector <pair<int, int> > cor;
	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		scanf("%d %d",&first, &second);
		
		cor.push_back(make_pair(first, second));
	}
	
	sort(cor.begin(), cor.end());
	
	for(int i=0;i<n;i++){
		printf("%d %d\n",cor[i].first, cor[i].second);
	}
	
	return 0;
}
