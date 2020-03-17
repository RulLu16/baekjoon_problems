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
	long long a[10]={0,};
	int n,i,j;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		for(j=0;j<10;j++)
			scanf("%lld",&a[j]);
		qsort(a,10,sizeof(long long),compare);
		printf("%lld\n",a[7]);	
	}
}
