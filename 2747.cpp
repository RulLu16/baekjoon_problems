#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> memo(46);

int fibo(int n){
	if(memo[n]!=0){
		return memo[n];
	}
	if(n==0){
		return 0;
	}
	if(n==1){
		return 1;
	}
	
	memo[n]=fibo(n-2)+fibo(n-1);
	return memo[n];
}

int main(){
	int n;
	int result=0;
	
	scanf("%d",&n);
	
	result=fibo(n);
	
	printf("%d\n",result);
}
