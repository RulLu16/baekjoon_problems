#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int start;
	int end;
}meet;

void sort(meet*,int, int);
void SWAP(meet*, meet*);
void Insertion_Sort(meet*, int, int);

int main(){
	int n;
	meet* m;
	int i;
	int result=1;
	int t_end;
	
	scanf("%d",&n);
	m=(meet*)malloc(sizeof(meet)*n);
	
	for(i=0;i<n;i++)
		scanf("%d %d",&m[i].start,&m[i].end);
		
	sort(m,0,n);
	Insertion_Sort(m,0,n);	
	t_end=m[0].end;
	
	for(i=0;i<n;i++){
		printf("%d %d\n",m[i].start,m[i].end);
	}
	
	for(i=1;i<n;i++){
		if(m[i].start>=t_end){
			result++;
			t_end=m[i].end;
		}
	}
	printf("%d\n",result);
}

void sort(meet* m,int left, int right){
	int temp;
	int i, j;
	int p=left;
	int mid = (left + right) / 2;
	
	if (right - left < 32)
	{
		/*for (i = left; i < right; i++) {
			for (j = i; j < right - 1; j++) {
				if (m[j].end > m[j+1].end) {
					SWAP(&m[j], &m[j+1]);
				}
				else if(m[j].end==m[j+1].end){
					if(m[j].start>m[left].start)
						SWAP(&m[j],&m[j+1]);
				}
			}
		}*/
		return;
	}
	else if (left<right)
	{
		
		for (i = left + 1; i < right; i++)
		{
			if (m[i].end < m[left].end)
			{
				j++;
				SWAP(&m[j],&m[i]);
			}
			else if(m[i].end==m[left].end){
				if(m[i].start<m[left].start){
					j++;
					SWAP(&m[j],&m[i]);
				}
			}
		}
		SWAP(&m[left], &m[j]);

		p = j;
		if (p < mid) {
			sort(m, left, p);
			sort(m, p + 1, right);
		}
		else
		{
			sort(m, p + 1, right);
			sort(m, left, p);
		}

	}
}

void Insertion_Sort(meet* data, int left, int right)
{
	meet temp;
	int i, j;
	for (i = left; i < right; i++)
	{
		temp = data[i];
		for (j = i; j >0; j--)
		{
			if (temp.end < data[j - 1].end)
				data[j]=data[j-1];
			else if(temp.end==data[j-1].end){
				if(temp.start<data[j-1].start)
					data[j]=data[j-1];
			}
			else
				break;
		}
		data[j]=temp;
	}
}

void SWAP(meet* a, meet* b){
	meet temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
