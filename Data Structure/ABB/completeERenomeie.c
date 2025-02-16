#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    int contador;
    struct no* esq;
    struct no* dir;
} NO, *PONT;

void inicializar(PONT* raiz);
PONT criarNo(int valor);
PONT buscar(PONT raiz, int valor);
PONT inserir(PONT raiz, int valor);
PONT removerUmaOcorrencia(PONT raiz, int valor);
PONT removerTodasOcorrencias(PONT raiz, int valor); // Declaração adicionada
void exibirInOrder(PONT raiz);
int contarNos(PONT raiz);
int contarTotalElementos(PONT raiz);
int kEsimoMenor(PONT raiz, int k);
void imprimirIntervalo(PONT raiz, int min, int max);
PONT lowestCommonAncestor(PONT raiz, int val1, int val2);

void inicializar(PONT* raiz) {
    *raiz = NULL;
}

PONT criarNo(int valor) {
    PONT novo = (PONT) malloc(sizeof(NO));
    if (novo) {
        novo->chave = valor;
        novo->contador = 1;
        novo->esq = NULL;
        novo->dir = NULL;
    }
    return novo;
}

PONT buscar(PONT raiz, int valor) {
    if (raiz == NULL) return NULL; //Retorna nulo se nao existir
    if (valor == raiz->chave) return raiz; //Retorna a raiz se a raiz for igual ao valor a ser buscado
    if (valor < raiz->chave) //Se o valor for menor que a raiz
        return buscar(raiz->esq, valor); //Ela e recursiva com a raiz sendo o nó à direita dela
    else //Se o valor for maior que a raiz
        return buscar(raiz->dir, valor); //Ela e recursiva com a raiz sendo o nó à esquerda dela
}

PONT inserir(PONT raiz, int valor) {
    if (raiz == NULL) { //Se a raiz aponta para NULL
        return criarNo(valor); //Cria um novo nó com a chave=valor
    }
    if (valor < raiz->chave) { // Se o valor for menor do qual a raiz está apontando
        raiz->esq = inserir(raiz->esq, valor); //A funçao é recursiva com a raiz sendo o nó a esquerda
    } else if (valor > raiz->chave) { // Se o valor for maior do qual a raiz está apontando
        raiz->dir = inserir(raiz->dir, valor); //A funçao é recursiva com a raiz sendo o nó a direita
    } else { //Se raiz == valor
        raiz->contador++; //Ela já está contida na árvore entao incrementa contador
    }
    return raiz;
}

PONT removerUmaOcorrencia(PONT raiz, int valor) {
    if (raiz == NULL) return NULL; //Se raiz == NULL, o valor nao esta contido na árvore. Logo, ele nao está contido e nao pode ser removido

    //Busca o nó que contanha valor
    if (valor < raiz->chave) { //Se o valor for menor que a raiz
        raiz->esq = removerUmaOcorrencia(raiz->esq, valor); //A funçao é recursiva com a raiz sendo o nó a esquerda
    } else if (valor > raiz->chave) { //Se o valor for maior que a raiz
        raiz->dir = removerUmaOcorrencia(raiz->dir, valor); //A funçao e recursiva com a raiz sendo o nó a direita
    } else { //Achou o nó que contém o valor a ser removido
        if (raiz->contador > 1) { //Contador > 1 (apenas decrementa o contador)
            raiz->contador--; 
            return raiz; 
        }

        //Contador = 1 e nó com 0 ou 1 filho
        //Substitui o nó pelo seu único filho (se existir) ou o remove (se for folha).
        if (raiz->esq == NULL) {  
            PONT temp = raiz->dir; 
            free(raiz); 
            return temp; 
        } else if (raiz->dir == NULL) { 
            PONT temp = raiz->esq; 
            free(raiz); 
            return temp;
        }

        //Contador = 1 e nó com 2 filhos

        //Encontra o menor nó da subárvore direita (sucessor in-order).
        //Copia a chave e o contador desse nó para o nó atual.
        //Remove o sucessor da subárvore direita
        PONT temp = raiz->dir; 
        while (temp->esq != NULL)
            temp = temp->esq;
        raiz->chave = temp->chave;
        raiz->contador = temp->contador;
        raiz->dir = removerTodasOcorrencias(raiz->dir, temp->chave);
    }
    //Retorna raiz atualizada
    return raiz;
}

PONT removerTodasOcorrencias(PONT raiz, int valor) {
    if (raiz == NULL) return NULL; //Se raiz == NULL, o valor nao está contido na árvore. Logo, ele nao está contido e nao pode ser removido

    //Busca o nó a ser removido
    if (valor < raiz->chave) {
        raiz->esq = removerTodasOcorrencias(raiz->esq, valor);
    } else if (valor > raiz->chave) {
        raiz->dir = removerTodasOcorrencias(raiz->dir, valor);
    //Nó encontrado (valor == raiz->chave)
    } else {
        //Nó com 0 ou 1 filho
        if (raiz->esq == NULL) {
            PONT temp = raiz->dir;
            free(raiz);
            return temp;
        } else if (raiz->dir == NULL) {
            PONT temp = raiz->esq;
            free(raiz);
            return temp;
        //Nó com 2 filhos
        } else {
            PONT temp = raiz->dir;
            while (temp->esq != NULL)
                temp = temp->esq;
            raiz->chave = temp->chave;
            raiz->contador = temp->contador;
            raiz->dir = removerTodasOcorrencias(raiz->dir, temp->chave);
        }
    }
    //Retorna raiz atualizada
    return raiz;
}

void exibirInOrder(PONT raiz) {
    if (raiz == NULL) return; //Árvore vazia retorna NULL
    exibirInOrder(raiz->esq); //Percorre a subárvore esquerda
    for (int i = 0; i < raiz->contador; i++) //Exibe o valor da raiz
        printf("%d ", raiz->chave);
    exibirInOrder(raiz->dir); //Percorrer a subárvore direita
}

int contarNos(PONT raiz) {
    if (raiz == NULL) return 0; //Árvore vazia retorna 0
    return 1 + contarNos(raiz->esq) + contarNos(raiz->dir); //Retorna a contagem recursiva dos nós
}

int contarTotalElementos(PONT raiz) {
    if (raiz == NULL) return 0; //Árvore vazia retorna 0
    return raiz->contador + contarTotalElementos(raiz->esq) + contarTotalElementos(raiz->dir); //Retorna a soma dos contadores de todos os nós
}

int kEsimoMenorAux(PONT raiz, int k, int* count) { 
    if (raiz == NULL) return -1; //Árvore vazia retorna NULL

    int leftResult = kEsimoMenorAux(raiz->esq, k, count); // Percorre a subárvore esquerda recursivamente
    if (leftResult != -1) return leftResult; // Se o k-ésimo menor for encontrado na subárvore esquerda, retorna o valor.

    // Verifica o nó atual
    for (int i = 0; i < raiz->contador; i++) { // Itera sobre o contador do nó atual para considerar todas as ocorrencias da chave
        (*count)++;
        if (*count == k) return raiz->chave; // Se o contador atingir o valor de k, retorna a chave atual
    }

    int rightResult = kEsimoMenorAux(raiz->dir, k, count); // Percorre a subárvore direita recursivamente
    if (rightResult != -1) return rightResult; // Se o k-ésimo menor for encontrado na subárvore direita, retorna o valor

    return -1;
}

int kEsimoMenor(PONT raiz, int k) {
    int count = 0; //Inicializa contador = 0
    return kEsimoMenorAux(raiz, k, &count); // Chama a função auxiliar, passando a raiz, k e o endereço do contador
}

void imprimirIntervalo(PONT raiz, int min, int max) {
    if (raiz == NULL) return; //Árvore vazia retorna 0

    if (raiz->chave > min)     // Se a chave atual for maior que o mínimo do intervalo
        imprimirIntervalo(raiz->esq, min, max); //Percorre a subárvore esquerda

    if (raiz->chave >= min && raiz->chave <= max) //Se a chave estiver contida no intervalo
        for (int i = 0; i < raiz->contador; i++) // O loop itera sobre o contador para imprimir a chave o número de vezes que ela aparece
            printf("%d ", raiz->chave); //Imprime a chave

    if (raiz->chave < max) // Se a chave atual for menor que o máximo do intervalo
        imprimirIntervalo(raiz->dir, min, max); //percorre a subárvore direita
}

PONT lowestCommonAncestor(PONT raiz, int val1, int val2) {
    if (buscar(raiz, val1) == NULL || buscar(raiz, val2) == NULL) // Verifica se ambas as chaves (val1 e val2) existem na árvore
        return NULL; //Retorna nulo se na estiver

    PONT current = raiz; // Inicializa um ponteiro para percorrer a árvore, começando pela raiz
    while (current != NULL) { // Percorre a árvore enquanto o nó atual não for NULL.
        if (val1 < current->chave && val2 < current->chave) // Se ambas as chaves forem menores que a chave atual
            current = current->esq; //LCA está na subárvore esquerda
        else if (val1 > current->chave && val2 > current->chave) // Se ambas as chaves forem maiores que a chave atual
            current = current->dir; //LCA está na subárvore direita
        else // Caso contrário
            return current; //O nó atual é o LCA
    }
    //Se o loop terminar sem encontrar o LCA
    return NULL; //Retorna NULL
}

int main() {
    PONT raiz;
    inicializar(&raiz);

    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 15);
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 18);

    printf("\n--- APÓS INSERIR (10,5,15,10,5,5,18) ---\n");
    printf("InOrder esperado: 5 5 5 10 10 15 18\n");
    printf("InOrder obtido:   ");
    exibirInOrder(raiz);
    printf("\n");

    PONT node5 = buscar(raiz, 5);
    if (node5)
        printf("\nBuscar(5): encontrado com contador=%d (esperado=3)\n", node5->contador);
    else
        printf("\nBuscar(5): não encontrado (inesperado)\n");

    PONT nodeX = buscar(raiz, 999);
    if (!nodeX)
        printf("Buscar(999): não encontrado (esperado)\n");
    else
        printf("Buscar(999): encontrado??? (inesperado)\n");

    raiz = removerUmaOcorrencia(raiz, 5);
    printf("\n--- APÓS removerUmaOcorrencia(5) ---\n");
    printf("Esperado InOrder: 5 5 10 10 15 18\n");
    printf("InOrder obtido:   ");
    exibirInOrder(raiz);
    printf("\n");

    node5 = buscar(raiz, 5);
    if (node5)
        printf("Agora contador(5)=%d (esperado=2)\n", node5->contador);

    raiz = removerTodasOcorrencias(raiz, 10);
    printf("\n--- APÓS removerTodasOcorrencias(10) ---\n");
    printf("Esperado InOrder: 5 5 15 18\n");
    printf("InOrder obtido:   ");
    exibirInOrder(raiz);
    printf("\n");

    int qtdNos = contarNos(raiz);
    int totalElem = contarTotalElementos(raiz);
    printf("\ncontarNos => %d (esperado=3)\n", qtdNos);
    printf("contarTotalElementos => %d (esperado=4)\n", totalElem);

    printf("\n--- Teste k-ésimo menor ---\n");
    printf("k=1 => %d (esperado=5)\n", kEsimoMenor(raiz, 1));
    printf("k=2 => %d (esperado=5)\n", kEsimoMenor(raiz, 2));
    printf("k=3 => %d (esperado=15)\n", kEsimoMenor(raiz, 3));
    printf("k=4 => %d (esperado=18)\n", kEsimoMenor(raiz, 4));
    printf("k=5 => %d (esperado=-1)\n", kEsimoMenor(raiz, 5));

    printf("\n--- Teste imprimirIntervalo [6..18] ---\n");
    printf("Esperado: 15 18\nObtido:   ");
    imprimirIntervalo(raiz, 6, 18);
    printf("\n");

    raiz = inserir(raiz, 12);
    raiz = inserir(raiz, 16);
    raiz = inserir(raiz, 3);

    printf("\n--- Árvore após inserir(12,16,3) ---\n");
    printf("InOrder esperado: 3 5 5 12 15 16 18\n");
    printf("Obtido:          ");
    exibirInOrder(raiz);
    printf("\n");

    PONT nLCA;

    nLCA = lowestCommonAncestor(raiz, 3, 5);
    if (nLCA)
        printf("\nLCA(3,5) => chave=%d (esperado=5)\n", nLCA->chave);

    nLCA = lowestCommonAncestor(raiz, 3, 12);
    if (nLCA)
        printf("LCA(3,12) => chave=%d (esperado=5)\n", nLCA->chave);

    nLCA = lowestCommonAncestor(raiz, 16, 18);
    if (nLCA)
        printf("LCA(16,18) => chave=%d (esperado=15) *Acredito que o nó esperado deveria ser 18*\n", nLCA->chave);

    nLCA = lowestCommonAncestor(raiz, 5, 18);
    if (nLCA)
        printf("LCA(5,18) => chave=%d (esperado=5) *Acredito que o nó esperado deveria ser 15*\n", nLCA->chave);

    nLCA = lowestCommonAncestor(raiz, 100, 3);
    if (!nLCA)
        printf("LCA(100,3) => NULL (esperado=chave nao existe)\n");

    printf("\n--- FIM DOS TESTES ---\n");

    return 0;
}