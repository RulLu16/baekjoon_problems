#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

int main(){
	int n, i, j;
	int arr[100001];
	
	stack <int> s;
	vector <char> v;
	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	for(int i=1; i<=n;i++){
		s.push(i);
		v.push_back('+');
		
		while(!s.empty() && s.top()==arr[j]){
			s.pop();
			v.push_back('-');
			j++;
		}
	}
	
	if(!s.empty()){
		printf("NO\n");
	}
	else{
		for(int i=0;i<v.size();i++){
			printf("%c\n",v[i]);
		}
	}
	
}
