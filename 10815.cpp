#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

long long n,m;
vector <long long> card;
//long long* search;
	
int binarySearch(long long key){
	long long right=n-1;
	long long left=0;
	long long mid=(right+left)/2;
	
	while(left<=right){
		if(key==card[mid])
			return 1;
		else if(key>card[mid]){
			left=mid+1;
		}
		else{
			right=mid-1;
		}
		mid=(right+left)/2;
	}
	
	return 0;	
}

int main(){
	long long temp;
	
	scanf("%lld",&n);
	
	for(long long i=0;i<n;i++){
		scanf("%lld",&temp);
		card.push_back(temp);	
	}
	sort(card.begin(), card.end());
	
	scanf("%lld",&m);
	for(long long i=0;i<m;i++){
		scanf("%lld",&temp);
		printf("%d ",binarySearch(temp));
	}
	printf("\n");
}
