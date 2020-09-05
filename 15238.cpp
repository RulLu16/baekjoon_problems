#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n;
	int alpha[26] = { 0, };
	int result=0;

	scanf("%d", &n);
	getchar();

	for (int i = 0; i < n; i++) {
		char temp;
		scanf("%1c", &temp);

		alpha[(int)temp - 'a']++;

		if (alpha[(int)temp - 'a'] > alpha[result]) result = (int)temp - 'a';
	}

	printf("%c %d", (char)result + 'a', alpha[result]);
}