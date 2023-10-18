#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h> 
#include <stdbool.h>

typedef struct {
    char nome;
    double CPF;
    int tipoAtendimento;
} Objeto;

int Menu(char *tipoMenu);  

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int capacidadeAtendimento = 1000, quantidadeAtendimento = 0, actionMenuChosen = 0;

    actionMenuChosen = Menu("Default");  

    if (actionMenuChosen == 1) { actionMenuChosen = Menu("setorAtendimento"); }
    if (actionMenuChosen == 2) { Listar(); }
    if (actionMenuChosen == 3) { Listar(); }


    // Objeto * agendados = (Objeto *)malloc(capacidadeAtendimento * sizeof(Objeto));

    // if (agendados == NULL) {
    //     printf("Erro ao alocar memória.\n");
    //     return 1;
    // }

    // // Pede ao usuário para adicionar um objeto
    printf("Chosen action: %d", actionMenuChosen);
    // scanf("%d", &agendados[quantidadeAtendimento].nome);

    // printf("Digite seu CPF: ");
    // scanf("%lf", &agendados[quantidadeAtendimento].CPF);

    // quantidadeAtendimento++;

    // // Libera a memória alocada para o array de objetos
    // free(quantidadeAtendimento);

    return 0;
}

int Menu(char *tipoMenu)  
{
    int MenuAction = 0;
    bool MenuVerify = false;

    do {
        system("cls");

        if (tipoMenu == "setorAtendimento") {  
            printf("\n ------------ Qual setor de atendimento que deseja ser atendido? ------------ \n\n"
                "ATENÇÃO: O usuário deve digitar um número entre 1 a 4 referente às ações do menu. \n\n"
                "1 - Abertura de Conta\n"
                "2 - Caixa\n"
                "3 - Gerente Pessoa Física\n"
                "4 - Gerente Pessoa Jurídica\n\n"
                "Escolha uma opção: ");
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

void Listar()  
{
    printf("Listando");
}
