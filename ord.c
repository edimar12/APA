#include <stdio.h>
#include <stdlib.h>

void heap(int a[], int n) {
   int i = n / 2, pai, filho, t;
   while(1) {
      if (i > 0) {
          i--;
          t = a[i];
      } else {
          n--;
          if (n == 0) return;
          t = a[n];
          a[n] = a[0];
      }
      pai = i;
      filho = i * 2 + 1;
      while (filho < n) {
          if ((filho + 1 < n)  &&  (a[filho + 1] > a[filho]))
              filho++;
          if (a[filho] > t) {
             a[pai] = a[filho];
             pai = filho;
             filho = pai * 2 + 1;
          } else {
             break;
          }
      }
      a[pai] = t;
   }
}

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

void merge(int *arr, int initial, int end) {
    int i, j, k, halfsize, *arrTemp;

    if(initial == end) return;

    halfsize = (initial + end ) / 2;
    merge(arr, initial, halfsize);
    merge(arr, halfsize + 1, end);

    i = initial;
    j = halfsize + 1;
    k = 0;
    arrTemp = (int *) malloc(sizeof(int) * (end - initial + 1));

    while(i < halfsize + 1 || j  < end + 1) {
        if (i == halfsize + 1 ) { 
            arrTemp[k] = arr[j];
            j++;
            k++;
        }
        else {
            if (j == end + 1) { 
                arrTemp[k] = arr[i];
                i++;
                k++;
            }
            else {
                if (arr[i] < arr[j]) {
                    arrTemp[k] = arr[i];
                    i++;
                    k++;
                }
                else {
                    arrTemp[k] = arr[j];
                    j++;
                    k++;
                }
            }
        }

    }

    for(i = initial; i <= end; i++) {
        arr[i] = arrTemp[i - initial];
    }
    free(arrTemp);

}

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

//1 - numero do alg
//2 - nome do arquivo
int main(int argc, char** argv){
	int size,i;
	FILE* file = fopen(argv[2], "r");
	fscanf(file, "%d", &size);
	int * arr = (int*) malloc(sizeof(int)*size);
	for(i = 0; i < size; i++)
		fscanf(file, "%d", &arr[i]);	

	switch(atoi(argv[1])){
		case 1: 
			selection(arr, size);	
			break;
		case 2:
			insertion(arr, size);
			break;
		case 3:
			quick(arr, 0, size-1);
			break;
		case 4:
			merge(arr, 0 ,size-1);
			break;
		case 5:
			heap(arr, size);
			break;
		default:
			printf("Numero de algoritmo invalido. Passa numero entre 1-5\n");
			exit(EXIT_FAILURE);
			break;			
	}
	
	  for(i = 0; i<size; i++) printf("%d%s", arr[i],i != size-1 ? ", ":"\n") ;

	return 0;
}
