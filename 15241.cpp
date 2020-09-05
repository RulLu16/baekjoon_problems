#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int map[201][201];
long long dp[201][201] = { 0, };

int main() {
	scanf("%d %d", &n, &m);
	getchar();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char temp;
			scanf("%1c", &temp);

			if (temp == '.') map[i][j] = 0;
			else map[i][j] = 1;
		}
		getchar();
	}
	for (int i = 0; i < m; i++) {
		if (map[0][i] == 1) break;
		dp[0][i] = 1;
	}
	for (int i = 0; i < n; i++) {
		if (map[i][0] == 1) break;
		dp[i][0] = 1;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (map[i][j] == 1) {
				dp[i][j] = 0;
			}
			else dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
		}
	}

	printf("%lld\n", dp[n-1][m-1]);
}