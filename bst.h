#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

typedef struct no {
    int valor;
    struct no *esq;
    struct no *dir;
} no;
typedef no* arvore;

//funções

arvore inserir(arvore raiz, int valor);

void preOrder(arvore raiz);

void inOrder(arvore raiz);

void posOrder(arvore raiz);

void reverso(arvore raiz);

int qtdPar(arvore raiz);

arvore ant(arvore raiz, int valor);

arvore pai(arvore raiz, int valor);

arvore remover(arvore raiz, int valor);

int somaPar(arvore raiz);

arvore podar(arvore raiz, int valor);

void dobro(arvore raiz);

arvore busca(arvore raiz, int valor);

void descendentes(arvore raiz, int valor);

int alturaArv(arvore raiz);

#endif
