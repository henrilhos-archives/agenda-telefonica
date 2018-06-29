#ifndef TELA_PADRAO
  #include "telaPadrao.h"
#endif
#ifndef MENU
  #include "menu.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>

#define clear() printf("\033[H\033[J")
#define MAX_AGENDA 50

typedef struct {
	char nome[50];
	int idade;
} registro;

void criaContato(registro r[], int *tamanho) {
	int indice = *tamanho;

	printf("Entre o nome do contato: ");
	scanf("%s", r[indice].nome);

	printf("Entre a idade do contato: ");
	scanf("%d", &r[indice].idade);
	*tamanho = *tamanho + 1;

}

void listaContatos(registro r[], int *tamanho) {
	system("cls");
	int tam = *tamanho;
	printf("Lista de Contatos\n");
	printf("Nome\tIdade\n");

	for(int i = 0; i < tam; i++){
		printf("%s\t%d\n", r[i].nome, r[i].idade);
	}
}

void processaOpcao(int opcao, registro r[], int *tamanho) {
	switch(opcao) {
		case '1':
			criaContato(r, tamanho);
			break;
		case '2':
			break;
		case '3':
			break;
		case '4':
			listaContatos(r, tamanho);
			break;
		case '5':
			break;
		case 's':
			printf("Encerrando...\n");
			break;
		default:
			printf("Opção inválida!\n");
			break;
	}
}

int main() {
	FILE *arquivo;
	char *nome_arquivo = "agenda.bin";
	char op;

	registro agenda[MAX_AGENDA];

	int tamanho = 0;
	// lê o arquivo e carrega seu conteúdo para o vetor "agenda", se existir
	arquivo = fopen(nome_arquivo, "rb");
	if (arquivo != NULL) {
		fread(&tamanho, sizeof(int), 1, arquivo);
		fread(agenda, sizeof(registro), MAX_AGENDA, arquivo);
		fclose(arquivo);
	} else {
		printf("Sem arquivo!");
	}

	do {
		system("cls"); // limpa a tela - multiplataforma

		printf("%d", tamanho);

		imprimeMenu();
		gotoxy(9, 16);
		op = tolower(getchar());
		processaOpcao(op, agenda, &tamanho);
		fflush(stdin); // limpa o buffer do teclado (para remover lixos)
		getchar();
		getchar();
	} while (op != 's');

	// grava o arquivo, com o conteúdo do vetor, ao sair
	arquivo = fopen(nome_arquivo, "wb");
	fwrite(&tamanho, sizeof(int), 1, arquivo);
	fwrite(agenda, sizeof(registro), MAX_AGENDA, arquivo);
	fclose(arquivo);

	return 0;
}
