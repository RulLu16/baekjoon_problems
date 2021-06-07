#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int max_count = 0;
int min_count = 100;

int count_odd(string num){
	int count = 0;
	
	for(int i=0;i<num.length();i++){
		count += (num[i]-'0')%2;
	}
	
	return count;
}

void brute(string num, int odd){
	odd += count_odd(num);
	
	if(num.length() == 1){
		if(max_count < odd) max_count = odd;
		if(min_count > odd) min_count = odd;
	}
	else if(num.length() == 2){
		int tmp = stoi(num);
		
		num = to_string(tmp/10 + tmp%10);
		brute(num, odd);
	}
	else{
		for(int i=1;i<num.length();i++){
			for(int j=i+1;j<num.length();j++){
				int first = stoi(num.substr(0, i));
				int second = stoi(num.substr(i, j-i));
				int third = stoi(num.substr(j));
				
				string newStr = to_string(first + second + third);
				brute(newStr, odd);
			}
		}
	}
}

int main(){
	string num;
	
	cin >> num;
	brute(num, 0);
	
	printf("%d %d\n", min_count, max_count);
}
