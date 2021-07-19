#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int n, k;
int alpha[26] = {0,}; // 3 == antic, 2 == 뽑은 알파벳, 1 == 문자열에 포함된 알파벳, 0 == 포함되지 않아 뽑을 필요 없는 알파벳 
vector<string> word;
int max_v = 0;

int check(){
	int sum = 0;
	
	for(int i=0;i<n;i++){
		int lg = 0;
		for(int j=4;j<word[i].length()-4;j++){
			if(alpha[word[i][j] - 'a'] < 2)
				break;
			lg++;
		}
		if(lg + 8 == word[i].length()) sum++;
	}
	
	return sum;
}

void brute(int depth, int before){
	if(depth == k){
		int tmp = check();
		
		if(tmp > max_v) max_v = tmp;
		return;
	}
	
	for(int i=1;i<26;i++){
		if(alpha[i] == 1 && i > before){
			alpha[i] = 2;
			brute(depth+1, i);
			alpha[i] = 1;
		}
	}
}

int main(){
	int max_lg = 0;
	scanf("%d %d", &n, &k);
	
	alpha[0] = 3; alpha[2] = 3;
	alpha[13] = 3; alpha[8] = 3; alpha[19] = 3; 
		
	for(int i=0;i<n;i++){
		string tmp;
		cin >> tmp;
		
		word.push_back(tmp);
		for(int j=4;j<tmp.length()-4;j++){
			if(alpha[tmp[j] - 'a'] == 0){
				max_lg++;
				alpha[tmp[j] - 'a'] = 1;
			}
		}
	}
	
	if(k < 5){
		printf("0\n");
		return 0;
	}
	
	k -= 5;
	if(max_lg <= k){
		printf("%d\n", n);
		return 0;
	}
	
	brute(0, 0);
	
	printf("%d\n", max_v);
}
