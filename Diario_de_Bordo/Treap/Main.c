#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int conteudo;
    int prioridade;
    struct No *esq, *dir;
} No;

// Fnução para criar um novo no
No* criarNo(int conteudo) {
    No* node = (No*)malloc(sizeof(No));
    node->conteudo = conteudo;
    node->prioridade = rand() % 100; // Gerando um valor de prioridade aleatória
    node->esq = node->dir = NULL;
    return node;
}

// Rotação para a direita
No* rotacaoRR(No* y) {
    No* x = y->esq;
    No* T2 = x->dir;
    x->dir = y;
    y->esq = T2;
    return x;
}

// Rotação para a esquerda
No* rotacaoLL(No* x) {
    No* y = x->dir;
    No* T2 = y->esq;
    y->esq = x;
    x->dir = T2;
    return y;
}

// Função para inserir No
No* inserir(No* root, int conteudo) {
    if (!root)
        return criarNo(conteudo);

    if (conteudo <= root->conteudo) {
        root->esq = inserir(root->esq, conteudo);
        if (root->esq->prioridade > root->prioridade)
            root = rotacaoRR(root);
    } else {
        root->dir = inserir(root->dir, conteudo);
        if (root->dir->prioridade > root->prioridade)
            root = rotacaoLL(root);
    }
    return root;
}

// Funçao para excluir um NO
No* removerNo(No* root, int conteudo) {
    if (!root)
        return root;

    if (conteudo < root->conteudo)
        root->esq = removerNo(root->esq, conteudo);
    else if (conteudo > root->conteudo)
        root->dir = removerNo(root->dir, conteudo);
    else {
        if (!root->esq) {
            No* temp = root->dir;
            free(root);
            root = temp;
        } else if (!root->dir) {
            No* temp = root->esq;
            free(root);
            root = temp;
        } else if (root->esq->prioridade < root->dir->prioridade) {
            root = rotacaoLL(root);
            root->esq = removerNo(root->esq, conteudo);
        } else {
            root = rotacaoRR(root);
            root->dir = removerNo(root->dir, conteudo);
        }
    }
    return root;
}

int main() {
    No* raiz = NULL;
    raiz = inserir(raiz, 0);

    
    return 0;
}
