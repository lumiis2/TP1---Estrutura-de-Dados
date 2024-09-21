#include "selection.h"
#include "aux.h"

// recursive selection sort
void recursiveSelectionSort(int arr[], int l, int r, sortperf_t * s)
{
    int min = l;
    inccalls(s,1);
    for (int j = l + 1; j <= r; j++)
    {
	inccmp(s,1);
        if (arr[j] < arr[min]) {
            min = j;
        }
    }

    if (min!=l)
      swap(&arr[min], &arr[l], s);

    if (l + 1 < r) {
        recursiveSelectionSort(arr, l + 1, r, s);
    }
}

// selection sort
void selectionSort(int arr[], int l, int r, sortperf_t * s) {
    inccalls(s, 1);
    for (int i = l; i <= r; i++) {
        int min = i;
        for (int j = i + 1; j <= r; j++) {
            inccmp(s, 1);
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if(min == i) continue;
        else swap(&arr[i], &arr[min], s);
    }
    return;
}
