#include <stdio.h>
#include <stdlib.h>

long long a[100001]={0,};

int compare(const void *a, const void *b)    // �������� �� �Լ� ����
{
    int num1 = *(int *)a;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������
    int num2 = *(int *)b;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������

    if (num1 < num2)    // a�� b���� ���� ����
        return -1;      // -1 ��ȯ
    
    if (num1 > num2)    // a�� b���� Ŭ ����
        return 1;       // 1 ��ȯ
    
    return 0;    // a�� b�� ���� ���� 0 ��ȯ
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
