/*
    CPF, primeiro número não aparece
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    char nome[105];
    char CPF[18];
    int tipoAtendimento;
} Objeto;

int main() {
    system("cls"); 
    setlocale(LC_ALL, "Portuguese");

    int capacidadeAtendimento = 1000, quantidadeAtendimento = 0, actionMenuChosen = 0;
    Objeto *agendados = (Objeto *)malloc(capacidadeAtendimento * sizeof(Objeto));

    if (agendados == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    while (actionMenuChosen != 4) {
        actionMenuChosen = Menu("Default", "");

        if (actionMenuChosen == 1) {
            printf("\n\n**** Opção - Registrar Atendimento ****\n\n");

            // Pede ao usuário para adicionar um objeto
            printf("Digite seu Nome: ");
            getchar(); // Consumir a quebra de linha deixada pelo fgets
            fgets(agendados[quantidadeAtendimento].nome, sizeof(agendados[quantidadeAtendimento].nome), stdin);

            printf("Digite seu CPF: ");
            getchar(); // Consumir a quebra de linha deixada pelo fgets
            fgets(agendados[quantidadeAtendimento].CPF, sizeof(agendados[quantidadeAtendimento].CPF), stdin);

            agendados[quantidadeAtendimento].tipoAtendimento = Menu("setorAtendimento", "Qual o setor de atendimento que você deseja ser atendido?");

            printf("%s", agendados[quantidadeAtendimento].CPF);

            quantidadeAtendimento++;

            printf("Atendimento registrado com sucesso !!!");

            printf("Pressione Enter para finalizar...");
            getchar(); 
        }

        if (actionMenuChosen == 2) {
            List(quantidadeAtendimento, agendados, false);
        }

        if (actionMenuChosen == 3) {
            List(quantidadeAtendimento, agendados, true);
        }

        system("cls"); 
    }
    // Libera a memória alocada para o array de objetos aqui, após o uso
    free(agendados);

    return 0;
}

int Menu(char *tipoMenu, char *tituloMenuAtendimento) {
    int MenuAction = 0;
    bool MenuVerify = false;

    do {
        if (strcmp(tipoMenu, "setorAtendimento") == 0) { // Use strcmp para comparar strings
            printf("\n ------------ %d ------------ \n\n"
                   "ATENÇÃO: O usuário deve digitar um número entre 1 a 4 referente às ações do menu. \n\n"
                   "1 - Abertura de Conta\n"
                   "2 - Caixa\n"
                   "3 - Gerente Pessoa Física\n"
                   "4 - Gerente Pessoa Jurídica\n\n"
                   "Escolha uma opção: ", tituloMenuAtendimento);
        } else {
            printf("\n ------------ Bem-vindo ao sistema de atendimento ------------ \n\n"
                   "ATENÇÃO: O usuário deve digitar um número entre 1 a 4 referente às ações do menu. \n\n"
                   "1 - Solicitar Atendimento\n"
                   "2 - Listar Atendimentos Registrados\n"
                   "3 - Listar Atendimento por Setor\n"
                   "4 - Sair\n\n"
                   "Escolha uma opção: ");
        }

        scanf("%d", &MenuAction);

        // 1 - Verifica se o valor recebido está de acordo com as ações do menu
        // 2 - Limpa o buffer de entrada caso o valor de entrada seja inválido
        MenuVerify = (MenuAction >= 1 && MenuAction <= 4) ? true : (getchar(), false);
    } while (!MenuVerify);

    return MenuAction;
}

void List(int quantidadeAtendimento, Objeto *agendados, bool porSetor) {
    printf("Listando\n\n");

    int actionMenuSectorChosen = Menu("setorAtendimento", "Escolha qual setor entre as opções abaixo você deseja listar");

    for (int i = 0; i < quantidadeAtendimento; i++) {
        if (porSetor) {
            if (agendados[i].tipoAtendimento == actionMenuSectorChosen) {
                RenderList(agendados, i);
            }
        } else {
            RenderList(agendados, i);
        }
    }

    printf("Pressione Enter para continuar...");
    getchar(); 
}

void RenderList(Objeto *agendados, int posicao) {

    printf("Nome: %s\n", agendados[posicao].nome);
    printf("CPF: %s\n", agendados[posicao].CPF);

    switch (agendados[posicao].tipoAtendimento) {
        case 1:
            printf("Tipo de atendimento: 1 - Abertura de Conta\n\n");
            break;
        case 2:
            printf("Tipo de atendimento: 2 - Caixa\n\n");
            break;
        case 3:
            printf("Tipo de atendimento: 3 - Gerente Pessoa Física\n\n");
            break;
        case 4:
            printf("Tipo de atendimento: 4 - Gerente Pessoa Jurídica\n\n");
            break;
        default:
            printf("!!! Erro ao imprimir o setor de atendimento !!!\n\n");
    }
}