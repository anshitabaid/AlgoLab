#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
	int c = *a;
	*a = *b;
	*b = c;
}

int bubbleSort(int *arr, int n) {
	int upcount = 0, i, j;
	for (i = 0; i<n; i++) {
		for (j = 0; j<n-i-1; j++) {
			upcount++;
			if (*(arr+j) > *(arr+j+1))
				swap(arr+j, arr+j+1);
		}
	}
	return upcount;
}

int main() {
	int n;
	printf("Enter size of the array: ");
	scanf("%d", &n);
	int *arr = malloc(n*sizeof(int));
	printf("Enter elements of the array. Syntax: 2 1 4 3\n");
	for (int i =0; i < n; i++)
		scanf("%d", (arr+i));
	int upcount = bubbleSort(arr, n);
	printf("Sorted array is:\n");
	for(int i =0; i < n; i++)
		printf("%d ", *(arr+i));
	printf("UPCOUNT: %d\n", upcount);
	return 0;
}
