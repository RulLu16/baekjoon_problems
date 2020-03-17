#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct{
	long long a;
	long long b;
}line;
long long low(long long*, long long, long long); //found lower bound

line a[102];

bool compare(line a, line b) {
	return a.a < b.a;
}

int main(){
	long long n;
	long long* dp;
	long long point;
	long long temp;
	long long first, second;
	long long i,j;
	
	scanf("%lld",&n);
	//a=(line*)malloc(sizeof(line)*n);
	dp=(long long*)malloc(sizeof(long long)*n); // scan and make array
	
	if(n<2){
		printf("0\n");
		return 0; //if there is too little num n
	}
	else{
		for(i=0;i<n;i++)
			scanf("%lld %lld",&a[i].a,&a[i].b); //scan array A
		
		sort(a, a + n + 1, compare);
		
		/*for(i=0;i<=n;i++)
			printf("%lld %lld\n",a[i].a,a[i].b);*/
			
		dp[0]=a[1].b;
		point=0;
		for(i=1;i<n;i++){
			if(dp[point]<a[i+1].b){
				point++;
				dp[point]=a[i+1].b;
			}
			else{
				temp=low(dp,a[i+1].b,point);
				dp[temp]=a[i+1].b;	
			}
		}
		
		printf("%lld\n",n-point-1);
	}
}

long long low(long long* dp, long long a, long long point){
	long long start, end, mid;
	start=0;
	end=point;
	mid=point/2;
	
	while(end-start>0){	
		if(dp[mid]>=a){
			if(dp[mid-1]<a)
				return mid;
			else{
				end=mid;
				mid=(end+start)/2;
			}
		}
		
		else{
			if(dp[mid+1]>=a)
				return mid+1;
			else{
				start=mid;
				mid=(end+start)/2;
			}
		}
	}								// find lower bound by binary search
	return end;
	
}
