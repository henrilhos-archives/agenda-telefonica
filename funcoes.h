#ifndef __FUNCOES_H_
  #define __FUNCOES_H_

  #include <stdio.h>
  #include <stdlib.h>
  #include <ctype.h>
  #include <windows.h>

  #define MAX_AGENDA 50
  #define LINHAS 24
  #define COLUNAS 14

  typedef struct {
    int id;
    int active;
  	char name[30];
  	char phone[15];
  } registro;

  void imprimeMenu();
  void processaOpcao(int opcao, registro r[], int *tamanho);
  void criaContato(registro r[], int *tamanho);
  void removeContato(registro r[], int *tamanho);
  void pesquisaContato(registro r[], int *tamanho);
  void listaContatos(registro r[], int *tamanho);
  void editaContato(registro r[], int *tamanho);
  void gotoxy(short col, short row);
  void desenharTela(short altura, short largura, short x, short y);
  void desenharLinha(short linha, short largura, short x, short y);
  void desenharTelaComTitulo(short altura, short largura, short x, short y, char* titulo);
#endif
