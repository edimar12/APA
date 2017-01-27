#include <stdio.h>
#include <stdlib.h>

void heap(int v[], int n) {
   int i = n / 2, pai, filho, t;
   while(1) {
      if (i > 0) {
          i--;
          t = v[i];
      } else {
          n--;
          if (n == 0) return;
          t = v[n];
          v[n] = v[0];
      }
      pai = i;
      filho = i * 2 + 1;
      while (filho < n) {
          if ((filho + 1 < n)  &&  (v[filho + 1] > v[filho]))
              filho++;
          if (v[filho] > t) {
             v[pai] = v[filho];
             pai = filho;
             filho = pai * 2 + 1;
          } else {
             break;
          }
      }
      v[pai] = t;
   }
}

int * insertion(int *v, int tam){
	int i, j, key;
	for(int i = 1; i < tam; i++){
		key = v[i];
		for(j = i-1; j>=0 && key < v[j];j--){
			v[j+1] = v[j];
		}
		v[j+1] = key;
	}
}

void merge(int *v, int inicio, int fim) {
    int i, j, k, meiotam, *vTemp;

    if(inicio == fim) return;

    meiotam = (inicio + fim ) / 2;
    merge(v, inicio, meiotam);
    merge(v, meiotam + 1, fim);

    i = inicio;
    j = meiotam + 1;
    k = 0;
    vTemp = (int *) malloc(sizeof(int) * (fim - inicio + 1));

    while(i < meiotam + 1 || j  < fim + 1) {
        if (i == meiotam + 1 ) { 
            vTemp[k] = v[j];
            j++;
            k++;
        }
        else {
            if (j == fim + 1) { 
                vTemp[k] = v[i];
                i++;
                k++;
            }
            else {
                if (v[i] < v[j]) {
                    vTemp[k] = v[i];
                    i++;
                    k++;
                }
                else {
                    vTemp[k] = v[j];
                    j++;
                    k++;
                }
            }
        }

    }

    for(i = inicio; i <= fim; i++) {
        v[i] = vTemp[i - inicio];
    }
    free(vTemp);

}

void quick(int * v, int inicio, int fim){
	int i, j, pivo, aux;
	i = inicio;
	j = fim;
	pivo = v[(inicio + fim)/2];
	while(i<j){
		while(v[i] < pivo) 
			i++;
		while(v[j] > pivo) 
			j--;
		if(i <= j){
			aux = v[i];
			v[i++] = v[j];
			v[j--] = aux;
		}
	}
	if(j > inicio) 
		quick(v, inicio, j);
	if(i < fim) 
		quick(v, i, fim);

	return;
}

int * selection(int *v, int size){
	int i,j,y, min, aux;
	for(i = 0; i<size-1; i++){
		min = i;
		for(j = i+1; j<size; j++){
			if(v[min] > v[j]) min = j;
		}
		aux = v[min];
		v[min] = v[i];
		v[i] = aux;
	}

}

//1 - numero do alg
//2 - nome do arquivo
int main(int argc, char** argv){
	if (argc < 1) exit(EXIT_FAILURE);
	int size,i;
	scanf("%d", &size);
	int * v = (int*) malloc(sizeof(int)*size);
	for(i = 0; i < size; i++)
		scanf("%d", &v[i]);	

	switch(atoi(argv[1])){
		case 1: 
			selection(v, size);	
			break;
		case 2:
			insertion(v, size);
			break;
		case 3:
			quick(v, 0, size-1);
			break;
		case 4:
			merge(v, 0 ,size-1);
			break;
		case 5:
			heap(v, size);
			break;
		default:
			printf("Numero de algoritmo invalido. Passa numero entre 1-5\n");
			exit(EXIT_FAILURE);
			break;			
	}
	
	  for(i = 0; i<size; i++) printf("%d\n",v[i]);

	return 0;
}
