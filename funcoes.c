#include "funcoes.h"

char _conteudo[LINHAS][COLUNAS] = {
  {201, 205, 187},
  {186,  32, 186},
  {204, 205, 185},
  {200, 205, 188}
};

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
void processaOpcao(int opcao, registro r[], int *tamanho) {
	switch(opcao) {
		case '1':
			criaContato(r, tamanho);
			break;
		case '2':
      removeContato(r, tamanho);
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
void criaContato(registro r[], int *tamanho) {
  int tam = *tamanho;
  int id = 99;

  for (int i = 0; i < tam; i++) {
    if (r[i].active == 0) {
      id = i;
      break;
    }
  }

  if (id == 99) {
    id = tam;
  }

  system("cls");
  desenharTelaComTitulo(10, 50, 5, 5, "Criar Contato");

  gotoxy(8, 9);
  printf("ID do contato: %d", id);
  gotoxy(8, 10);
	printf("Nome: [                                ]");
	gotoxy(8, 11);
  printf("Fone: [             ]");

  gotoxy(16, 10);
  scanf("%s", r[id].name);
  gotoxy(16, 11);
	scanf("%f", &r[id].phone);
  r[id].id = id;
  r[id].active = 1;

	*tamanho = *tamanho + 1;
}
void removeContato(registro r[], int *tamanho) {
  int tam = *tamanho;
  int id;
  int excl;

  system("cls");
  desenharTelaComTitulo(10, 50, 5, 5, "Remover Contato");

  gotoxy(8, 9);
  printf("ID do contato: [    ]");

  gotoxy(25, 9);
  scanf("%d", &id);

  for (int i = 0; i < tam; i++) {
    if (r[i].id == id) {
      if (r[i].active == 1) {
        r[i].active = 0;
        excl = 1;
        break;
      }
    }
  }

  system("cls");
  desenharTelaComTitulo(10, 50, 5, 5, "Remover Contato");

  if (excl == 1) {
    gotoxy(8, 9);
    printf("Usuario removido com sucesso.");
    gotoxy(8, 11);
    printf("Aperte Enter para continuar...");
  } else {
    gotoxy(8, 9);
    printf("Algo de errado aconteceu.");
    gotoxy(8, 11);
    printf("Aperte Enter para continuar...");
  }

  getch();
}
void listaContatos(registro r[], int *tamanho) {
  int tam = *tamanho;
  int altura = 0;
  int posit = 1;

  for (int i = 0; i < tam; i++) {
    if (r[i].active == 1) {
      altura++;
    }
  }

  system("cls");
  desenharTelaComTitulo(altura + 4, 50, 5, 5, "Lista de Contatos");

  gotoxy(8, 9);
	printf("ID");
  gotoxy(12, 9);
  printf("Nome");
  gotoxy(40, 9);
  printf("Fone");

  for (int i = 0; i < tam; i++) {
    if (r[i].active == 1) {
      gotoxy(8, posit + 10);
      printf("%d", r[i].id);
      gotoxy(12, posit + 10);
      printf("%s", r[i].name);
      gotoxy(40, posit + 10);
  		printf("%.0f", r[i].phone);

      posit++;
    }
  }

  getch();
}
void gotoxy(short x, short y) {
  COORD pos = {x, y};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
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
