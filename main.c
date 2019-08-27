#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 100000

void troca(int vetor[], int a, int b)
{
    int temp = vetor[a];
    vetor[a] = vetor[b];
    vetor[b] = temp;
}

int separa(int vetor[], int inicio, int fim)
{
    int pivo = vetor[fim];
    int divide = inicio;
    for (int i = inicio; i < fim; i++)
    {
        if (vetor[i] <= pivo)
        {
            troca(vetor, divide, i);
            divide++;
        }
    }
    troca(vetor, divide, fim);
    return divide;
}

void quicksort(int vetor[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int pivo = separa(vetor, inicio, fim);
        quicksort(vetor, inicio, pivo - 1);
        quicksort(vetor, pivo + 1, fim);
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
