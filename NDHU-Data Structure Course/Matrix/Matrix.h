#ifndef _H_MATRIX
#define _H_MATRIX

typedef struct
{
    int row;
    int col;
    int value;

}Term;//Sparse-Matrix，左上角為(1,1)，沒有第0列、第0行

Term* getTranspose(Term* matrix);
Term* multi(Term* a,Term* b);

Term* fastTranspose(Term* m);
Term* mmult(Term* a, Term* b);
void storeSum(Term *m,int *total,int row,int col,int *sum,int max);

#endif // _H_MATRIX
