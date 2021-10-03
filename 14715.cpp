#include <stdio.h>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

int min_v = 1000001;

int main(){
	int k;
	
	cin >> k;
	
	int sum = 1;
	while(1){
		int flag = 0;
		for(int i=2;i<=sqrt(k);i++){
			if(k % i == 0) {
				sum++;
				k /= i;
				flag = 1;
				break;	
			}
		}
		
		if(flag == 0) {
			break;
		}
	}
	
	cout << ceil(log2(sum)) << "\n";
}
