#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>

#define LINHAS 24
#define COLUNAS 14

#define TELA_PADRAO 1

void gotoxy(short col, short row);
void desenharTela(short altura, short largura, short x, short y);
void desenharLinha(short linha, short largura, short x, short y);
void desenharTelaComTitulo(short altura, short largura, short x, short y, char* titulo);

char _conteudo[LINHAS][COLUNAS] = {
  {201, 205, 187},
  {186,  32, 186},
  {204, 205, 185},
  {200, 205, 188}
};

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
