#include <stdio.h>
#include <vector>

using namespace std;

int main(){
	int n;
	long long ans=0;
	long long plus=0;
	vector <int> num;
	
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int temp;
		
		scanf("%d",&temp);
		num.push_back(temp);
		plus+=temp;
	}
	
	for(int i=0;i<n-1;i++){
		plus-=num[i];
		ans=ans+(plus*num[i]);
	}
	
	printf("%lld\n",ans);
}
