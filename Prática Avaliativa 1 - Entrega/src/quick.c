#include "quick.h"
#include "aux.h"
#include "insertion_shell.h"


// quicksort partition using median of 3
void partition3(int * A, int l, int r, int *i, int *j, sortperf_t *s) {
   inccalls(s, 1);
   int pivot = median(A[l], A[(l + r) / 2], A[r]);
    *i = l;
    *j = r;
    while (*i <= *j) {
        inccmp(s, 1);
        while (A[*i] < pivot) {
            (*i)++;
            inccmp(s, 1);
        }
        while (A[*j] > pivot) {
            (*j)--;
            inccmp(s, 1);
        }
        inccmp(s, 1);
        if (*i <= *j) {
            swap(&A[*i], &A[*j], s);
            (*i)++;
            (*j)--;
        }
    }
}

// standard quicksort partition
void partition(int * A, int l, int r, int *i, int *j, sortperf_t *s) {
  inccalls(s, 1);
  int pivot = A[(l + r) / 2];
    *i = l;
    *j = r;
    while (*i <= *j) {
        inccmp(s,1);
        while (A[*i] < pivot) {
            (*i)++;
            inccmp(s, 1);
        }
        while (A[*j] > pivot) {
            (*j)--;
            inccmp(s, 1);
        }
        inccmp(s, 1);
        if (*i <= *j) {
            swap(&A[*i], &A[*j], s);
            (*i)++;
            (*j)--;
        }
    }
}

// standard quicksort
void quickSort(int * A, int l, int r, sortperf_t *s) {
  inccalls(s, 1);
  int i, j;
  i = l, j = r;
  partition(A, l, r, &i, &j, s);
  if (l < j) {
    quickSort(A, l, j, s);
  }
  if(r > i){
     quickSort(A, i, r, s);
  }
}

// quicksort with median of 3
void quickSort3(int * A, int l, int r, sortperf_t *s) {
  inccalls(s, 1);
  int i, j;
  i = l, j = r;
  partition3(A, l, r, &i, &j, s);
  if (l < j) {
    quickSort3(A, l, j, s);
  }
  if(r > i){
    quickSort3(A, i, r, s);
  }
}

// quicksort with insertion for small partitions
void quickSortIns(int * A, int l, int r, sortperf_t *s) {
    inccalls(s, 1);
    int threshold = 50;
    int i, j;
    i = l, j = r;
    partition(A, l, r, &i, &j, s);
    if (l < j) {
        if ((j - l) <= threshold) {
            insertionSort(A, l, j, s);
        } else {
            quickSortIns(A, l, j, s);
        }
    }
    if (r > i) {
        if ((r - i) <= threshold) {
            insertionSort(A, i, r, s);
        } else {
            quickSortIns(A, i, r, s);
        }
    }
}

// quicksort with insertion for small partitions and median of 3
void quickSort3Ins(int * A, int l, int r, sortperf_t *s) {
    inccalls(s, 1);
    int threshold = 50;
    int i, j;
    i = l, j = r;
    partition3(A, l, r, &i, &j, s);
    if (l < j) {
        if ((j - l) <= threshold) {
            insertionSort(A, l, j, s);
        } else {
            quickSort3Ins(A, l, j, s);
        }
    }
    if (r > i) {
        if ((r - i) <= threshold) {
            insertionSort(A, i, r, s);
        } else {
            quickSort3Ins(A, i, r, s);
        }
    }
}
