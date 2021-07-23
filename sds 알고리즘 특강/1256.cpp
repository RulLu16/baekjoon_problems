#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

long long dp[202][202] = {0,};
string result = "";

long long min_v(long long a, long long b){
	if(a<b) return a;
	return b;
}

long long getDp(long a, long z){
	if(a == z || z == 0){
		return 1;
	}
	else if(dp[a][z] != 0)
		return dp[a][z];
	else{
		dp[a][z] = min_v(1000000000, getDp(a-1, z) + getDp(a-1, z-1));
		return dp[a][z];
	}	
}

void getStr(long a, long z, long target){
	
	if(a+z == 0) return;
	else if(a == 0){
		result.push_back('z');
		getStr(a, z-1, target);
	}
	else if(z == 0){
		result.push_back('a');
		getStr(a-1, z, target);
	}else{
		long long left = getDp(a + z -1, z);
		
		if(target > left){
		// go to right
			result.push_back('z');
			getStr(a, z-1, target - left);
		}
		else{
			// go to left
			result.push_back('a');
			getStr(a-1, z, target);
		}
	}

}

int main(){
	long n,m,k;
	
	scanf("%ld %ld %ld", &n, &m, &k);
	long long total = getDp(n +m, m);
	
	if(total < k){
		printf("-1\n");
		return 0;
	}
	
	getStr(n, m, k);
	cout << result << "\n";
	
}
