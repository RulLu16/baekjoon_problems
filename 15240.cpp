#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int map[1001][1001];
int visit[1001][1001] = { 0, };
int xMove[4] = { 0,1,0,-1 };
int yMove[4] = { 1,0, -1,0 };
int paint; int base;

void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nextX = x + xMove[i];
		int nextY = y + yMove[i];

		if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m) continue;

		if (visit[nextX][nextY] == 0 && map[nextX][nextY] == base) {
			visit[nextX][nextY] = 1;
			map[nextX][nextY] = paint;
			dfs(nextX, nextY);
			visit[nextX][nextY] = 0;
		}

	}
}

int main() {
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	int x; int y;
	scanf("%d %d %d", &x, &y, &paint);

	visit[x][y] = 1;
	base = map[x][y];
	map[x][y] = paint;
	dfs(x, y);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d", map[i][j]);
		}
		printf("\n");
	}
}