#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n;
	
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int size;
		int upperSize = 0; int lowerSize = 0; int digitSize = 0;
		int specialChar = 0; int satisfied = 0; // 1 == no, 2 == yes
		
		scanf("%d", &size);
		getchar();

		if (size < 12) satisfied = 1;

		for (int j = 0; j < size; j++) {
			char temp;
			scanf("%1c", &temp);

			if (satisfied == 1 || satisfied==2) continue;

			if (temp >= 'a' && temp <= 'z') lowerSize++;
			else if (temp >= 'A' && temp <= 'Z') upperSize++;
			else if (temp >= '0' && temp <= '9') digitSize++;
			else specialChar++;

			if (lowerSize > 0 && upperSize > 0 && digitSize > 0 && specialChar > 0 && size > 11) satisfied = 2;
		}

		if (satisfied == 2) printf("valid\n");
		else printf("invalid\n");

	}
}