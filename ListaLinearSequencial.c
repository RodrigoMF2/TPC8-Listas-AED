/*
Uma lista linear sequencial, 
também conhecida como lista sequencial, 
é uma estrutura de dados que armazena elementos em uma sequência contígua de memória
****************
   para esta lista sequencial foi implementado as funcoes 
    Criar a lista
	Adicionar um numero na lista.
    Remover um numero da lista
    Procurar um numero 
    Alterar um numero da lista
    Imprimir todos os numeros da lista.
    Remover a lista
    Copia da lista*/
#include <stdio.h>
#include <stdlib.h>

#define TAM 10

typedef struct {
    int data[TAM];
    int tamanho;
} ListaSequencial;

void inicializar(ListaSequencial *list) {
    list->tamanho = 0;
}

void adicionar(ListaSequencial *list, int num) {
    if (list->tamanho < TAM) {
        list->data[list->tamanho] = num;
        list->tamanho++;
        printf("%d foi adicionado.\n", num);
    } else {
        printf("Não é possível adicionar o elemento %d. A lista está cheia.\n", num);
    }
}

void remover(ListaSequencial *list, int num) {
    int encontrado = 0;
    int i;

    for (i = 0; i < list->tamanho; i++) {
        if (list->data[i] == num) {
            encontrado = 1;
            break;
        }
    }

    if (encontrado) {
        for (; i < list->tamanho - 1; i++) {
            list->data[i] = list->data[i + 1];
        }
        list->tamanho--;
        printf("%d foi removido.\n", num);
    } else {
        printf("Elemento %d não está na lista.\n", num);
    }
}

int procurar(ListaSequencial *list, int num) {
    for (int i = 0; i < list->tamanho; i++) {
        if (list->data[i] == num) {
            printf("Elemento %d encontrado na lista na posição %d.\n", num, i);
            return i;
        }
    }
    printf("Elemento %d não está na lista.\n", num);
    return -1;
}

void alterar(ListaSequencial *list, int pos, int novoNum) {
    if (pos >= 0 && pos < list->tamanho) {
        list->data[pos] = novoNum;
        printf("Elemento na posição %d alterado para %d.\n", pos, novoNum);
    } else {
        printf("Posição inválida.\n");
    }
}

void imprimir(ListaSequencial *list) {
    if (list->tamanho == 0) {
        printf("A lista está vazia.\n");
    } else {
        printf("A lista: ");
        for (int i = 0; i < list->tamanho; i++) {
            printf("%d ", list->data[i]);
        }
        printf("\n");
    }
}

void removerLista(ListaSequencial *list) {
    inicializar(list);
    printf("A lista foi removida.\n");
}

void copiarLista(ListaSequencial *dest, ListaSequencial *src) {
    inicializar(dest);

    for (int i = 0; i < src->tamanho; i++) {
        dest->data[i] = src->data[i];
        dest->tamanho++;
    }

    printf("A lista foi copiada.\n");
}

int main() {
    ListaSequencial list;
    inicializar(&list);

    adicionar(&list, 2);
    adicionar(&list, 4);
    adicionar(&list, 6);
    adicionar(&list, 8);
    adicionar(&list, 10);

    imprimir(&list);

    // Remover um número da lista
    int numRemover = 6;
    remover(&list, numRemover);
    printf("%d foi removido.\n", numRemover);

    // Copiar a lista
    ListaSequencial copia;
    copiarLista(&copia, &list);
    printf("Cópia da lista:\n");
    imprimir(&copia);

    // Procurar um número
    int numProcurar = 4;
    int pos = procurar(&list, numProcurar);


    // Alterar um número
    int posAlterar = 3;
    int novoNum = 12;
    alterar(&list, posAlterar, novoNum);

    // Imprimir todos os números da lista
    imprimir(&list);

    // Remover a lista
    removerLista(&list);

    return 0;
}
