#include <stdio.h>
#include <string.h>

#define MOD 1000000000

using namespace std;

int n,m;
long long power=1;
long long hashS=0; 
long long hashP=0;
char s[1000001];
char p[1000001];

long long mode(long long x){
	if(x>=0) return x%MOD;
	else return ((-x/MOD+1)*MOD+x)%MOD;
}

void rabin(){	
	for(int i=0;i<m;i++){
		hashS=mode(hashS+s[m-1-i]*power);
		hashP=mode(hashP+p[m-1-i]*power);
		if(i<m-1)	power=mode(power*2);
	}
}

int collision(int start){
	for(int i=0;i<m;i++){
		if(s[i+start]!=p[i]){
			return 0;
		}
	}
	return 1;
}

int main(){	
	scanf("%s",s);
	scanf("%s",p);
	
	n=strlen(s);
	m=strlen(p);
	
	for(int i=0;i<=n-m;i++){
		if(i==0) rabin();
		else hashS=mode(2*(hashS-s[i-1]*power)+s[i+m-1]);
		
		if(hashS==hashP){
			if(collision(i)==1){
				printf("1\n");
				return 0;
			}
		}
	}
	
	printf("0\n");
}
