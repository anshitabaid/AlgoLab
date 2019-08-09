#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int searchSubstring(char str[], char substring[]) {
	int opcount = 0;
	int n = strlen(str);
	int s = strlen(substring);
	int i, j;
	int k = n - s;
	int flag; // 1 <--- found
	for (i = 0; i < k; i++) {
		flag = 1;
		for(j = 0; j<s; j++) {
			opcount++;
			if (substring[j] != str[j+i]) {
				flag = 0;
				break;
			}
		}
		if (flag == 1) {
			printf("String found at index %d\n", i);
			return opcount;
		}
	}

	printf("String not found\n");
	return opcount;
}

int main() {
	char string[100], substring[100];
	printf("Enter a string:\n");
	gets(string);
	printf("Enter a substring you want to search for:\n");
	gets(substring);
	int opcount = searchSubstring(string, substring);
	printf("OPCOUNT: %d\n", opcount);
	return 0;
}
