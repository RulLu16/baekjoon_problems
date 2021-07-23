#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<int> chae;

long isDivide(string p, long div){
	string co = "0";
	long siz = p.size();
	long r;
	
	for(long i=0;i<siz;i++){
		char c = p[i];
		co.push_back(c);
		r = stoi(co)%div;
		
		co = to_string(r);
	}
	
	return stoi(co);
}

void makeChae(long target){
	for(int i=2;i<target;i++){
		if(chae[i] == 0){
			for(int j=i*2;j<target;j+=i){
				chae[j] = 1;
			}
		}
	}
}

int main(){
	string p;
	long k;
	
	cin >> p;
	scanf("%ld", &k);
	
	chae.assign(k, 0);
	makeChae(k);
		
	for(long i = 2; i<k;i++){
		if(chae[i] == 0){
			
			if(isDivide(p, i) == 0){
				printf("BAD %ld\n", i);
				return 0;
			}
		}
	}	
	
	printf("GOOD\n");
}
