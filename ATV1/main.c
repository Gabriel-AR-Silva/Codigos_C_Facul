#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() { 
	setlocale(LC_ALL, "");

	float valorInvestido = 0; 
	int periodo = 0;
	float percentualRendimento = 0;

	printf("Digite o valor investido: \n");
	scanf("%f", &valorInvestido);
	printf("Digite a quantidade de meses do investimento: \n");
	scanf("%d", &periodo);
	printf("Digite o percentual de rendimento ao mˆs: \n");
	scanf("%f", &percentualRendimento);

	printf("\n\n");

	float valorInicialRendimento = valorInvestido;

	for (int i = 1; i <= periodo; i++) {
		valorInvestido *= 1 + percentualRendimento;
		printf("Depois do mˆs %d ter  = %.3f \n", i, valorInvestido);
	}

	float saldoParaRetirada = valorInicialRendimento + (( valorInvestido - valorInicialRendimento ) * 0.85);

	printf("\n\nValor do saldo final = %.3f \n", valorInvestido);
	printf("Valor do saldo para retirada ap¢s imposto sobre rendimento = %.2f \n\n", saldoParaRetirada);
	
	return 0;
}
