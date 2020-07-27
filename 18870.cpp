#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int main(){
	int n;
	vector <int> x;
	vector <int> idx;
	vector <int> result;
	set <int, greater<int> > compress;
	
	scanf("%d",&n);
	result.assign(n,0);
	
	for(int i=0;i<n;i++){
		int temp;
		scanf("%d",&temp);
		x.push_back(temp);
		idx.push_back(temp);
	}
	sort(idx.begin(), idx.end());
	idx.erase(unique(idx.begin(), idx.end()), idx.end());
	
	for(int i=0;i<n;i++){
		printf("%d ",lower_bound(idx.begin(), idx.end(), x[i])-idx.begin());
	}
	printf("\n");
}
