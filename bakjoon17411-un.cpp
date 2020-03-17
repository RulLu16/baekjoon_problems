#include <stdio.h>
#include <stdlib.h>

long long low(long long*, long long, long long); //found lower bound

int main(){
	long long n;
	long long* a;
	long long* dp;
	long long point;
	long long* num;
	long long temp;
	long long i,j;
	long long div=10*10*10*10*10*10*10*10*10+7;
	scanf("%lld",&n);
	a=(long long*)malloc(sizeof(long long)*n);
	dp=(long long*)malloc(sizeof(long long)*n); // scan and make array
	num=(long long*)malloc(sizeof(long long)*(n+1));
	
	if(n<2){
		printf("1 1\n");
		return 0; //if there is too little num n
	}
	else{
		for(i=0;i<n;i++){
			scanf("%lld",&a[i]); //scan array A
			num[i]=0;
		}
		num[n]=0;
	
		dp[0]=a[0];
		point=0;
		for(i=1;i<n;i++){
			if(dp[point]<a[i]){
				point++;
				num[point]=(num[point]+1)%div;
				dp[point]=a[i]; 
			}
			else{
				temp=low(dp,a[i],point);
				if(temp==point || dp[temp]==a[i])
					num[temp]=(num[point]+1)%div;
				dp[temp]=a[i];	
			}
			printf("%lld ",num[point]);
		}
		
		printf("%lld %lld\n",point+1, num[point]);
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
