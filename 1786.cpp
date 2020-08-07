#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

#define MOD 1000000007

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
	long long result=0;
	vector <long long> position;
	
	scanf("%[^\n]s",s);
	getchar();
	scanf("%[^\n]s",p);
	
	n=strlen(s);
	m=strlen(p);
	
	for(int i=0;i<=n-m;i++){
		if(i==0) rabin();
		else hashS=mode(2*(hashS-s[i-1]*power)+s[i+m-1]);
		
		if(hashS==hashP){
			if(collision(i)==1){
				result++;
				position.push_back(i+1);
			}
		}
	}
	
	printf("%lld\n",result);
	
	for(int i=0;i<position.size();i++){
		printf("%lld ",position[i]);
	}
}
