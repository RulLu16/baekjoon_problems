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
	int n;
	int* p;
	int* sum;
	int i;
	int result=0;
	
	scanf("%d",&n);
	p=(int*)malloc(sizeof(int)*n);
	sum=(int*)malloc(sizeof(int)*n);
	
	for(i=0;i<n;i++)
		scanf("%d",&p[i]);
		
	
	qsort(p, n, sizeof(int), compare);
	sum[0]=p[0];
	result=p[0];
	
	for(i=1;i<n;i++){
		sum[i]=sum[i-1]+p[i];
		result=result+sum[i];
	}
	
	printf("%d\n",result);
}
