#include <stdio.h>
#include <stdlib.h>

int main(){
	long long cur;
	long long f,s,g,u,d;
	long long* que;
	long long* visit;
	long long start, end;
	scanf("%lld %lld %lld %lld %lld",&f,&s,&g,&u,&d);
	que=(long long*)malloc(sizeof(long long)*(1000000+1));
	visit=(long long*)malloc(sizeof(long long)*(1000000+1));
	for(long long i=0;i<f;i++){
		que[i]=0;
		visit[i]=0;
	}
	
	start=1;
	end=0;
	que[end]=s;
	visit[s]=1;
	
	
	while(1){
		if(end==start){
			printf("use the stairs\n");
			break;
		}
		
		cur=que[end];
		
		if(cur==g){
			printf("%lld\n",visit[cur]-1);
			break;
		}
		
		if(cur+u<=f && visit[cur+u]==0){
			//printf("%lld\n",cur);
			visit[cur+u]=visit[cur]+1;
			que[start]=cur+u;
			start++;
		}
		if(cur-d>=1 && visit[cur-d]==0){
			visit[cur-d]=visit[cur]+1;
			que[start]=cur-d;
			start++;
		}
		end++;
	}
	
}
