#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int n, re;
int candidate[101] = {0,};
int last[101] = {0,};

int replace(){
	vector<int> min_group;
	int min_v = 1001;
	
	for(int i=1;i<101;i++){
		if(candidate[i] != 0 && candidate[i] < min_v){
			min_v = candidate[i];
		}
	} // min 찾기
		
	for(int i=1;i<101;i++){
		if(candidate[i] == min_v){
			min_group.push_back(i);
		}
	} 
	
	if(min_group.size() == 1)
		return min_group[0];
	else{
		int old = 1001;
		
		for(int i=0;i<min_group.size();i++){
			if(last[min_group[i]] < old){
				old = last[min_group[i]];
			}
		} // old 찾기
	
		for(int i=0;i<min_group.size();i++){
			if(last[min_group[i]] == old){
				return min_group[i];
			}
		} 
	}
}

int main(){
	int cur = 0;
	
	scanf("%d", &n);
	scanf("%d", &re);
	
	for(int i=0;i<re;i++){
		int like;
		scanf("%d", &like);
		
		if(candidate[like] == 0){
			last[like] = i;
			
			if(cur<n){
				cur++;
			}
			else{
				int down = replace();
				candidate[down] = 0;
				last[down] = 0;
			}
		} // 처음 개시

		candidate[like]++;		
	}
	
	for(int i=0;i<101;i++){
		if(candidate[i] > 0)
			printf("%d ", i);
	}
	printf("\n");
}
