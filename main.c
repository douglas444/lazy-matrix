#include <stdio.h>
#include <stdlib.h>
#include "lmatrix.h"

int main()
{
    int i, j, indexes[2], count;

    Lmatrix lmatrix;
    initialize_lmatrix(&lmatrix, -1, 5, 2);

    for (i = 0; i < 5; ++i)
    {
        for (j = 0; j < 5; ++j)
        {
            indexes[0] = i;
            indexes[1] = j;

            printf("%d ", lmatrix_read(&lmatrix, indexes));
        }
        printf("\n");
    }

    destroy_lmatrix(&lmatrix);
    initialize_lmatrix(&lmatrix, -1, 5, 2);

    count = 10;
    printf("\n");
    for (i = 0; i < 5; ++i)
    {
        for (j = 0; j < 5; ++j)
        {
            indexes[0] = i;
            indexes[1] = j;

            lmatrix_write(&lmatrix, indexes, count);

            ++count;
        }
    }

    for (i = 0; i < 5; ++i)
    {
        for (j = 0; j < 5; ++j)
        {
            indexes[0] = i;
            indexes[1] = j;

            printf("%d ", lmatrix_read(&lmatrix, indexes));
        }
        printf("\n");
    }

    destroy_lmatrix(&lmatrix);

    return 0;
}
