#include <stdio.h>
#include <stdlib.h>

long long low(long long*, long long, long long); //found lower bound

int main(){
	long long n;
	long long* a;
	long long* dp;
	long long point;
	long long temp;
	long long i,j;
	
	scanf("%lld",&n);
	a=(long long*)malloc(sizeof(long long)*n);
	dp=(long long*)malloc(sizeof(long long)*n); // scan and make array
	
	if(n<2){
		printf("1\n");
		return 0; //if there is too little num n
	}
	else{
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]); //scan array A
	
		dp[0]=a[0];
		point=0;
		for(i=1;i<n;i++){
			if(dp[point]<a[i]){
				point++;
				dp[point]=a[i]; 
			}
			else{
				temp=low(dp,a[i],point);
				dp[temp]=a[i];	
			}
		}
		
		printf("%lld\n",point+1);
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
