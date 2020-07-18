#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	int n;
	vector <int> tree;
	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		int temp;
		
		scanf("%d",&temp);
		tree.push_back(temp);
	}	
	sort(tree.begin(), tree.end(),greater<int>());
	
	for(int i=0;i<n;i++){
		tree[i]-=(n-1-i);
	}
	sort(tree.begin(), tree.end(),greater<int>());
	
	printf("%d\n",n+1+tree[0]);
}
