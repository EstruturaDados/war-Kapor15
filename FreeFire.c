#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Item {
    char nome[30];
    int peso;
};

struct Item mochila[10];
int totalItens = 0;
int pesoAtual = 0;
int limiteMochila = 10;

void buscarItem() {
    int escolha;
    printf("\n=== Buscar Item ===\n");
    printf("1 - AK47 (peso 5)\n");
    printf("2 - Bandagem (peso 3)\n");
    printf("3 - Municao (peso 2)\n");
    printf("Escolha o item: ");
    scanf("%d", &escolha);

    int chance = rand() % 100;

    if (chance < 50) {
        printf("\nVocê procurou e nao encontrou nada...\n");
        return;
    }

    struct Item novoItem;

    switch (escolha) {
        case 1:
            strcpy(novoItem.nome, "AK47");
            novoItem.peso = 5;
            break;
        case 2:
            strcpy(novoItem.nome, "Bandagem");
            novoItem.peso = 3;
            break;
        case 3:
            strcpy(novoItem.nome, "Municao");
            novoItem.peso = 2;
            break;
        default:
            printf("Opcao invalida.\n");
            return;
    }

    if (pesoAtual + novoItem.peso > limiteMochila) {
        printf("\nA mochila esta cheia, voce nao consegue carregar esse item!\n");
        return;
    }

    mochila[totalItens] = novoItem;
    totalItens++;
    pesoAtual += novoItem.peso;

    printf("\nParabens! Voce encontrou uma %s!\n", novoItem.nome);
}

void verMochila() {
    if (totalItens == 0) {
        printf("\nMochila vazia!\n");
        return;
    }

    printf("\n=== Mochila ===\n");
    for (int i = 0; i < totalItens; i++) {
        printf("%d - %s (peso %d)\n", i + 1, mochila[i].nome, mochila[i].peso);
    }

    int opcao;
    printf("\nDeseja remover algum item?\n1 - Sim\n2 - Nao\nOpcao: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        int escolha;
        printf("\nDigite o numero do item para remover: ");
        scanf("%d", &escolha);

        if (escolha < 1 || escolha > totalItens) {
            printf("Opcao invalida!\n");
            return;
        }

        pesoAtual -= mochila[escolha - 1].peso;

        for (int i = escolha - 1; i < totalItens - 1; i++) {
            mochila[i] = mochila[i + 1];
        }
        totalItens--;

        printf("\nItem removido!\n");
    }
}

int main() {
    srand(time(NULL));

    int opcao;

    while (1) {
        printf("\n=== MENU ===\n");
        printf("1 - Buscar item\n");
        printf("2 - Ver mochila\n");
        printf("3 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: buscarItem(); break;
            case 2: verMochila(); break;
            case 3: printf("\nSaindo...\n"); return 0;
            default: printf("Opcao invalida!\n");
        }
    }
}

