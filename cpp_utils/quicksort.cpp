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