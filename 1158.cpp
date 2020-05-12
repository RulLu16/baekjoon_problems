#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n, k;
	int rolling=0;
	vector <int> visit(5001, 0);
	
	scanf("%d %d",&n,&k);
	printf("<");
	
	for(int i=1;i<n;i++){
		for(int j=1;j<=k;j++){
			if(rolling==n){
				rolling=rolling%n;
			}
			rolling++;
			
			if(visit[rolling]!=0){
				j--;
			}
		}
		
		printf("%d, ",rolling);
		visit[rolling]=1;
	}
	
	for(int i=1;i<=n;i++){
		if(visit[i]==0){
			printf("%d>\n",i);
			break;
		}
	}
}
