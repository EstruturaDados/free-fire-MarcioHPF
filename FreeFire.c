#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITENS 10

// Estrutura que representa um item do inventário
struct Item {
    char nome[30];
    char tipo[20];
    int quantidade;
};

// Funções do sistema
void inserirItem(struct Item mochila[], int *qtd);
void removerItem(struct Item mochila[], int *qtd);
void listarItens(struct Item mochila[], int qtd);
void buscarItem(struct Item mochila[], int qtd);

int main() {
    struct Item mochila[MAX_ITENS];  // Vetor que armazena até 10 itens
    int qtd = 0;                     // Quantidade atual de itens
    int opcao;

    do {
        printf("\n=== SISTEMA DE INVENTÁRIO ===\n");
        printf("1 - Inserir item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Buscar item\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do teclado

        switch (opcao) {
            case 1:
                inserirItem(mochila, &qtd);
                break;
            case 2:
                removerItem(mochila, &qtd);
                break;
            case 3:
                listarItens(mochila, qtd);
                break;
            case 4:
                buscarItem(mochila, qtd);
                break;
            case 0:
                printf("Encerrando o sistema...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}

/* Função responsável por cadastrar um novo item na mochila */
void inserirItem(struct Item mochila[], int *qtd) {
    if (*qtd >= MAX_ITENS) {
        printf("A mochila está cheia! Não é possível adicionar mais itens.\n");
        return;
    }

    printf("\n=== Inserir novo item ===\n");
    printf("Nome do item: ");
    scanf(" %29[^\n]", mochila[*qtd].nome);

    printf("Tipo (arma, munição, cura...): ");
    scanf(" %19[^\n]", mochila[*qtd].tipo);

    printf("Quantidade: ");
    scanf("%d", &mochila[*qtd].quantidade);

    (*qtd)++;
    printf("Item adicionado com sucesso!\n");

    listarItens(mochila, *qtd);
}

/* Função que remove um item da mochila com base no nome */
void removerItem(struct Item mochila[], int *qtd) {
    if (*qtd == 0) {
        printf("A mochila está vazia! Nenhum item para remover.\n");
        return;
    }

    char nomeBusca[30];
    printf("\n=== Remover item ===\n");
    printf("Digite o nome do item que deseja remover: ");
    scanf(" %29[^\n]", nomeBusca);

    int i, encontrado = 0;
    for (i = 0; i < *qtd; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            encontrado = 1;
            // Move os itens seguintes uma posição para trás
            for (int j = i; j < *qtd - 1; j++) {
                mochila[j] = mochila[j + 1];
            }
            (*qtd)--;
            printf("Item '%s' removido com sucesso!\n", nomeBusca);
            break;
        }
    }

    if (!encontrado)
        printf("Item não encontrado na mochila.\n");

    listarItens(mochila, *qtd);
}

/* Função que lista todos os itens cadastrados */
void listarItens(struct Item mochila[], int qtd) {
    printf("\n=== Itens na mochila ===\n");
    if (qtd == 0) {
        printf("Nenhum item cadastrado.\n");
        return;
    }

    for (int i = 0; i < qtd; i++) {
        printf("=================================");
        printf("\nItem %d:\n", i + 1);
        printf("Nome: %s\n", mochila[i].nome);
        printf("Tipo: %s\n", mochila[i].tipo);
        printf("Quantidade: %d\n", mochila[i].quantidade);
        printf("=================================");
    }
}

/* Função de busca sequencial por nome */
void buscarItem(struct Item mochila[], int qtd) {
    if (qtd == 0) {
        printf("A mochila está vazia! Nenhum item para buscar.\n");
        return;
    }

    char nomeBusca[30];
    printf("\n=== Buscar item ===\n");
    printf("Digite o nome do item que deseja procurar: ");
    scanf(" %29[^\n]", nomeBusca);

    int encontrado = 0;
    for (int i = 0; i < qtd; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            printf("\nItem encontrado!\n");
            printf("Nome: %s\n", mochila[i].nome);
            printf("Tipo: %s\n", mochila[i].tipo);
            printf("Quantidade: %d\n", mochila[i].quantidade);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
        printf("Item não encontrado.\n");
}


int main() {
    return 0;
}

