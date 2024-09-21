
#ifndef AUX_H
#define AUX_H

typedef struct sortperf{
  int cmp;
  int move;
  int calls;
} sortperf_t;

void resetcounter(sortperf_t * s);
void inccmp(sortperf_t * s, int num);
void incmove(sortperf_t * s, int num);
void inccalls(sortperf_t * s, int num);
void swap(int *xp, int *yp, sortperf_t *s);
int median(int a, int b, int c);

#endif // AUX_H 