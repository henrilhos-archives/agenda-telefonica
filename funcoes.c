#include "funcoes.h"

char _conteudo[LINHAS][COLUNAS] = {
  {201, 205, 187},
  {186,  32, 186},
  {204, 205, 185},
  {200, 205, 188}
};

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

void imprimeMenu() {
  system("cls");
  desenharTelaComTitulo(10, 50, 5, 5, "Agenda Eletronica");

  gotoxy(8, 9);
  printf("1 - Criar Contato");
  gotoxy(8, 10);
  printf("2 - Remover Contato");
  gotoxy(8, 11);
  printf("3 - Pesquisar Contato");
  gotoxy(8, 12);
  printf("4 - Listar Contato");
  gotoxy(8, 13);
  printf("5 - Editar Contato");
  gotoxy(8, 14);
  printf("S - Sair");

  gotoxy(7, 16);
	printf("[   ] Escolha uma opcao");
}

void criaContato(registro r[], int *tamanho) {
  int indice = *tamanho;

  system("cls");
  desenharTelaComTitulo(10, 50, 5, 5, "Criar Contato");

  gotoxy(8, 9);
  printf("ID do contato: %d", indice);
  gotoxy(8, 10);
	printf("Nome: [                                ]");
	gotoxy(8, 11);
  printf("Fone: [             ]");

  gotoxy(16, 10);
  scanf("%s", r[indice].nome);
  gotoxy(16, 11);
	scanf("%f", &r[indice].fone);
  r[indice].id = indice;

	*tamanho = *tamanho + 1;
}

void listaContatos(registro r[], int *tamanho) {
  int tam = *tamanho;

  system("cls");
	printf("Lista de Contatos\n");
	printf("ID\tNome\tFone\n");

	for(int i = 0; i < tam; i++){
		printf("%d\t%s\t%.0f\n", r[i].id, r[i].nome, r[i].fone);
	}

  printf("\nAperte Enter para continuar...");
  getch();
}

void desenharTelaComTitulo(short altura, short largura, short x, short y, char* titulo) {
  desenharTela(altura, largura, x, y);
  gotoxy(x + 2, y + 1);
  printf("%s", titulo);
}

void desenharLinha(short linha, short largura, short x, short y) {
  int i = 0;

  gotoxy(x, y);
  printf("%c", _conteudo[linha][0]);

  for (i = 0; i < largura; i++) {
    printf("%c", _conteudo[linha][1]);
  }

  printf("%c", _conteudo[linha][2]);
}

void desenharTela(short altura, short largura, short x, short y) {
  int i = 0;

  desenharLinha(0, largura, x, y++);
  desenharLinha(1, largura, x, y++);
  desenharLinha(2, largura, x, y++);

  for (i = 0; i < altura; i++) {
    desenharLinha(1, largura, x, y++);
  }

  desenharLinha(2 ,largura, x, y++ );
  desenharLinha(1, largura, x, y++ );
  desenharLinha(3, largura, x, y++ );
}

void gotoxy(short x, short y) {
  COORD pos = {x, y};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
