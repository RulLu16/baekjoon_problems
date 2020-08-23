#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	long long n;
	long long head, tail;
	long long result=2147483647;
	long long ans[2]={0,};
	vector <long long> liquid;
	
	scanf("%lld",&n);
	head=0; tail=n-1;
	
	for(long long i=0;i<n;i++){
		long long temp;
		scanf("%lld",&temp);
		
		liquid.push_back(temp);
	}
	sort(liquid.begin(), liquid.end());
	
	while(head<tail){
		long long temp=liquid[head]+liquid[tail];
			
		if(abs(result)>abs(temp)){
			result=liquid[head]+liquid[tail];
			ans[0]=liquid[head]; ans[1]=liquid[tail];
		}
			
		if(temp<0) head++;
		else if(temp>0) tail--;	
		else break;		
	}
	
	printf("%lld %lld\n",ans[0],ans[1]);
}
