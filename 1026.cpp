#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	int n;
	int s=0;
	vector <int> a;
	vector <int> b;
	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		int temp;
		scanf("%d",&temp);
		a.push_back(temp);
	}	
	for(int i=0;i<n;i++){
		int temp;
		scanf("%d",&temp);
		b.push_back(temp);
	}	
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<int>());
	
	for(int i=0;i<n;i++){
		s+=a[i]*b[i];
	}	
	printf("%d\n",s);
}
