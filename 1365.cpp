#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n;
	vector <int> a;
	vector <int> dp;
	int point;
	int temp;
	int i,j;
	
	scanf("%d",&n);
	a.assign(n,0);
	
	if(n<2){
		printf("0\n");
		return 0; //if there is too little num n
	}
	else{
		for(i=0;i<n;i++)
			scanf("%d",&a[i]); //scan array A
	
		dp.push_back(a[0]);
		for(i=1;i<n;i++){
			if(dp.back()<a[i]){
				dp.push_back(a[i]);
			}
			else{
				temp=lower_bound(dp.begin(), dp.end(), a[i])-dp.begin();
				dp[temp]=a[i];	
			}
		}
		
		printf("%d\n",n-dp.size());
	}
}
