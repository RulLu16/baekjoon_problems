#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	vector<int> upward; // 위로 자람 
	vector<int> downward; // 아래로 자람
	
	vector<int> up_acc;
	vector<int> down_acc;
	
	int n, h;
	scanf("%d %d", &n, &h);
	
	for(int i=0;i<n;i+=2){
		int d, u;
		scanf("%d", &u);
		scanf("%d", &d);
		
		upward.push_back(u);
		downward.push_back(d);
	} 
	
	sort(upward.begin(), upward.end());
	sort(downward.begin(), downward.end());
	
	up_acc.assign(h+1, 0);
	down_acc.assign(h+1, 0);
	
	int num = 0;
	int idx = n/2 - 1;
	for(int i=h;i>0;i--){
		if(idx >= 0 && upward[idx] == i) {
			int same = 0;
			for(int j = idx - 1;j>=0;j--){
				if(upward[idx] != upward[j]){
					break;
				}
				same++;
			}
			num += same + 1;
			idx = idx - same - 1;
		}
		up_acc[i] = num;
	} // 석순 높이별 누적합 
	
	num = 0;
	idx = n/2 - 1;
	for(int i=1;i<=h;i++){
		if(idx >= 0 && h-downward[idx]+1 == i) {
			int same = 0;
			for(int j = idx - 1;j>=0;j--){
				if(downward[idx] != downward[j]){
					break;
				}
				same++;
			}
			num += same + 1;
			idx = idx - same - 1;
		}
		down_acc[i] = num;
	} // 종유석 높이별 누적합
	
	int min_v = n;
	int answer = 0;
	for(int i=1;i<=h;i++){
		int sum = up_acc[i] + down_acc[i];
		if(sum < min_v){
			min_v = sum;
			answer = 1;
		}
		else if(sum == min_v) {
			answer++;
		}
	}
	
	printf("%d %d\n", min_v, answer);	
}
