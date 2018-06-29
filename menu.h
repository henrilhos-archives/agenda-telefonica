#ifndef TELA_PADRAO
  #include "telaPadrao.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>

#define MENU 1

void imprimeMenu();

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
