#include <stdio.h>

int * selection(int *arr, int size){
	int i,j,y, min, aux;
	for(i = 0; i<size-1; i++){
		min = i;
		for(j = i+1; j<size; j++){
			if(arr[min] > arr[j]) min = j;
		}
		aux = arr[min];
		arr[min] = arr[i];
		arr[i] = aux;
	}

}

int main(){
  int arr[] = {3,2,5,1,4,6,26,62,634,37,37,2,25,5,2,374,75,22};
  int size = sizeof(arr)/sizeof(arr[0]);
  selection(arr,size);
  int i;
  for(i = 0; i<size; i++) printf("%d%s", arr[i],i != size-1 ? ", ":"\n") ;
}
