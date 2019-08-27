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

    // crescente
    for (int i = 0; i < MAX; i++)
    {
        array[i] = i;
    }

    double start, stop, elapsed;
    start = (double)clock() / CLOCKS_PER_SEC;
    quicksort(array, 0, MAX);
    stop = (double)clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;

    printf("Tempo de ordenacao crescente: %lf secs\n", elapsed);

    ////////////////////////////////////////////////

    //decrescente
    int j = MAX - 1;
    for (int i = 0; i < MAX; i++)
    {
        array[i] = j;
        j--;
    }

    start = (double)clock() / CLOCKS_PER_SEC;
    quicksort(array, 0, MAX);
    stop = (double)clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;

    printf("Tempo de ordenacao decrescente: %lf secs\n", elapsed);

    ////////////////////////////////////////////////
    // crescente/decrescente
    int k = MAX / 2;
    for (int i = 0; i < MAX; i++)
    {
        if (i < MAX / 2)
        {
            array[i] = i;
        }
        else
        {
            array[i] = k;
            k--;
        }
    }

    start = (double)clock() / CLOCKS_PER_SEC;
    quicksort(array, 0, MAX);
    stop = (double)clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;

    printf("Tempo de ordenacao crescente/decrescente: %lf secs\n", elapsed);

    /////////////////////////////////////////////////////////
    // decrescente/crescente

    k = MAX / 2;
    for (int i = 0; i < MAX; i++)
    {
        if (i > (MAX / 2) - 1)
        {
            array[i] = k;
            k++;
        }
        else
        {
            array[i] = k;
            k--;
        }
    }

    start = (double)clock() / CLOCKS_PER_SEC;
    quicksort(array, 0, MAX);
    stop = (double)clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;

    printf("Tempo de ordenacao decrescente/crescente: %lf secs\n", elapsed);
    ////////////////////////////////////////////////

    //aleatorio
    for (int i = 0; i < MAX; i++)
    {
        array[i] = rand() % MAX;
    }

    start = (double)clock() / CLOCKS_PER_SEC;
    quicksort(array, 0, MAX);
    stop = (double)clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;

    printf("Tempo de ordenacao aleatorio: %lf secs\n", elapsed);

    return 0;
}
