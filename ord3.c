#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RANGE 9999
#define tam_bucket 1000
#define num_bucket 1000


typedef struct {
        int top;
        int balde[tam_bucket];
}bucket;
 
void buckets(int v[],int tam);                         
int cmpfunc (const void * a, const void * b); 
                                                            
void buckets(int v[],int tam){                                     
        bucket b[num_bucket];                                      
        int i,j,k;                                                 
	for(i=0;i<num_bucket;i++){                  
                 b[i].top=0;
        }
	for(i=0;i<tam;i++){                        
                j=(num_bucket)-1;
                while(1){
                        if(j<0)
                                break;
                        if(v[i]>=j*10){
                                b[j].balde[b[j].top]=v[i];
                                (b[j].top)++;
                                break;
                        }
                        j--;
                }
        }
         
	for(i=0;i<num_bucket;i++)                    
                 if(b[i].top)
			qsort(b[i].balde, b[i].top, sizeof(int), cmpfunc);
         
         i=0;
	for(j=0;j<num_bucket;j++){                  
                 for(k=0;k<b[j].top;k++){
                         v[i]=b[j].balde[k];
                         i++;
                 }
         }
 }
 int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

void counting(int arr[], int size){
    
	int output[size];
	int count[RANGE + 1], i;
	memset(count, 0, sizeof(count));
	
	for(i = 0; arr[i]; ++i)
		++count[arr[i]];

	for (i = 1; i <= RANGE; ++i)
		count[i] += count[i-1];

	for (i = 0; arr[i]; ++i){
        	output[count[arr[i]]-1] = arr[i];
        	--count[arr[i]];
    	}

	for (i = 0; arr[i]; ++i)
        	arr[i] = output[i];
}
void radix(int v[], int size) {
    int i;
    int *b;
    int maior = v[0];
    int exp = 1;

    b = (int *)calloc(size, sizeof(int));

    for (i = 0; i < size; i++) {
        if (v[i] > maior)
    	    maior = v[i];
    }
 
    while (maior/exp > 0) {
        int bucket[RANGE] = { 0 };
    	for (i = 0; i < size; i++)
    	    bucket[(v[i] / exp) % 10]++; 
    	for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];
    	for (i = size - 1; i >= 0; i--)
    	    b[--bucket[(v[i] / exp) % 10]] = v[i];
    	for (i = 0; i < size; i++)
    	    v[i] = b[i];
    	exp *= 10;
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
			counting(v, size);	
			break;
		case 2:
			buckets(v, size);
			
			break;
		case 3:
			radix(v, size);
			break;
		default:
			printf("Numero de algoritmo invalido-> Passa numero entre 1-5\n");
			exit(EXIT_FAILURE);
			break;			
	}
	for(i = 0; i<size; i++) printf("%d\n",v[i]);
	return 0;
}
