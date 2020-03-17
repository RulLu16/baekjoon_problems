#include <stdio.h>
#include <stdlib.h>

long long a[100001]={0,};

int compare(const void *a, const void *b)    // 오름차순 비교 함수 구현
{
    int num1 = *(int *)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
    int num2 = *(int *)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

    if (num1 < num2)    // a가 b보다 작을 때는
        return -1;      // -1 반환
    
    if (num1 > num2)    // a가 b보다 클 때는
        return 1;       // 1 반환
    
    return 0;    // a와 b가 같을 때는 0 반환
}

long long low(long long num, long long point){
	long long start, end, mid;
	start=0;
	end=point;
	mid=point/2;
	
	while(end-start>1){	
		if(a[mid]==num)
			return 1;

		if(a[mid]>num){
			end=mid;
			mid=(end+start)/2;
		}
		
		else{
			start=mid;
			mid=(end+start)/2;
		}
	}
	if(a[end]==num || a[start]==num)
		return 1;								// find lower bound by binary search
	return 0;
	
}

int main(){
	long long n,m;
	long long i;
	long long temp;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
	
	qsort(a,n,sizeof(long long),compare);
	
	scanf("%lld",&m);
	
	for(i=0;i<m;i++){
		scanf("%lld",&temp);
		printf("%lld\n",low(temp,n));
	}
}
