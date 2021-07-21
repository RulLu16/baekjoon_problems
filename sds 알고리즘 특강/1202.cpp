#include <queue>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int> > jew;
vector<int> bag;
priority_queue<int> w;

int main(){
	int n, k;
	long long ans = 0;
	int idx = 0;
	scanf("%d %d", &n, &k);
	
	for(int i=0;i<n;i++){
		int first, second;
		scanf("%d %d", &first, &second);
		
		jew.push_back(make_pair(first, second));
	}
	
	for(int i=0;i<k;i++){
		int weight;
		scanf("%d", &weight);
		
		bag.push_back(weight);
	}
	
	sort(jew.begin(), jew.end());
	sort(bag.begin(), bag.end());
	
	for(int i=0;i<k;i++){
		
		while(1){
			if(idx < n && jew[idx].first <= bag[i]){
				w.push(jew[idx].second);
				idx++;
			}
			else break;
		}
		
		if(!w.empty()){
			ans += w.top();
			w.pop();
		}
	}
	
	printf("%lld\n", ans);
}
