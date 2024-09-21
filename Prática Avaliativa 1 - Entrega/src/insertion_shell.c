#include "insertion_shell.h"
#include "aux.h"


// shellsort
void shellSort(int *A, int n, sortperf_t * s) {
  inccalls(s, 1);
  for (int h = n / 2; h > 0; h /= 2) {
        for (int i = h; i < n; i++) {
            incmove(s,1);
            int temp = A[i];
            int j;
            for (j = i; j >= h && A[j - h] > temp; j -= h) {
                inccmp(s, 1);
                A[j] = A[j - h];
                incmove(s, 1);
            }
            A[j] = temp;
            incmove(s, 1);
            inccmp(s,1);
        }
    } 
}

//insertion sort
void insertionSort(int v[], int l, int r, sortperf_t * s) {
  inccalls(s, 1);
  for (int i = l + 1; i <= r; i++) {
    int key = v[i];
    int j = i - 1;
    incmove(s, 1);
    while (j >= l && v[j] > key) {
      inccmp(s,1);
      incmove(s,1);
      v[j + 1] = v[j];
      j--;
    }
    inccmp(s,1);
    incmove(s, 1);
    v[j + 1] = key;
  }
  return;
}