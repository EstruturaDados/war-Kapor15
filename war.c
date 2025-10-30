#include <stdio.h>
#include <string.h>

struct Territorio {
    char nome[30];  // Nome do território
    char cor[10];   // Cor do exército
    int tropas;     // Quantidade de tropas
};

int main() {
    struct Territorio territorios[5];
    int i;

    // Cadastro dos territórios
    for(i = 0; i < 5; i++) {
        printf("Cadastro do territorio %d:\n", i + 1);

        printf("Nome: ");
        scanf(" %[^\n]s", territorios[i].nome); 

        printf("Cor do exercito: ");
        scanf(" %s", territorios[i].cor); 

        printf("Quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas); 

        printf("\n");
    }

    // Mostrar dados cadastrados
    printf("--- Territorios cadastrados ---\n");
    for(i = 0; i < 5; i++) {
        printf("Territorio %d:\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do exercito: %s\n", territorios[i].cor);
        printf("Tropas: %d\n\n", territorios[i].tropas);
    }

    return 0;
}
