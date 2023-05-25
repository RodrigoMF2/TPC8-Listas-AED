//O objetivo é criar uma lista de músicas, onde 
//cada música é representada por um nome e um artista.


#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

// Definição da estrutura Musica
struct Musica {
    char nome[50];
    char artista[50];
};

// Definição da estrutura No
struct No {
    struct Musica musica;
    int proximo;
};

// Definição da estrutura ListaEstatica
struct ListaEstatica {
    struct No elementos[MAX_SIZE];
    int livre;
};

// Função para criar uma nova lista
void CriarLista(struct ListaEstatica *lista) {
    // Inicializa a lista com os elementos livres apontando para o próximo índice
    lista->livre = 0;
    for (int i = 0; i < MAX_SIZE - 1; i++) {
        lista->elementos[i].proximo = i + 1;
    }
    lista->elementos[MAX_SIZE - 1].proximo = -1;
}

// Função para remover todos os elementos da lista
void RemoverLista(struct ListaEstatica *lista) {
    // Reinicia a lista, tornando todos os elementos livres
    lista->livre = 0;
}

// Função para inserir um novo elemento na lista
int InserirElemento(struct ListaEstatica *lista, struct Musica novaMusica) {
    // Verifica se a lista está cheia
    if (lista->livre == -1) {
        printf("A lista está cheia.\n");
        return -1;
    }
    
    int indice = lista->livre;  // Obtém o próximo índice livre
    lista->livre = lista->elementos[indice].proximo;  // Atualiza o próximo índice livre
    lista->elementos[indice].musica = novaMusica;  // Armazena a nova música no elemento
    lista->elementos[indice].proximo = -1;  // Define o próximo elemento como nulo
    
    return indice;  // Retorna o índice do elemento inserido
}

// Função para remover um elemento da lista
void RemoverElemento(struct ListaEstatica *lista, int indice) {
    // Verifica se o índice é válido
    if (indice < 0 || indice >= MAX_SIZE) {
        printf("Índice inválido.\n");
        return;
    }
    
    // Define o próximo elemento do elemento removido como o próximo índice livre
    lista->elementos[indice].proximo = lista->livre;
    lista->livre = indice;  // Atualiza o próximo índice livre para o índice removido
}

// Função para acessar um elemento da lista
struct Musica AcessarElemento(struct ListaEstatica *lista, int indice) {
    struct Musica musicaVazia = {"", ""};  // Retorna uma música vazia se o índice for inválido
    
    // Verifica se o índice é válido
    if (indice < 0 || indice >= MAX_SIZE) {
        printf("Índice inválido.\n");
        return musicaVazia;
    }
    
    return lista->elementos[indice].musica;  // Retorna a música do elemento
}

// Função para alterar um elemento da lista
void AlterarElemento(struct ListaEstatica *lista, int indice, struct Musica novaMusica) {
    // Verifica se o índice é válido
    if (indice < 0 || indice >= MAX_SIZE) {
        printf("Índice inválido.\n");
        return;
    }
    
    lista->elementos[indice].musica = novaMusica;  // Atualiza a música do elemento
}

// Função para classificar a lista em ordem crescente pelo nome da música
void ClassificarLista(struct ListaEstatica *lista) {
    int i, j;
    struct No temp;
    
    for (i = 0; i < MAX_SIZE - 1; i++) {
        for (j = i + 1; j < MAX_SIZE; j++) {
            // Compara os nomes das músicas e troca de posição se necessário
            if (strcmp(lista->elementos[i].musica.nome, lista->elementos[j].musica.nome) > 0) {
                temp = lista->elementos[i];
                lista->elementos[i] = lista->elementos[j];
                lista->elementos[j] = temp;
            }
        }
    }
}

// Função para criar uma cópia da lista
struct ListaEstatica CopiarLista(struct ListaEstatica *lista) {
    struct ListaEstatica listaCopia;
    
    CriarLista(&listaCopia);  // Cria uma nova lista vazia
    
    // Copia os elementos da lista original para a lista cópia
    for (int i = 0; i < MAX_SIZE; i++) {
        listaCopia.elementos[i] = lista->elementos[i];
    }
    
    return listaCopia;  // Retorna a lista cópia
}

int main() {
    struct ListaEstatica lista;
    CriarLista(&lista);  // Cria uma nova lista
    
    // Exemplo de uso das operações
    struct Musica m1 = {"Song 1", "Artist 1"};
    struct Musica m2 = {"Song 2", "Artist 2"};
    struct Musica m3 = {"Song 3", "Artist 3"};

    int indice1 = InserirElemento(&lista, m1);  // Insere a música m1 na lista
    int indice2 = InserirElemento(&lista, m2);  // Insere a música m2 na lista
    int indice3 = InserirElemento(&lista, m3);  // Insere a música m3 na lista

    struct Musica musicaAcessada = AcessarElemento(&lista, indice2);  // Acessa a música do índice 2
    printf("Música acessada: %s - %s\n", musicaAcessada.nome, musicaAcessada.artista);
    
    struct Musica novaMusica = {"Song 4", "Artist 4"};
    AlterarElemento(&lista, indice2, novaMusica);  // Altera a música do índice 2 para novaMusica
    
    RemoverElemento(&lista, indice1);  // Remove a música do índice 1 da lista

    ClassificarLista(&lista);  // Classifica a lista em ordem crescente pelo nome da música
    
    struct ListaEstatica listaCopia = CopiarLista(&lista);  // Cria uma cópia da lista original
    
    return 0;
}






