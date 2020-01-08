#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)    // 오름차순 비교 함수 구현
{
    long long num1 = *(long long*)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
    long long num2 = *(long long*)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

    if (num1 < num2)    // a가 b보다 작을 때는
        return -1;      // -1 반환
    
    if (num1 > num2)    // a가 b보다 클 때는
        return 1;       // 1 반환
    
    return 0;    // a와 b가 같을 때는 0 반환
}

int main(){
	long long n;
	int i;
	long long* sort;
	
	scanf("%llu",&n);
	sort=(long long*)malloc(sizeof(long long)*n);
	
	for(i=0;i<n;i++)
		scanf("%llu",&sort[i]);
		
	qsort(sort, n, sizeof(long long), compare);
	
	for(i=0;i<n;i++){
		printf("%d\n",sort[i]);
	}
	
}
