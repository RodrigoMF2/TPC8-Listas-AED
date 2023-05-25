//O exercício consiste em criar uma lista duplamente ligada
//de números inteiros, onde cada nó da lista contém um número
//e ponteiros para o nó anterior e o próximo nó.
///Você pode implementar as seguintes funcionalidades:

//Inserir um novo número no início da lista.
//Inserir um novo número no final da lista.
//Remover um número da lista.
//todos os números da lista em ordem crescente.
//Exibir todos os números da lista em ordem decrescente.

// Definição da estrutura do nó da lista
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* aux = *head;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = newNode;
        newNode->prev = aux;
    }
}

void removeNode(Node** head, int data) {
    Node* aux = *head;
    if (aux->data == data) {
        *head = aux->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(aux);
    } else {
        while (aux->next != NULL) {
            if (aux->next->data == data) {
                Node* aux2 = aux->next;
                aux->next = aux->next->next;
                if (aux->next != NULL)
                    aux->next->prev = aux;
                free(aux2);
            } else {
                aux = aux->next;
            }
        }
    }
}

void printList(Node* head) {
    Node* aux = head;
    while (aux != NULL) {
        printf("%d ", aux->data);
        aux = aux->next;
    }
    printf("\n");
}

void printListReverse(Node* head) {
    Node* aux = head;
    while (aux->next != NULL) {
        aux = aux->next;
    }
    while (aux != NULL) {
        printf("%d ", aux->data);
        aux = aux->prev;
    }
    printf("\n");
}

void freeList(Node* head) {
    Node* aux = head;
    while (aux != NULL) {
        Node* aux2 = aux;
        aux = aux->next;
        free(aux2);
    }
    free(head);
}

int main() {
    Node* head = NULL;

    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 3);
    insertAtEnd(&head, 8);
    insertAtEnd(&head, 10);
    insertAtBeginning(&head, 1);

    printf("Lista em ordem crescente: ");
    printList(head);

    printf("Lista em ordem decrescente: ");
    printListReverse(head);

    removeNode(&head, 3);

    printf("Lista aposs remover o numero 3: ");
    printList(head);

    freeList(head);

    return 0;
}

