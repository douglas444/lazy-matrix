struct lmatrix
{
    int n;
    int top;
    int order;
    int *values;
    int initial_value;
    unsigned int *to;
    unsigned int *from;
};
typedef struct lmatrix Lmatrix;

void initialize_lmatrix(Lmatrix *lmatrix, int initial_value, int n, int order);
void destroy_lmatrix(Lmatrix *lmatrix);
int lmatrix_read(Lmatrix *lmatrix, int *indexes);
void lmatrix_write(Lmatrix *lmatrix, int *indexes, int value);
