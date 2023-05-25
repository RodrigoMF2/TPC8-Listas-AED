//Uma lista encadeada circular é uma lista encadeada cujo último elemento aponta para
//o primeiro:
//Vantagem: cada elemento é acessível a partir de qualquer outro. Numa lista circular,
//não faz mais sentido se falar em primeiro ou último elemento. Porém, devemos saber,
//durante um percurso na lista, se já demos uma volta completa, para evitarmos loops
//infinitos. Para isso, assumimos a existência de um registro especial, chamado Cabeça
//de Lista, cujo campo de informação não pertence ao conjunto de elementos da lista
//(poderia até servir de sentinela numa busca).
//
//Construa algoritmos para:
//(a) contar o número de elementos numa lista circular;
//(b) inserir um elemento à esquerda da cabeça da lista;
//(c) eliminar o elemento de valor x;
//(d) concatenar duas listas circulares;
//(e) intercalar duas listas ordenadas;
//(f) fazer uma cópia da lista;

//(a) contar o número de elementos numa lista circular;
int contarElementos(struct No *cabeça){
  if (cabeça == NULL)
    return 0;

  struct No *atual = cabeça ->proximo;
  int contador = 1;
  while (atual != cabeça){
    contador++;
    atual = atual ->proximo;
  }
  return  contador;
}

//(b) inserir um elemento à esquerda da cabeça da lista;
void inserirEsquerda(struct No **cabeça, int x){
  struct NO *novo_no = criar_no(Valor);

  if(*cabeça == NULL){
    *cabeça = novo_no;
    novo_no->proximo = novo_no;
  }else{
    novo_no->proximo = *cabeça;
    struct No *atual = *cabeça;

    while(atual->proximo != *cabeça){
      atual = atual->proximo;
    }
    atual->proximo = novo-no;
    *cabeça = novo_no;
  }
}

//(c) eliminar o elemento de valor x;
void EliminarElemento(struct No **cabeça, int valor) {
    if (*cabeça == NULL)
        return;
    
    struct No *atual = *cabeça;
    struct No *anterior = NULL;
    
    while (1) {
        if (atual->valor == valor) {
            if (atual == *cabeça) {
                while (atual->proximo != *cabeça) {
                    atual = atual->proximo;
                }
                *cabeça = (*cabeça)->proximo;
                atual->proximo = *cabeça;
            } else {
                anterior->proximo = atual->proximo;
            }
            
            free(atual);
            return;
        } else {
            anterior = atual;
            atual = atual->proximo;
            
            if (atual == *cabeça)
                return;
        }
    }
}

//(d) concatenar duas listas circulares;
void ConcatenarListas(struct No **lista1, struct No **lista2) {
    if (*lista1 == NULL) {
        *lista1 = *lista2;
    } else {
        struct No *atual = *lista1;
        
        while (atual->proximo != *lista1) {
            atual = atual->proximo;
        }
        
        atual->proximo = *lista2;
    }
    
    struct No *atual = *lista2;
    
    while (atual->proximo != *lista2) {
        atual = atual->proximo;
    }
    
    atual->proximo = *lista1;
}

//(e) intercalar duas listas ordenadas;
void ConcatenarListas(struct No **lista1, struct No **lista2) {
    if (*lista1 == NULL) {
        *lista1 = *lista2;
    } else {
        struct No *atual = *lista1;
        
        while (atual->proximo != *lista1) {
            atual = atual->proximo;
        }
        
        atual->proximo = *lista2;
    }
    
    struct No *atual = *lista2;
    
    while (atual->proximo != *lista2) {
        atual = atual->proximo;
    }
    
    atual->proximo = *lista1;
}

//(f) fazer uma cópia da lista;
struct No* CopiarLista(struct No *cabeça) {
    if (cabeça == NULL)
        return NULL;
    
    struct No *copia_cabeça = NULL;
    struct No *atual = cabeça;
    
    do {
        InserirElemento(&copia_cabeça, atual->valor);
        atual = atual->proximo;
    } while (atual != cabeça);
    
    return copia_cabeça;
}