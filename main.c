#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 100000

int separa(int v[], int p, int r)
{
    int c = v[r];
    int t, j = p;
    for (int k = p; k < r; ++k)
        if (v[k] <= c)
        {
            t = v[j];
            v[j] = v[k];
            v[k] = t;
            ++j;
        }
    t = v[j];
    v[j] = v[r];
    v[r] = t;
    return j;
}

void quicksort(int v[], int p, int r)
{
    if (p < r)
    {
        int j = separa(v, p, r);
        quicksort(v, p, j - 1);
        quicksort(v, j + 1, r);
    }
}

int main(int argc, char const *argv[])
{

    int array[MAX];
    int array1[MAX];
    int array2[MAX];
    int array3[MAX];
    int array4[MAX];

    // ordenado
    for (int i = 0; i < MAX; i++)
    {
        array[i] = i;
    }

    //
    int k = MAX / 2;
    for (int i = 0; i < MAX; i++)
    {
        if (i < MAX / 2)
        {
            array1[i] = i;
        }
        else
        {
            array1[i] = k;
            k--;
        }
    }

    //decrescente
    int j = MAX - 1;
    for (int i = 0; i < MAX; i++)
    {
        array2[i] = j;
        j--;
    }

    k = MAX / 2;
    for (int i = 0; i < MAX; i++)
    {
        if (i > (MAX / 2) - 1)
        {
            array3[i] = k;
            k++;
        }
        else
        {
            array3[i] = k;
            k--;
        }
    }

    //aleatorio
    for (int i = 0; i < MAX; i++)
    {
        array4[i] = rand() % MAX;
    }

    // for (int i = 0; i < MAX; i++)
    // {
    //     printf("%d \n", array4[i]);
    // }

    double start, stop, elapsed;
    start = (double)clock() / CLOCKS_PER_SEC;
    quicksort(array, 0, MAX);
    stop = (double)clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;

    printf("Tempo de execucao 1: %lf\n", elapsed);

    start = (double)clock() / CLOCKS_PER_SEC;
    quicksort(array2, 0, MAX);
    stop = (double)clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;

    printf("Tempo de execucao 2: %lf\n", elapsed);

    start = (double)clock() / CLOCKS_PER_SEC;
    quicksort(array1, 0, MAX);
    stop = (double)clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;

    printf("Tempo de execucao 3: %lf\n", elapsed);

    start = (double)clock() / CLOCKS_PER_SEC;
    quicksort(array3, 0, MAX);
    stop = (double)clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;

    printf("Tempo de execucao 4: %lf\n", elapsed);

    start = (double)clock() / CLOCKS_PER_SEC;
    quicksort(array4, 0, MAX);
    stop = (double)clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;

    printf("Tempo de execucao 5: %lf\n", elapsed);

    return 0;
}
