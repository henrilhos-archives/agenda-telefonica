#include "funcoes.h"

int main() {
	FILE *arquivo;
	char *nome_arquivo = "agenda.bin";
	char option;

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
		option = tolower(getchar());
		processaOpcao(option, agenda, &tamanho);
		fflush(stdin); // limpa o buffer do teclado (para remover lixos)
	} while (option != 's');

	// grava o arquivo, com o conteúdo do vetor, ao sair
	arquivo = fopen(nome_arquivo, "wb");
	fwrite(&tamanho, sizeof(int), 1, arquivo);
	fwrite(agenda, sizeof(registro), MAX_AGENDA, arquivo);
	fclose(arquivo);
	system("cls");

	return 0;
}
