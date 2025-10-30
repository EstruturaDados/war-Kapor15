#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FILA 5 


typedef struct {
    char tipo;  
    int id;    
} Peca;

// Fila circular
Peca fila[MAX_FILA];
int frente = 0;     
int tras = 0;       
int quantidade = 0; 
int contadorId = 0; 


char gerarTipoPeca() {
    char tipos[] = {'I', 'O', 'T', 'L'};
    return tipos[rand() % 4];
}


Peca gerarPeca() {
    Peca nova;
    nova.tipo = gerarTipoPeca();
    nova.id = contadorId++;
    return nova;
}


void inserirPeca(Peca p) {
    if (quantidade == MAX_FILA) {
        printf("Fila cheia! Nao é possivel inserir nova peca.\n");
        return;
    }
    fila[tras] = p;
    tras = (tras + 1) % MAX_FILA;
    quantidade++;
    printf("Peca [%c %d] inserida na fila!\n", p.tipo, p.id);
}


void jogarPeca() {
    if (quantidade == 0) {
        printf("Fila vazia! Nenhuma peca para jogar.\n");
        return;
    }
    printf("Peca jogada: [%c %d]\n", fila[frente].tipo, fila[frente].id);
    frente = (frente + 1) % MAX_FILA;
    quantidade--;
}


void mostrarFila() {
    if (quantidade == 0) {
        printf("Fila vazia!\n");
        return;
    }
    printf("Fila de pecas:\n");
    for (int i = 0; i < quantidade; i++) {
        int idx = (frente + i) % MAX_FILA;
        printf("[%c %d] ", fila[idx].tipo, fila[idx].id);
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); 

    
    for (int i = 0; i < MAX_FILA; i++) {
        inserirPeca(gerarPeca());
    }

    int opcao;
    do {
        printf("\n==== Tetris Stack - Fila de Pecas ====\n");
        mostrarFila();
        printf("1 - Jogar peca\n2 - Inserir nova peca\n0 - Sair\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            jogarPeca();
        } else if (opcao == 2) {
            Peca nova = gerarPeca();
            printf("Nova peca gerada: [%c %d]\n", nova.tipo, nova.id);
            inserirPeca(nova);
        } else if (opcao != 0) {
            printf("Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);

    printf("Jogo encerrado!\n");
    return 0;
}
