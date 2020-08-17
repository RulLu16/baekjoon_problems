#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	vector <int> num;
	int n;
	
	while(scanf("%1d",&n)!=EOF){
		num.push_back(n);
	}
	
	sort(num.begin(), num.end());
	reverse(num.begin(), num.end());
	
	for(int i=0;i<num.size();i++){
		printf("%d",num[i]);
	}
	
	return 0;
}
