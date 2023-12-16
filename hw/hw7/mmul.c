#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "matrix.h"

// Search TODO to find the locations where code needs to be completed

#define     NUM_THREADS     4

typedef struct {
    unsigned int id;
    TMatrix *m, *n, *t;
} thread_arg_t;

static void * thread_main(void * p_arg)
{
    // TODO
    thread_arg_t *arg = (thread_arg_t *)p_arg;

    int start_row = (arg->id) * (arg->m->nrows / NUM_THREADS);
    int end_row;
    if (arg->id == NUM_THREADS-1) end_row = arg->m->nrows;
    else end_row = (arg->id + 1) * (arg->m->nrows / NUM_THREADS);

    for (int i = start_row; i < end_row; i++)  {
        for (int j = 0; j < arg->n->ncols; j++) {
            TElement sum = (TElement)0;
            for (int k = 0; k < arg->m->ncols; k++)
                sum += arg->m->data[i][k] * arg->n->data[k][j];
            arg->t->data[i][j] = sum;
        }
    }
    return NULL;
}

/* Return the sum of two matrices.
 *
 * If any pthread function fails, report error and exit. 
 * Return NULL if anything else is wrong.
 *
 * Similar to mulMatrix, but with multi-threading.
 */
TMatrix * mulMatrix_thread(TMatrix *m, TMatrix *n)
{
    if (    m == NULL || n == NULL
         || m->ncols != n->nrows )
        return NULL;

    TMatrix * t = newMatrix(m->nrows, n->ncols);
    if (t == NULL)
        return t;

    // TODO
    pthread_t threads[NUM_THREADS];
    thread_arg_t thread_args_array[NUM_THREADS];

    for (int i=0; i<NUM_THREADS; i++) {
        thread_args_array[i].id = i;
        thread_args_array[i].m = m, thread_args_array[i].n = n, thread_args_array[i].t = t;

        if (pthread_create(&threads[i], NULL, thread_main, (void *)&thread_args_array[i]) != 0) {
            printf("thread create");
            exit(-1);
        }
    }

    for (int i=0; i<NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            printf("thread join");
            exit(-1);
        }
    }
    return t;
}