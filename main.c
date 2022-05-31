#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main(){
    ordenacao_500_posicoes();
}

void ordenacao_500_posicoes(){

    FILE *arquivo;
    clock_t inicio, fim;
    int tam = 500;
    int vetor[tam];
    int i = 1;

    arquivo = fopen("numeros.txt", "r");

    if (!arquivo)
    {
        printf("Problema ao abrir o arquivo!\n");
        return;
    }

    while (i<=tam){
        fscanf(arquivo, "%d", &vetor[i]);
        i++;
    }

    fclose(arquivo);

    int tempo = heapSort(vetor, tam);

    for (int j = 1; j <= 500; j++)
    {
        printf("Linha %d: %d\n", j, vetor[j]);
    }

    printf("Tempo de execucao Heap Sort: %lf", tempo);
}

// Métodos de Ordenação:

// void bubbleSort(int vet[], int TAM){
//     int i, j, aux;
//     for (i = 0; i < TAM - 1; i++)
//     {
//         for (j = i + 1; j < TAM; j++)
//         {
//             if (vet[i] > vet[j])
//             {
//                 aux = vet[i];
//                 vet[i] = vet[j];
//                 vet[j] = aux;
//             }
//         }
//     }
// }

// void insertionSort(int vet[], int TAM){
//     int i, j, chave;
//     for (i = 1; i < TAM; i++)
//     {
//         chave = vet[i];
//         j = i - 1;
//         while (j >= 0 && vet[j] > chave)
//         {
//             vet[j + 1] = vet[j];
//             j = j - 1;
//         }
//         vet[j + 1] = chave;
//     }
// }

// void selectionSort(int vet[], int TAM){
//     int i, j, min, aux;
//     for (i = 0; i < (TAM - 1); i++)
//     {
//         min = i;
//         for (j = (i + 1); j < TAM; j++)
//         {
//             if (vet[j] < vet[min])
//                 min = j;
//         }
//         if (i != min)
//         {
//             aux = vet[i];
//             vet[i] = vet[min];
//             vet[min] = aux;
//         }
//     }
// }

// void shellSort(int vet[], int TAM){

//     int h = 1, valor, j;

//     do{
//         h = (3 * h) + 1;
//     } while (h < TAM);

//     do{
//         h /= 3;
//         for (int i = h; i < TAM; i++)
//         {
//             valor = vet[i];
//             j = i - h;
//             while ((j >= 0) && (valor < vet[j])){
//                 vet[j + h] = vet[j];
//                 j -= h;
//             }
//             vet[j + h] = valor;
//         }
//     } while (h > 1);
// }

// void quickSort(int vetor[], int TAM, int inicio, int fim){
//     int pivo, aux, i, j, meio;

//     // inicio do processo de particao
//     i = inicio;
//     j = fim;
//     meio = (i+j) / 2;
//     pivo = vetor[meio];
//     do {
//         while(vetor[i] < pivo)
//             i = i + 1;
//         while(vetor[j] > pivo)
//             j = j - 1;
//         if (i <= j) {
//             aux = vetor[i];
//             vetor[i] = vetor[j];
//             vetor[j] = aux;
//             i = i + 1;
//             j = j - 1;
//         }
//     }while(j > i);
//     // fim do processo de participacao

//     if(inicio < j) {
//         quickSort(vetor, inicio, j);
//     }
//     if(i < fim) {
//         quickSort(vetor, i, fim);
//     }
// }

int heapSort(int vetor[], int TAM){
    int i, pai, filho, aux, n;
    clock_t inicio, fim;

    i = TAM/2;
    n = TAM;
    while(1) {
        if (i > 0) {
            i--;
            aux = vetor[i];
        } else {
            n--;
            if (n == 0)
                break;
            aux = vetor[n];
            vetor[n] = vetor[0];
        }
        pai = i;
        filho = (i*2) + 1;
        while (filho < n) {
            if ((filho + 1 < n) && (vetor[filho + 1] > vetor[filho]))
                filho++;
            if (vetor[filho] > aux) {
                vetor[pai] = vetor[filho];
                pai = filho;
                filho = (pai*2) + 1;
            } else
                break;
        }
        vetor[pai] = aux;
    }  
    fim = clock();
   // double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    //return tempo;
}
