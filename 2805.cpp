#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long n,m;
vector <long long> v;

int main(){
	long long temp;
	long long h=0;
	long long max_val=0;
	long long min_val=0;
	long long sum;
	long long result=0;
	
	scanf("%lld %lld",&n,&m);
	
	for(int i=0;i<n;i++){
		scanf("%lld",&temp);
		v.push_back(temp);
		if(max_val<temp){
			max_val=temp;
		}	
	}
	
	while(min_val<=max_val){
		sum=0;
		h=(max_val+min_val)/2;
		for(int i=0;i<n;i++){
			if(h<v[i]){
				sum+=v[i]-h;
			}
		}
		
		if(sum<m){
			max_val=h-1;
		}
		else{
			if(result<h){
				result=h;
			}
			min_val=h+1;
		}
	}
	
	printf("%lld\n",result);
}

