#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)    // �������� �� �Լ� ����
{
    long long num1 = *(long long*)a;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������
    long long num2 = *(long long*)b;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������

    if (num1 < num2)    // a�� b���� ���� ����
        return -1;      // -1 ��ȯ
    
    if (num1 > num2)    // a�� b���� Ŭ ����
        return 1;       // 1 ��ȯ
    
    return 0;    // a�� b�� ���� ���� 0 ��ȯ
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
