// Quick sort
#include<stdio.h>
#include<conio.h>
#define SIZE 7
int partition(int a[], int lb, int ub);
int quickSort(int a[], int lb, int ub);
void main(){
	int a[SIZE] = {10,15,1,2,9,16,11};
	int i;
	clrscr();
	quickSort(a, 0, SIZE-1);
	for(i=0;i<SIZE;i++){
		printf("\n%d",a[i]);
	}
	getch();
}

int partition(int a[],int lb, int ub){
	int start = lb, end = ub, pivot = a[lb], temp;
	while(start < end){
		while(a[start] <= pivot && start < end){
			start++;
		}
		while(a[end] > pivot){
			end--;
		}
		if(start< end){
			temp = a[start];
			a[start] = a[end];
			a[end] = temp;
		}
	}
	temp = a[end];
	a[end] = a[lb];
	a[lb] = temp;
	return end;
}

int quickSort(int a[],int lb, int ub){
	int loc;
	if(lb < ub){
	       loc = partition(a,lb,ub);
	       quickSort(a, lb, loc-1);
	       quickSort(a,loc+1,ub);								}
}
