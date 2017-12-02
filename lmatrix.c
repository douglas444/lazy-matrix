#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lmatrix.h"

void initialize_lmatrix(Lmatrix *lmatrix, int initial_value, int n, int order)
{
    int num_elements = pow(n,order);

    lmatrix->top = 0;
    lmatrix->n = n;
    lmatrix->order = order;
    lmatrix->initial_value = initial_value;

    lmatrix->values = (int*) malloc(sizeof(int) * num_elements);
    lmatrix->to = (unsigned int*) malloc(sizeof(unsigned int) * num_elements);
    lmatrix->from = (unsigned int*) malloc(sizeof(unsigned int) * num_elements);

}

void destroy_lmatrix(Lmatrix *lmatrix)
{
    free(lmatrix->values);
    free(lmatrix->to);
    free(lmatrix->from);
}

int lmatrix_read(Lmatrix *lmatrix, int *indexes)
{
    int i;
    int index = 0;

    for (i = 0; i <lmatrix->order; ++i)
    {
        index += pow(lmatrix->n, i) * indexes[i];
    }

    if (lmatrix->from[index] < lmatrix->top && lmatrix->to[lmatrix->from[index]] == index)
    {
        return lmatrix->values[index];
    }
    else
    {
        lmatrix->from[index] = lmatrix->top;
        lmatrix->to[lmatrix->top] = index;
        lmatrix->values[index] = lmatrix->initial_value;
        lmatrix->top++;
        return lmatrix->values[index];
    }
}

void lmatrix_write(Lmatrix *lmatrix, int *indexes, int value)
{
    int i;
    int index = 0;

    for (i = lmatrix->order - 1; i >= 0; --i)
    {
        index += pow(lmatrix->n, i) * indexes[i];
    }

    if (lmatrix->from[index] < lmatrix->top && lmatrix->to[lmatrix->from[index]] == index)
    {
        lmatrix->values[index] = value;
    }
    else
    {
        lmatrix->from[index] = lmatrix->top;
        lmatrix->to[lmatrix->top] = index;
        lmatrix->values[index] = value;
        lmatrix->top++;
    }
}
