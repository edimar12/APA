#include <stdio.h>

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

int main(){
  int arr[] = {3,2,5,1,4,6,26,62,634,37,37,2,25,5,2,374,75,22};
  int size = sizeof(arr)/sizeof(arr[0]);
  heap(arr,size);
  int i;
  for(i = 0; i<size; i++) printf("%d%s", arr[i],i != size-1 ? ", ":"\n") ;
}