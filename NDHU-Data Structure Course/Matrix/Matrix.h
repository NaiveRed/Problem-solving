#ifndef _H_MATRIX
#define _H_MATRIX

typedef struct
{
    int row;
    int col;
    int value;

}Term;//Sparse-Matrix�A���W����(1,1)�A�S����0�C�B��0��

Term* getTranspose(Term* matrix);
Term* multi(Term* a,Term* b);

Term* fastTranspose(Term* m);
Term* mmult(Term* a, Term* b);
void storeSum(Term *m,int *total,int row,int col,int *sum,int max);

#endif // _H_MATRIX
