//Deap: https://github.com/NaiveRed/NDHU-Data-Structure-Course/tree/master/Deap
#include <cstdio>
#include <cstdlib>
#define PARENT(i) ((i) >> 1) //i/2
#define SIZE_TO_IDX(size) ((size) + 1)
#define N 1000001

inline int read()
{
    int n = 0;
    char c;
    while ((c = getchar()) >= '0' && c <= '9')
        n = n * 10 + c - '0';
    return n;
}
struct Deap
{
    int *arr;
    int size;
    int max_size;
};
Deap *createDeap(int size)
{
    Deap *deap = (Deap *)malloc(sizeof *deap);
    deap->arr = (int *)calloc(size + 2, sizeof(int));
    deap->max_size = size;
    deap->size = 0;

    return deap;
}
bool deapIsFull(Deap *d)
{
    return d->max_size == d->size;
}
bool deapIsEmpty(Deap *d)
{
    return d->size ? false : true;
}
bool InMaxHeap(int idx)
{
    while (idx > 3)
        idx /= 2;
    return idx == 3;
}
int correspondToMax(int size, int idx)
{
    if (idx == 2)
        return 2;
    int i;
    for (i = 2; i * 2 <= idx; i *= 2)
        ;
    i /= 2;
    if (idx + i > size)
        return (idx + i) / 2;
    return idx + i;
}
int correspondToMin(int idx)
{
    int i;
    for (i = 2; i * 2 <= idx; i *= 2)
        ;

    return idx - i / 2;
}
void insertMinHeap(Deap *d, int idx, int num)
{
    while (idx > 2 && num < d->arr[PARENT(idx)])
    {
        d->arr[idx] = d->arr[PARENT(idx)];
        idx = PARENT(idx);
    }

    d->arr[idx] = num;
}
void insertMaxHeap(Deap *d, int idx, int num)
{
    while (idx > 3 && num > d->arr[PARENT(idx)])
    {
        d->arr[idx] = d->arr[PARENT(idx)];
        idx = PARENT(idx);
    }

    d->arr[idx] = num;
}
bool insertDeap(Deap *d, int num)
{
    if (deapIsFull(d) || !d)
        return false;

    if (deapIsEmpty(d))
    {
        d->arr[2] = num;
        d->size++;
    }
    else
    {
        int idx = SIZE_TO_IDX(++d->size);
        int i;
        if (InMaxHeap(idx))
        {
            i = correspondToMin(idx);

            if (num < d->arr[i])
            {
                d->arr[idx] = d->arr[i];
                insertMinHeap(d, i, num);
            }
            else
                insertMaxHeap(d, idx, num);
        }
        else
        {
            i = correspondToMax(idx, idx);

            if (num > d->arr[i])
            {
                d->arr[idx] = d->arr[i];
                insertMaxHeap(d, i, num);
            }
            else
                insertMinHeap(d, idx, num);
        }
    }

    return true;
}
int popMinHeap(Deap *d)
{
    if (!d || deapIsEmpty(d))
    {
        exit(EXIT_FAILURE);
    }

    int min = d->arr[2];
    int temp = d->arr[SIZE_TO_IDX(d->size)];
    int size = SIZE_TO_IDX(--d->size);

    int p, c;
    for (p = 2; p * 2 <= size; p = c)
    {
        c = p * 2;
        if (c + 1 <= size)
            if (d->arr[c] > d->arr[c + 1])
                c++;
        d->arr[p] = d->arr[c];
    }

    int partner = correspondToMax(size, p);
    if (d->arr[partner] < temp)
    {

        d->arr[p] = d->arr[partner];
        insertMaxHeap(d, partner, temp);
    }
    else
        insertMinHeap(d, p, temp);

    return min;
}
int popMaxHeap(Deap *d)
{
    if (!d || deapIsEmpty(d))
    {
        //error message
        exit(EXIT_FAILURE);
    }
    else if (d->size == 1)
        return popMinHeap(d);

    int max = d->arr[3];
    int temp = d->arr[SIZE_TO_IDX(d->size)];
    int size = SIZE_TO_IDX(--d->size);

    int p, c;
    for (p = 3; p * 2 <= size;)
    {
        c = p * 2;
        if (c + 1 <= size)
            if (d->arr[c] < d->arr[c + 1])
                c++;
        d->arr[p] = d->arr[c];
        p = c;
    }

    int partner = correspondToMin(p);

    if (partner * 2 <= size)
    {
        partner *= 2;
        if (partner + 1 <= size && d->arr[partner] < d->arr[partner + 1])
            partner++;
    }

    if (d->arr[partner] > temp)
    {

        d->arr[p] = d->arr[partner];
        insertMinHeap(d, partner, temp);
    }
    else
        insertMaxHeap(d, p, temp);

    return max;
}

int searchDeap(Deap *d, int num)
{
    int size = SIZE_TO_IDX(d->size), i;
    for (i = 2; i <= size; i++)
        if (num == d->arr[i])
            return i;

    return 0;
}
void destroyDeap(Deap *d)
{
    //free
    free(d->arr);
    free(d);
}
int main()
{
    int n;

    while (scanf("%d", &n) && n)
    {
        Deap *deap = createDeap(100000 * n);
        getchar();

        long long sum = 0;

        for (int i = 0; i < n; ++i)
        {
            int k, bill;
            //scanf("%d", &k);
            k = read();
            for (int j = 0; j < k; ++j)
            {
                //scanf("%d", &bill);
                bill = read();
                insertDeap(deap, bill);
            }

            int high = popMaxHeap(deap), low = popMinHeap(deap);

            sum += high - low;
        }

        printf("%lld\n", sum);
        destroyDeap(deap);
    }

    return 0;
}
