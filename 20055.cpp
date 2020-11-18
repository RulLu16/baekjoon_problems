#include <stdio.h>
#include <vector>

using namespace std;

int n, k;
int zero=0;
vector <pair<int, int> > durat;

void rolling(){
	int temp1 = durat[2*n-1].first;
	int temp2 = durat[2*n-1].second;
	
	for(int i=2*n-1;i>0;i--){
		durat[i].first = durat[i-1].first;
		durat[i].second = durat[i-1].second;
	}
	durat[0].first=temp1;
	durat[0].second=temp2;
	
	if(durat[n-1].second == 1){
		durat[n-1].second=0;
	}
}

void moving(){
	for(int i=n-2;i>=0;i--){
		if(durat[i+1].first>=1 && durat[i+1].second==0 && durat[i].second==1){
			durat[i+1].first--;
			durat[i+1].second=1;
			durat[i].second=0;
			
			if(durat[i+1].first==0) zero++;
		}
	}
	
	if(durat[n-1].second == 1){
		durat[n-1].second=0;
	}
}

void up(){
	if(durat[0].second==0 && durat[0].first>=1){
		durat[0].second=1;
		durat[0].first--;
		
		if(durat[0].first == 0) zero++;
	}
}

int main(){
	int ans=1;
	
	scanf("%d %d", &n, &k);
	
	for(int i=0;i<2*n;i++){
		int temp;
		
		scanf("%d",&temp);
		durat.push_back(make_pair(temp, 0));
	}
	
	while(1){
		rolling();
		moving();		
		up();
		
		if(zero>=k) {
			printf("%d\n", ans);
			break;
		}
		
		ans++;
	}
}
