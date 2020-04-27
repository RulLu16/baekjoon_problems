#include <stdio.h>
#include <stdlib.h>

int n, m;
int list[10];
int num[10];
int visit[10]={0,};

void dfs(int depth){
	if(depth==m){
		for(int i=0;i<m;i++){
			printf("%d ",list[i]);
		}
		printf("\n");
		return;
	}	
	
	for(int i=0;i<n;i++){
		if(visit[i]==0){
			visit[i]=1;
			list[depth]=num[i];
			dfs(depth+1);
			visit[i]=0;
		}
	}
}

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
	int i;
	scanf("%d %d",&n, &m);
	
	for(i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	
	qsort(num, n, sizeof(int), compare);

	
	dfs(0);
}
