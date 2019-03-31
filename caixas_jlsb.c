#include <stdio.h>
#include <stdlib.h>
 
int main (void) {
    int N, P, *vet, caixa, pilha, tam, esquerda, direita; // N = número de caixas e P = número de pilhas
     
    scanf ("%d %d", &N, &P);
    do{
        vet = malloc(P*sizeof(int)); // aloca espaço para um bloco de bytes consecutivos na memória RAM do computador e devolve o endereço desse bloco.O endereço devolvido por malloc é do tipo genérico  void *.   O programador armazena esse endereço num ponteiro de tipo apropriado.A fim de alocar espaço para um objeto que precisa de mais que 1 byte, convém usar o operador sizeof, que diz quantos bytes o objeto em questão tem, sizeof não é uma função mas um operador, tal como return, Os parênteses na expressão  sizeof (int) são necessários porque  int é um tipo-de-dados.  O operador sizeof também pode ser aplicado diretamente a uma variável:  se var é uma variável então  sizeof(var)  é o número de bytes ocupados por var. E P elementos inteiros pode ser alocado (e depois desalocado) durante a execução do programa
        for (int i = 0; i < P; i++) { // percorre até o numero de pilhas P
            scanf("%d", &vet[i]); //Cada linha contém um inteiro, indicando quantas caixas há na pilha i, vet[i] faz isso
            
            if(vet[i] == 0) break;
            
            for (int j = 0; j < vet[i]; j++) { // percorre pelo numero de caixas na pilha
                scanf("%d", &caixa); // Numero das caixas na pilha até encontrar a caixa 1 e cair na condição do if
                
                if (caixa == 1) {// só executa os de baixo se passar por aq
                    tam = j+1; // pega tamanho da pilha até a caixa desejada
                    pilha = i; // pega a posição da caixa
                }
            }
        }
        esquerda = vet[pilha] - tam;   // numero de caixas que estão acima
        direita = vet[pilha] - tam;    // numero de caixas que estão acima
        for (int a = pilha-1; vet[a] >= tam; a--){ //percorre as pilhas na posição
            esquerda += (vet[a] - tam + 1);    // numero de caixas retiradas na pilha
        }
        for (int b = pilha+1; vet[b] >= tam; b++){ 
            direita += (vet[b] - tam + 1);     // numero de caixas retiradas na pilha
        }
            printf("%d\n", (esquerda >= direita) ? direita : esquerda); //(condicional)  comando_se_for_verdadeiro : se_for_falso, print no menor

        scanf ("%d %d", &N, &P);
    }while (N!=0 || P!=0); // se for diferente dessa entrada ele sai do while liberando a memória no free
}
