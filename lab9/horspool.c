#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 500

int opcount = 0;

void shiftTable(int shift[], int m,char s[]){
	int j, i;
	for(i = 0;i < max; i++)
		shift[i] = m;
	for(j = 0;j < m - 2; j++) {
		shift[s[j]] = m - 1 - j;
	}
}

int horsepool(int shift[], char pattern[], char text[], int lengthOfPattern, int lengthOfText) {
    int i, k;
	i = lengthOfPattern - 1;
	int flag = -1;

	while(i <= lengthOfText - 1) {
		k = 0;
		while((k <= lengthOfPattern - 1)&&(pattern[lengthOfPattern - 1 - k] == text[i-k])){
			opcount++;
            k = k + 1;
		}
		if(k == lengthOfPattern) {
			flag = i - lengthOfPattern + 1;
			break;
		}
		else
			i = i + shift[text[i]];
	}

    return flag;
}

int main() {
    int shift[26], lengthOfPattern, lengthOfText;
	char text[1000], pattern[1000];

    printf("Enter the text\n");
	fgets(text, sizeof(text), stdin);
	printf("Enter the pattern to be searched for\n");
	fgets(pattern, sizeof(pattern), stdin);
	
    lengthOfPattern = strlen(pattern);
    lengthOfText = strlen(text);
	
    shiftTable(shift, lengthOfPattern, pattern);
    
	if(horsepool(shift, pattern, text, lengthOfPattern, lengthOfText) == -1)
		printf("Not found\n");
	else
		printf("Found\n");

    printf("\nOPCOUNT: %d\n", opcount);
}