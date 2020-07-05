#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector <int> card;

int upperBound(int key){
	int right=n-1;
	int left=0;
	int mid;
	
	while(left<right){
		mid=(right+left)/2;
		//printf("%lld\n",mid);
		
		if(card[mid]<=key){
			left=mid+1;
		}
		else{
			right=mid;
		}
	}
	return right;
}

int lowerBound(int key){
	int right=n-1;
	int left=0;
	int mid;
	
	while(left<right){
		mid=(right+left)/2;
		
		if(card[mid]>=key){
			right=mid;
		}
		else{
			left=mid+1;
		}
	}
	
	return right;
}

int main(){
	int m;
	int temp, key;
	
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		card.push_back(temp);
	}
	sort(card.begin(),card.end());
	
	/*for(long long i=0;i<n;i++){
		printf("%lld ",card[i]);
	}
	printf("\n");*/
	
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d",&key);
		
		int up=upperBound(key);
		int low=lowerBound(key);
		
		//printf("%lld %lld\n",up, low);
		if(up-low<0){
			printf("0 ");
		}
		else if(up==n-1 && card[up]==key){
			printf("%d ",up-low+1);
		}
		else{
			printf("%d ",up-low);
		}
	}
	printf("\n");
}
