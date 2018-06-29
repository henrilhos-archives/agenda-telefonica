#ifndef __FUNCOES_H_
  #define __FUNCOES_H_

  #include <stdio.h>
  #include <stdlib.h>
  #include <ctype.h>
  #include <windows.h>

  #define clear() printf("\033[H\033[J")
  #define MAX_AGENDA 50
  #define LINHAS 24
  #define COLUNAS 14

  typedef struct {
  	char nome[30];
  	float fone;
  } registro;

  void imprimeMenu();
  void criaContato(registro r[], int *tamanho);
  void listaContatos(registro r[], int *tamanho);
  void processaOpcao(int opcao, registro r[], int *tamanho);
  void gotoxy(short col, short row);
  void desenharTela(short altura, short largura, short x, short y);
  void desenharLinha(short linha, short largura, short x, short y);
  void desenharTelaComTitulo(short altura, short largura, short x, short y, char* titulo);
#endif
