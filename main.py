def quicksort(array, inicio, fim):
    if inicio < fim:
        pivo = separa(array, inicio, fim)
        quicksort(array, inicio, pivo - 1) # Ordenar a esquerda
        quicksort(array, pivo + 1, fim) # Ordenar a direita

def separa(array, inicio, fim):
    pivo = array[fim]
    i = inicio - 1
    for j in range(inicio,fim-1):
        if array[j] <= pivo:
            i = i + 1
            # Troca
            array[i], array[j] = array[j], array[i]
    # Troca
    array[i + 1], array[fim] = array[fim], array[i + 1]
    return i + 1