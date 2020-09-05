#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n;
	long long dp[1001];

	scanf("%d", &n);

	if (n == 1) {
		printf("0\n");
		return 0;
	}
	else if (n == 2) {
		printf("3\n");
		return 0;
	}

	dp[0] = 1; dp[1] = 0;
	dp[2] = 3; dp[3] = 0;

	for (int i = 4; i <= n; i++) {
		dp[i] = dp[i - 2] * 3 % 1000000007;

		for (int j = 4; j <= i; j += 2) {
			dp[i] = (dp[i - j] * 2 % 1000000007 + dp[i]% 1000000007)% 1000000007;
		}
	}

	printf("%lld\n", dp[n]);
}