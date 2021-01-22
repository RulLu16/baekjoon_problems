#include <stdio.h>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

int prime(long long temp){
	if(temp == 2) return 1;
	if(temp%2==0 || temp==1) return 0;
	
	int square = sqrt(temp);
	
	for(int i=3;i<=square;i+=2){
		if(temp%i == 0) return 0;
	}
	
	return 1;
}

int pelin(long long temp){
	string num = to_string(temp);
	
	for(int i=0;i<int(num.length()/2);i++){
		if(num[i] != num[num.length()-1-i])
			return 0;
	}
	
	return 1;
}

int main(){
	long long n;
	
	scanf("%lld", &n);
	
	while(1){
		if(prime(n) && pelin(n)){
			printf("%lld\n", n);
			break;
		}
		n++;
	}
}
