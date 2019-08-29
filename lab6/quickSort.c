#include<stdio.h>
#include<stdlib.h>

int opcount = 0;

int partition (int arr[], int low, int high) { 
	int temp;
    int pivot=low;
	int i=low;
	int j=high;
	printf("pivot is %d\n",arr[pivot]);
	while(i<j) {
		while(arr[i]<=arr[pivot]&&i<=high) {
			opcount++;
			i++;
		}
		while(arr[j]>arr[pivot]&&j>=low) {
			opcount++;
			j--;
		}
		opcount++;
		if(i<j)
		{
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	temp=arr[j];
	arr[j]=arr[pivot];
	arr[pivot]=temp;
	return j;
} 

void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

int main() {
	int arr[50];
	int i,n;
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	printf("Enter the array elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	quickSort(arr,0,n-1);
	printf("After quick sort\n");
	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
	printf("\nOP count: %d", opcount);
	printf("\n");
}
