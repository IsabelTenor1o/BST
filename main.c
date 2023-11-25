#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
    //declarar e inicializar como árvore vazia
    /*arvore a = NULL;
    a = inserir(a, 18);
    a = inserir(a, 9);
    a = inserir(a, 24);
    a = inserir(a, 21);
    a = inserir(a, 99);
    a = inserir(a, 2);
    a = inserir(a, 7);
    a = inserir(a, 6);
*/
    //printf("PRE-ORDER: ");
    //preOrder(a);
    //printf("\nIN-ORDER: ");
    //inOrder(a);
    //printf("\nPOS-ORDER: ");
    //posOrder(a);
    //printf("\nREVERSO: ");
    //reverso(a);
    //printf("\n");
    //dobro(a);
    //int resultado = busca(a, 32);
    //printf("%d\n", resultado);
    //int alt = altura(a);
    //printf("Altura da árvore: %d\n", alt);

    void menu() {
    printf("\nDigite um numero\n");
    printf("1. Inserir elemento\n");
    printf("2. Mostrar arvore pre-order\n");
    printf("3. Mostrar arvore in-order\n");
    printf("4. Mostrar arvore pos-order\n");
    printf("5. Mostrar arvore reversa\n");
    printf("6. Mostrar a quantidade de elementos pares da arvore\n");
    printf("7. Exibir antecessor de um elemento da arvore\n");
    printf("8. Exibir pai de um elemento da arvore\n");
    printf("9. Remover elemento da arvore\n");
    printf("10. Exibir a soma de elementos pares da arvore\n");
    printf("11. Podar os elementos e seus filhos\n");
    printf("12. Exibe a arvore com o valor de seus nos dobrados\n");
    printf("13. Busca um elemento na arvore\n");
    printf("14. Mostrar os descendentes de um elemento\n");
    printf("15. Mostrar a altura de uma arvore\n");
    printf("99. Sair\n");
}

int main() {
    arvore raiz = NULL;
    int opcao;
    int valor;
    int pares;
    int soma;
    do {
        menu();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf("Digite o valor que deseja inserir: ");
                scanf("%d", &valor);
                raiz = inserir(raiz, valor);
                break;
            case 2:
                printf("Arvore pre-order: ");
                preOrder(raiz);
                printf("\n");
                break;
            case 3:
                printf("Arvore in-order: ");
                inOrder(raiz);
                printf("\n");
                break;
            case 4:
                printf("Arvore pos-order: ");
                posOrder(raiz);
                printf("\n");
                break;
            case 5:
                printf("Arvore reverso: ");
                reverso(raiz);
                printf("\n");
                break;
            case 6:
                pares = qtdPar(raiz);
                printf("%d\n", pares);
                break;
            case 7:
                scanf("%d", &valor);
                antecessor(raiz, valor);
                printf("\n");
                break;
            case 8:
                printf("Pai de um elemento na arvore: ");
                scanf("%d", &valor);
                pai(raiz, valor);
                printf("\n");
                break;
            case 9:
                printf("Digite um valor para ser removido: ");
                scanf("%d", &valor);
                //raiz = remover(raiz, valor);
                printf("\n");
                break;
            case 10:
                soma = somaPar(raiz);
                printf("%d\n", soma);
                break;
            case 11:
                podar(raiz, valor);
                printf("\n");
                break;
            case 12:
                printf("O dobro dos elementos da arvore: ");
                dobro(raiz);
                printf("\n");
                break;
            case 13:
                printf("Buscar um elemento da arvore: ");
                scanf("%d", &valor);
                busca(raiz, valor);
                printf("\n");
                break;
            case 14:
                scanf("%d", &valor);
                descendentes(raiz, valor);
                printf("\n");
                break;
            case 15:
                printf("Altura da arvore: %d\n", alturaArv(raiz));
                break;
            case 99:
                exit(0);
                break;
            default:
                printf("Opção invalida.\n");
        }
    } while (1);

}


