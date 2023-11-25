#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

arvore inserir (arvore raiz, int valor){
    //caso base
    //caso a arvore esteja vazia, o novo valor é a raíz
    if(raiz == NULL) {
        //alocar espaço em memória
        arvore nova = (arvore) malloc(sizeof(struct no));
        //inicializar o novo nó
        //add o numero a variavel de valor
        nova->valor = valor;
        //aponta o ponteiro esquerdo e direito pra null já que é único
        nova->esq = NULL;
        nova->dir = NULL;
        //retornar o ponteiro para a raiz (relativa) da nova árvore
        return nova;
    }
    //caso nao seja o primeiro nó da arvore
    else {
        if(valor > raiz-> valor) {
            raiz-> dir = inserir(raiz-> dir, valor);
        } else {
            raiz-> esq = inserir(raiz-> esq, valor);
        }
        return raiz;
    }
}
void preOrder(arvore raiz){
    //caso indutivo
    if(raiz != NULL) {
        //pre-order: processa raiz, depois esq e direita
        printf("[%d]", raiz-> valor);

        //chamadas recursivas
        preOrder(raiz->esq);
        preOrder(raiz->dir);
    }

    //caso base, fim da recursão
    else {
        //nao imprime nada, esta vazia
    }
}

void inOrder(arvore raiz){
    if(raiz != NULL) {
        inOrder(raiz-> esq);
        printf("[%d]", raiz-> valor);
        inOrder(raiz-> dir);
    }

}

void posOrder(arvore raiz) {
    if(raiz != NULL) {
        posOrder(raiz-> esq);
        posOrder(raiz-> dir);
        printf("[%d]", raiz-> valor);
    }
}

void reverso(arvore raiz){
    if(raiz != NULL) {
        //subárvore direita do nó raiz, primeiro os nós com valores maiores
        reverso(raiz-> dir);
        //imprime ate chegar no null
        printf("[%d]", raiz-> valor);
        //passa pra esquerda, valores menores
        reverso(raiz-> esq);
    }
}

int qtdPar(arvore raiz) {
   //se a raiz for nula nao tem elementos na arvore
    if(raiz == NULL) {
        return 0;
    }
        //Verifica se o valor do nó é par
        int pares = 0;
        if(raiz-> valor % 2 == 0){
            //if true add 1 ao qtd de pares
            pares++;
        }
        pares += qtdPar(raiz-> esq);
        pares += qtdPar(raiz-> dir);
        return pares;
}

int somaPar(arvore raiz) {
   //se a raiz for nula nao tem elementos na arvore
    if(raiz == NULL) {
        return 0;
    }
        //Verifica se o valor do nó é par
        int pares = 0;
        if(raiz-> valor % 2 == 0){
            //if true soma aos pares
            pares+= raiz-> valor;
        }
        //recursivamente chama a funcão q realiza a soma primeiro pro lado esquerdo
        //depois pro direito
        pares += somaPar(raiz-> esq);
        pares += somaPar(raiz-> dir);
        return pares;
}

void dobro(arvore raiz){
    if (raiz == NULL){
        return 0;
    }
    if(raiz != NULL) {
        int duasVezes = raiz-> valor * 2;
        dobro(raiz-> esq);
        printf("[%d]", duasVezes);
        dobro(raiz-> dir);
    }
}

arvore busca(arvore raiz, int valor) {
    if(raiz == NULL) {
        // Valor não encontrado
        return 0;
    } else if(raiz-> valor == valor) {
        // Valor encontrado
        return 1;
    } else if(valor > raiz-> valor) {
        // Valor é maior que o valor do nó atual, então procuramos na subárvore direita
        return busca(raiz-> dir, valor);
    } else {
        // Valor é menor que o valor do nó atual, então procuramos na subárvore esquerda
        return busca(raiz-> esq, valor);
    }
}
int maximo(int a, int b) {
    if(a > b) {
        return a;
    } else {
        return b;
    }
}

int alturaArv(arvore raiz) {
    if (raiz != NULL) {
        int alturaDir = alturaArv(raiz-> dir);
        int alturaEsq = alturaArv(raiz-> esq);
        return 1 + maximo(alturaEsq, alturaDir);
    } else {
        return 0;
    }
}


/*arvore remover(arvore raiz, int valor) {
    // Se a raiz for NULL, a função retorna NULL
    if(raiz == NULL) {
        return raiz;
    } else {
        // Se o valor for maior que o valor do nó raiz, a função chama a si mesma para a subárvore direita
        if(valor > raiz-> valor) {
            raiz-> dir = remover(raiz-> dir, valor);
        }
        // Se o valor for menor que o valor do nó raiz, a função chama a si mesma para a subárvore esquerda
        else if(valor < raiz-> valor) {
            raiz-> esq = remover(raiz-> esq, valor);
        }
        // Se o valor for igual ao valor do nó raiz, o nó é removido
        else {
            // Se o nó não tiver filhos, ele é removido diretamente
            if(raiz-> esq == NULL && raiz-> dir == NULL) {
                free(raiz);
                return NULL;
            }
            // Se o nó tiver apenas um filho à esquerda, o filho à esquerda substitui o nó
            if(raiz-> esq != NULL && raiz-> dir == NULL) {
                arvore aux = raiz-> esq;
                free(raiz);
                return aux;
            }
            // Se o nó tiver apenas um filho à direita, o filho à direita substitui o nó
            if(raiz-> esq == NULL && raiz-> dir != NULL) {
                arvore aux = raiz-> dir;
                free(raiz);
                return aux;
            }
            //Se o nó tiver dois filhos, o maior valor da subárvore esquerda substitui o nó
            int maiorValorSubarvoreEsquerda = maior(raiz-> esq)-> valor;
            raiz-> valor = maiorValorSubarvoreEsquerda;
            raiz-> esq = remover(raiz-> esq, maiorValorSubarvoreEsquerda);
            return raiz;
        }
    }
}

arvore maior(arvore raiz) {
    if(raiz == NULL) {
        printf("Raiz vazia");
        return -1;
    } else {
        if(raiz->dir != NULL) {
            maior(raiz->dir);
        }
        if(raiz->dir == NULL) {
            return raiz;
        }
    }
}
*/
arvore podar(arvore raiz, int valor) {
    if (raiz != NULL) {
        if (raiz-> valor == valor) {
            free(raiz);
            return NULL;
        } else {
            if (valor > raiz-> valor) {
                raiz-> dir = podar(raiz-> dir, valor);
            } else {
                raiz-> esq = podar(raiz-> esq, valor);
            }
        }
        return raiz;
    } else {
        return NULL;
    }
}

void descendentes(arvore raiz, int valor) {
    if (raiz != NULL) {
        if (valor == raiz-> valor) {
            inOrder(raiz-> esq);
            inOrder(raiz-> dir);
        } else if (valor > raiz-> valor) {
            descendentes(raiz-> dir, valor);
        } else {
            descendentes(raiz-> esq, valor);
        }
    }
}

arvore antecessor(arvore raiz, int valor) {
    if (raiz != NULL) {
        if(raiz-> valor == valor) {
            return raiz;
        }
        if(raiz-> dir != NULL && raiz-> dir-> valor == valor) {
            printf("%d", raiz-> valor);
            return raiz;
        }
        if(raiz-> esq != NULL && raiz-> esq-> valor == valor) {
            arvore filha = raiz->esq;
            printf("O antecessor do valor e: %d", filha-> esq-> valor);
            return filha;
        } else {
            if(valor > raiz-> valor) {
                antecessor(raiz-> dir, valor);
            } else {
                antecessor(raiz-> esq, valor);
            }
        }
    } else {
        return NULL;
    }
}

arvore pai(arvore raiz, int valor) {
    if (raiz != NULL) {
        if (raiz-> valor == valor) {
            printf("Nao tem pai\n");
            return -1;
        }

        if (raiz-> dir != NULL && raiz-> dir-> valor == valor) {
            printf("[%d]\n", raiz-> valor);
            return raiz;
        }

        if (raiz-> esq != NULL && raiz-> esq-> valor == valor) {
            printf("[%d]\n", raiz-> valor);
            return raiz;
        } else {
            if (valor > raiz-> valor) {
                return pai(raiz-> dir, valor);
            } else {
                return pai(raiz-> esq, valor);
            }
        }
    } else {
        return -1;
    }
}
