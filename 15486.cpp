#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int max_n(int a, int b){
	if(a<b)	return b;
	else return a;
}

int main(){
	int n;
	vector <int> time;
	vector <int> price;
	vector <int> dp;
	int temp;
	
	scanf("%d",&n);

	time.push_back(0);
	price.push_back(0);
	for(int i=1;i<=n;i++){
		int getTime, getPrice;
		scanf("%d %d",&getTime,&getPrice);
		
		time.push_back(getTime);
		price.push_back(getPrice);
	}
	
	dp.assign(n+2,0);
	
	for(int i=n;i>0;i--){
		temp=i+time[i];
		if(temp>n+1){
			dp[i]=dp[i+1];
		}
		else{
			dp[i]=max_n(dp[i+1],dp[temp]+price[i]);
		}
	}
	
	printf("%d\n",dp[1]);
}
