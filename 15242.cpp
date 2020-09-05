#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct {
	int x;
	int y;
	int depth;
}night;

queue <night> que;
int endX; int endY;
int xMove[8] = { -1, 1, 2, 2, -1, 1, -2, -2 };
int yMove[8] = { 2, 2, 1, -1, -2, -2, 1, -1 };
int visit[8][8] = { 0, };

void bfs() {
	while (!que.empty()) {
		int x = que.front().x; int y = que.front().y;
		int depth = que.front().depth; que.pop();

		for (int i = 0; i < 8; i++) {
			int nextX = x + xMove[i];
			int nextY = y + yMove[i];

			if (nextX < 0 || nextX >= 8 || nextY < 0 || nextY >= 8) continue;

			if (visit[nextX][nextY] == 0) {
				night newOne; newOne.x = nextX;
				newOne.y = nextY; newOne.depth = depth+1;
				que.push(newOne);
				visit[nextX][nextY] = 1;
			}

			if (nextX == endX && nextY == endY) {
				printf("%d\n", depth + 1);
				return;
			}
		}
	}
}

int main() {
	char temp;
	int num;
	int startX; int startY;

	scanf("%1c", &temp);
	scanf("%1d", &num);
	getchar();

	startX = 8 - num;
	startY = (int)temp - 'a';

	scanf("%1c", &temp);
	scanf("%1d", &num);

	endX = 8 - num;
	endY = (int)temp - 'a';

	if (startX == endX && startY == endY) {
		printf("0\n");
		return 0;
	}

	night newOne; newOne.x = startX;
	newOne.y = startY; newOne.depth = 0;
	que.push(newOne);
	visit[startX][startY] = 1;

	bfs();
}