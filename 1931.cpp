#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector <pair<long long, long long> > meeting;

int greedy(){
	int result=0;
	long long endTime=meeting[0].second-1;
	
	for(int i=0;i<n;i++){
		if(endTime<=meeting[i].second){
			result++;
			endTime=meeting[i].first;
		}
	}
	
	return result;
}

int main(){
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		long long first, second;
		scanf("%lld %lld",&first, &second);
		meeting.push_back(make_pair(second, first));
	}
	sort(meeting.begin(), meeting.end());
	
	printf("%d\n",greedy());
}
