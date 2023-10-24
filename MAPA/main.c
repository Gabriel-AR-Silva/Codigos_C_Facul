/*
    CPF, primeiro nÃºmero nÃ£o aparece
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <unistd.h> 
#include <stdbool.h>

typedef struct {
    char nome[105];
    char CPF[18];
    int tipoAtendimento;
} Objeto;

// protótipo das funções
int menu(char *tipoMenu, char *tituloMenuAtendimento);
void list(int quantidadeAtendimento, Objeto *agendados, bool porSetor);
void render(Objeto *agendados, int posicao);

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
        actionMenuChosen = menu("Default", " ");

        if (actionMenuChosen == 1) {
            printf("\n\n**** Opção - Registrar Atendimento ****\n\n");

            printf("Digite seu Nome: ");
            getchar(); 
            fgets(agendados[quantidadeAtendimento].nome, sizeof(agendados[quantidadeAtendimento].nome), stdin);

            printf("Digite seu CPF: ");
            getchar(); 
            fgets(agendados[quantidadeAtendimento].CPF, sizeof(agendados[quantidadeAtendimento].CPF), stdin);
            
            printf("\n");

            agendados[quantidadeAtendimento].tipoAtendimento = menu("setorAtendimento", "Qual o setor de atendimento que você deseja ser atendido?");

            quantidadeAtendimento++;

            printf("\n>>>>>>>> Atendimento registrado com sucesso !!!\n\n");
            sleep(3);  
        }

        if (actionMenuChosen == 2) { list(quantidadeAtendimento, agendados, false); }
        
        if (actionMenuChosen == 3) { list(quantidadeAtendimento, agendados, true); }

        system("cls"); 
    }
    
    printf("\n>>>>>>>> Obrigado por utilizar nosso sistema :) !!!\n\n");
    sleep(3);

    // Libera a memória
    free(agendados);

    return 0;
}

int menu(char *tipoMenu, char *tituloMenuAtendimento) {
    int MenuAction = 0;
    bool MenuVerify = false;

    do {
        if (strcmp(tipoMenu, "setorAtendimento") == 0) { 
            printf("\n ------------ %s ------------ \n\n"
                   "ATENÇÃO: O usuário deve digitar um número entre 1 a 4 referente as ações do menu. \n\n"
                   "1 - Abertura de Conta\n"
                   "2 - Caixa\n"
                   "3 - Gerente Pessoa Fisica\n"
                   "4 - Gerente Pessoa Jurídica\n\n"
                   "Escolha uma opção: ", tituloMenuAtendimento);
        } else {
            printf("\n ------------ Bem-vindo ao sistema de atendimento ------------ \n\n"
                   "ATENÇÃO: O usuário deve digitar um número entre 1 a 4 referente as ações do menu. \n\n"
                   "1 - Solicitar Atendimento\n"
                   "2 - Listar Atendimentos Registrados\n"
                   "3 - Listar Atendimento por Setor\n"
                   "4 - Sair\n\n"
                   "Escolha uma opção: ");
        }

        scanf("%d", &MenuAction);

        // 1 - Verifica se o valor recebido está de acordo com as opções do menu
        // 2 - Limpa o buffer de entrada caso o valor de entrada seja inválido
        MenuVerify = (MenuAction >= 1 && MenuAction <= 4) ? true : (getchar(), false);
    } while (!MenuVerify);

    return MenuAction;
}

void list(int quantidadeAtendimento, Objeto *agendados, bool porSetor) {
    int actionMenuSectorChosen = 0;
    
    if (quantidadeAtendimento > 0) {
    	if (porSetor) {
    		printf("\n\n**** Opção - Listar Atendimento por Setor ****\n");
    		actionMenuSectorChosen = menu("setorAtendimento", "Escolha qual setor entre as opções abaixo você deseja listar :)");
		} else {
			printf("\n\n**** Opção - Listar Atendimentos Registrados ****\n");
		}
		
    	for (int i=0; i<quantidadeAtendimento; i++) {
	        if (porSetor) {
	            if (agendados[i].tipoAtendimento == actionMenuSectorChosen) {
	                render(agendados, i);
	            } else {
	            	printf("\n\n ****** Ainda não há atedimentos registrados para esse setor :( ******\n\n");
				}
	        } else {
	            render(agendados, i);
	        }
    	}
	} else {
		printf("\n\n ****** Ainda não há atedimentos registrados :( ******\n\n");
	}

    system("pause");
}

void render(Objeto *agendados, int posicao) {
    printf("\n\nNome: %s", agendados[posicao].nome);
    printf("CPF: %s", agendados[posicao].CPF);

    switch (agendados[posicao].tipoAtendimento) {
        case 1:
            printf("Tipo de atendimento: 1 - Abertura de Conta\n\n");
            break;
        case 2:
            printf("Tipo de atendimento: 2 - Caixa\n\n");
            break;
        case 3:
            printf("Tipo de atendimento: 3 - Gerente Pessoa Fisica\n\n");
            break;
        case 4:
            printf("Tipo de atendimento: 4 - Gerente Pessoa Jurídica\n\n");
            break;
        default:
            printf("!!! Erro ao imprimir o setor de atendimento !!!\n\n");
    }

    printf("================================= \n\n");
}