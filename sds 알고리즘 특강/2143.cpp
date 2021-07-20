#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
long long t;
long long ans = 0;

vector<long long> makePoint(vector<long long> arr){
	vector<long long> point;
	
	for(int left=0;left<arr.size();left++){
		long long sum = 0;
		for(int right=left;right<arr.size();right++){
			sum += arr[right];
			point.push_back(sum);
		}
	}
	
	sort(point.begin(), point.end());

	return point;
}

void solve(vector<long long> a, vector<long long> b){
	vector<long long> pointa = makePoint(a);
	vector<long long> pointb = makePoint(b);
	reverse(pointb.begin(), pointb.end());
	
	int posa = 0; int posb = 0;
	int sizea = pointa.size(); int sizeb = pointb.size();
	
	while(1){
		if(posa >= sizea || posb >= sizeb) break;
		
		long long mid = pointa[posa] + pointb[posb];
		if(mid == t){
			long long a_length = 1; long long b_length = 1;
			for(int i=posa+1;i<sizea;i++){
				if(pointa[i] != pointa[posa])
					break;
				a_length++;
			}
			
			for(int i=posb+1;i<sizeb;i++){
				if(pointb[i] != pointb[posb])
					break;
				b_length++;
			}
			ans += a_length * b_length; // 범위 생각 잘할 것 
			posa += a_length;
			posb += b_length;
		}	
		else if(mid < t){
			posa++;
		}	
		else if(mid > t){
			posb++;
		}
	}
	
}

int main(){
	vector<long long> a;
	vector<long long> b;
	
	scanf("%lld", &t);
	scanf("%d", &n);
	
	for(int i=0;i<n;i++){
		long long tmp;
		scanf("%lld", &tmp);
		
		a.push_back(tmp);
	} // a
	
	scanf("%d", &m);	
	for(int i=0;i<m;i++){
		long long tmp;
		scanf("%lld", &tmp);
		
		b.push_back(tmp);
	} // b
	
	solve(a, b);
	
	printf("%lld\n", ans);
}
