#include <stdio.h>


int * insertion(int *arr, int size){
	int i, j, key;
	for(int i = 1; i < size; i++){
		key = arr[i];
		for(j = i-1; j>=0 && key < arr[j];j--){
			arr[j+1] = arr[j];
		}
		arr[j+1] = key;
	}
}

int main(){
  int arr[] = {3,2,5,1,4,6,26,62,634,37,37,2,25,5,2,374,75,22};
  int size = sizeof(arr)/sizeof(arr[0]);
  insertion(arr,size);
  int i;
  for(i = 0; i<size; i++) printf("%d%s", arr[i],i != size-1 ? ", ":"\n") ;
}