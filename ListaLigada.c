/*A lista ligada é construída com nós contendo um valor inteiro e um ponteiro para o próximo nó na lista.
 As funções operam manipulando os ponteiros para criar, modificar, percorrer e remover elementos da lista.
*/

/*A lista ligada é construída com nós contendo um valor inteiro e um ponteiro para o próximo nó na lista.
 As funções operam manipulando os ponteiros para criar, modificar, percorrer e remover elementos da lista.
 *******************
 para esta lista ligada foi implementado as funcoes para armazenar nomes de estudantes numa lista
    Criar a lista
	Adicionar um nome na lista.
    Copia da lista
    Remover um nome da lista
    Procurar um nome 
    Alterar um nome da lista
    Imprimir todos os nomes da lista.
    Remover a lista
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[50];
    struct Node* next;
} Node;

Node* criarLista() {
    return NULL;
}

Node* adicionarNome(Node* head, const char* nome) {
    Node* novoNode = (Node*)malloc(sizeof(Node));
    strcpy(novoNode->name, nome);
    novoNode->next = NULL;

    if (head == NULL) {
        head = novoNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = novoNode;
    }

    printf("%s foi adicionado.\n", nome);
    return head;
}

Node* copiaLista(Node* head) {
    Node* copia = NULL;
    Node* temp = head;

    while (temp != NULL) {
        Node* novoNode = (Node*)malloc(sizeof(Node));
        strcpy(novoNode->name, temp->name);
        novoNode->next = NULL;

        if (copia == NULL) {
            copia = novoNode;
        } else {
            Node* copiaTemp = copia;
            while (copiaTemp->next != NULL) {
                copiaTemp = copiaTemp->next;
            }
            copiaTemp->next = novoNode;
        }

        temp = temp->next;
    }

    printf("A lista foi copiada.\n");
    return copia;
}

Node* removerNome(Node* head, const char* nome) {
    Node* temp = head;
    Node* prev = NULL;

    if (temp != NULL && strcmp(temp->name, nome) == 0) {
        head = temp->next;
        free(temp);
        printf("%s foi removido.\n", nome);
        return head;
    }

    while (temp != NULL && strcmp(temp->name, nome) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Elemento %s não está na lista.\n", nome);
        return head;
    }

    prev->next = temp->next;
    free(temp);
    printf("%s foi removido.\n", nome);
    return head;
}

void procurarNome(Node* head, const char* nome) {
    Node* temp = head;
    int encontrado = 0;

    while (temp != NULL) {
        if (strcmp(temp->name, nome) == 0) {
            printf("Elemento %s encontrado na lista.\n", nome);
            encontrado = 1;
            break;
        }
        temp = temp->next;
    }

    if (!encontrado) {
        printf("Elemento %s não está na lista.\n", nome);
    }
}

void alterarNome(Node* head, const char* nomeProcurar, const char* novoNome) {
    Node* temp = head;
    int alterado = 0;

    while (temp != NULL) {
        if (strcmp(temp->name, nomeProcurar) == 0) {
            strcpy(temp->name, novoNome);
            printf("Elemento %s alterado para %s.\n", nomeProcurar, novoNome);
            alterado = 1;
            break;
        }
        temp = temp->next;
    }

    if (!alterado) {
        printf("Elemento %s não está na lista.\n", nomeProcurar);
    }
}

void imprimirLista(Node* head) {
    if (head == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    printf("Elementos da lista: ");
    Node* temp = head;
    while (temp != NULL) {
        printf("%s ", temp->name);
        temp = temp->next;
    }
    printf("\n");
}

void removerLista(Node** head) {
    Node* atual = *head;
    Node* proximo;

    while (atual != NULL) {
        proximo = atual->next;
        free(atual);
        atual = proximo;
    }

    *head = NULL;
    printf("A lista foi removida.\n");
}



int main() {
    Node* head = criarLista();

    head = adicionarNome(head, "Aracy");
    head = adicionarNome(head, "Rodrigo");
    head = adicionarNome(head, "Neidilene");
    head = adicionarNome(head, "Naide");
    head = adicionarNome(head, "Stefany");

    imprimirLista(head);

    // Copiar a lista
    Node* copia = copiaLista(head);
    imprimirLista(copia);

    // Remover um nome da lista
    const char* nomeRemover = "Stefany";
    head = removerNome(head, nomeRemover);

    // Procurar um nome
    const char* nomeProcurar = "Aracy";
    procurarNome(head, nomeProcurar);

    // Alterar um nome
    const char* nomeAlterar = "Rodrigo";
    const char* novoNome = "Junior";
    alterarNome(head, nomeAlterar, novoNome);

    // Imprimir todos os nomes da lista
    imprimirLista(head);

    // Remover a lista
    removerLista(&head);

    return 0;
}
