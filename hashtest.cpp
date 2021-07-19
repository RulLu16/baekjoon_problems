#include <stdio.h>
typedef unsigned int UI;
struct Node
{
	Node *next;
	char name[30];
	
	Node *alloc(char *key, Node *next)
	{
		next = np;
		
		strcpy(name, key);
		return this;
		
	}
}*htab[3000], buf[5000];
int N, M;
UI hashf(char *s)
{
	UI hash = 0;
	for(int i=0; i<strlen(s); i++)
	{
		hash = hash*33 + s[i];
	}
	return hash;
}
Node *prob (char *name, int hidx)
{
	Node *p = htab[hidx];
	
	for(;p;p=p->next)
	{
		if(strcmp(p->name,name)==0){
			return p;
		}
	}
	return NULL;
}
int main(void)
{
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
	{
		char name[30];
		
		scanf("%s", name);	
		
		UI hidx = hashf(name)%SIZE;
		
		Node *p = prbing(name , hidx);
		
		if(p)
		{
			htab[hidx] = buf[bcnt++].alloc(name, htab[hidx]);
		}
		else
		{
			htab[hidx] = buf[bcnt++].alloc(name, htab[hidx]);
		}
	}	
	for(int i=0; i<M; i++))
	return 0;
}






