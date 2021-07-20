#include <stdio.h>
#include <vector>

int main(){
	long long x, y;
	int z;
	long long ans = 1000000001;
	
	// 98%�� �������� ��, x�� �ݺ��ؾ� 99%�� ��.
	// �׷��Ƿ� �ִ� x�� �ؾ���. �̸� �̿��� search ���� 
	scanf("%d %d", &x, &y);
	 
	int start = 1; int end = x;
	z = y*100 / x;
	
	if(z == 100 || z == 99) {
		printf("-1\n");
		return 0;
	}
	
	while(start <= end){
		int mid = (start + end)/2;
		
		if(((y+mid) * 100) / (x+mid) >= z+1){
			if(mid < ans) ans = mid;
			end = mid - 1;
		}
		else{
			start = mid + 1;
		}
	}
	
	printf("%d\n", ans);
}
