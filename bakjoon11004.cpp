#include <stdio.h>
#include <stdlib.h>

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

int main(){
	long long n,k;
	long long* a;
	long long i,j;
	
	scanf("%lld %lld",&n,&k);
	a=(long long*)malloc(sizeof(long long)*n);
	
	for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
	qsort(a, n, sizeof(long long), compare);
	/*for(i=0;i<n;i++)
		printf("%lld",a[i]);*/
	
	printf("%lld\n",a[k-1]);
}
