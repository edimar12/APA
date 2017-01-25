#include <stdio.h>
#include <stdlib.h>

void quick(int * arr, int initial, int end){
	int i = initial, j = end, pivot, aux;
	pivot = arr[(initial + end)/2];
	while(i<j){
		while(arr[i] < pivot) i++;
		while(arr[j] > pivot) j--;
		if(i <= j){
			aux = arr[i];
			arr[i++] = arr[j];
			arr[j--] = aux;
		}
	}
	if(j > initial) quick(arr, initial, j);
	if(i < end) quick(arr, i, end);

	return;
}

int main(){
  int arr[] = {3,2,5,1,4,6,26,62,634,37,37,2,25,5,2,374,75,22};
  int size = sizeof(arr)/sizeof(arr[0]);
  quick(arr,0, size-1);
  int i;
  for(i = 0; i<size; i++) printf("%d%s", arr[i],i != size-1 ? ", ":"\n") ;
}