#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RANGE 10000
#define RANGE_BUCKETS 1000
#define NBUCKET 1000
int get_max(int a[], int num_elements){
   int i, max= a[0];
   for (i=0; i<num_elements; i++)
   {
  if (a[i]>max)
  {
     max=a[i];
  }
   }
   return(max);
}
int get_min(int a[], int num_elements){
   int i, min= a[0];
   for (i=0; i<num_elements; i++)
   {
  if (a[i]<min)
  {
     min=a[i];
  }
   }
   return(min);
}


struct Node 
{ 
	int valor;  
	struct Node *next; 
};
int getBucketIndex(int valor)
{
	return valor/RANGE_BUCKETS;
}

struct Node *insertionSort(struct Node *list)
{	
	struct Node *k,*nodeList;
	if(list == 0 || list->next == 0) { 
		return list; 
	}
	
	nodeList = list; 
	k = list->next; 
	nodeList->next = 0; 
	while(k != 0) {	
		struct Node *ptr;

		if(nodeList->valor > k->valor)  { 
			struct Node *tmp;
			tmp = k;  
			k = k->next; 
			tmp->next = nodeList;
			nodeList = tmp; 
			continue;
		}

		for(ptr = nodeList; ptr->next != 0; ptr = ptr->next) {
			if(ptr->next->valor > k->valor) break;
		}

		if(ptr->next!=0){  
			struct Node *tmp;
			tmp = k;  
			k = k->next; 
			tmp->next = ptr->next;
			ptr->next = tmp; 
			continue;
		}
		else{
			ptr->next = k;  
			k = k->next;  
			ptr->next->next = 0; 
			continue;
		}
	}
	return nodeList;
}
void bucket(int arr[] ,int size)
{	
	int i,j, min;
	min = get_min(arr , size);
	for(i= 0 ; i < size ; i++){
		arr[i] = arr[i] -min; 
	}
	struct Node **buckets;  

	
	buckets = (struct Node **)malloc(sizeof(struct Node*) * NBUCKET); 

	
	for(i = 0; i < NBUCKET;++i) {  
		buckets[i] = NULL;
	}

	for(i = 0; i < size; ++i) {	
		struct Node *current;
		int pos = getBucketIndex(arr[i]);
		current = (struct Node *) malloc(sizeof(struct Node));
		current->valor = arr[i]; 
		current->next = buckets[pos];  
		buckets[pos] = current;
	}

	for(i = 0; i < NBUCKET; ++i) {  
		buckets[i] = insertionSort(buckets[i]); 
	}

	
	for(j =0, i = 0; i < NBUCKET; ++i) {	
		struct Node *node;
		node = buckets[i];
		while(node) {
			arr[j++] = node->valor + min;
			node = node->next;
		}
	}
	
	for(i = 0; i < NBUCKET;++i) {	
		struct Node *node;
		node = buckets[i];
		while(node) {
			struct Node *tmp;
			tmp = node; 
			node = node->next; 
			free(tmp);
		}
	}
	free(buckets); 
	return;
}


void counting(int arr[], int size , int range){
	int min ;

	min = get_min(arr, size);

	int output[size];
	int i;
	int count[range + 1];

	for(i = 0 ; i <size ; i++)
		arr[i] = arr[i] - min ;
	memset(count, 0, sizeof(count));


	for(i = 0; i< size; ++i)
		++count[arr[i]];

	for (i = 1; i <= range; ++i)
		count[i] += count[i-1];

	for (i = 0; i < size; ++i){
        	output[count[arr[i]]-1] = arr[i];
        	--count[arr[i]];
    	}
  
	for (i = 0; i<size; ++i){
        	arr[i] = output[i]+ min;
	}
}

void radix(int v[], int size) {
    int i;
    int *b;
    int maior = get_max(v,size);
    int exp = 1;

    b = (int *)calloc(size, sizeof(int));

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
	int size,i , range ;
	scanf("%d", &size);
	int * v = (int*) malloc(sizeof(int)*size);
	for(i = 0; i < size; i++)
		scanf("%d", &v[i]);
	
	switch(atoi(argv[1])){
		case 1: 
			range = get_max(v , size) - get_min(v, size);
			counting(v, size, range);	
			break;
		case 2:
			bucket(v, size);
			
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
