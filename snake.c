#include <Windows.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int width = 20, height = 20, gameover, score, key;
int snakex, snakey, fruitx, fruity;

void print() // printing the boundry,snake,fruit and score
{
  Sleep(1);
  system("cls");
  int i, j;
  for (i = 0; i <= height; i++) {
    for (j = 0; j <= width; j++) {
      if (i == 0) {
        printf("|");
      } else if (i == height) {
        printf("|");
      } else if (j == 0) {
        printf("|");
      } else if (j == width) {
        printf("|");
      }

      else {
        if (i == snakex && j == snakey) {
          printf("i");
        } else if (i == fruitx && j == fruity) {
          printf("*");
        } else
          printf(" ");
      }
    }
    printf("\n");
  }
  printf("score = %d", score);
  printf("\n");
}

void game() // snake and fruit and snake cordination
{

  snakex = height / 2;
  snakey = width / 2;
label1:
  fruitx = rand() % 20;
  if (fruitx == 0)
    goto label1;
label2:
  fruity = rand() % 20;
  if (fruity == 0)
    goto label2;
  score = 0;
  gameover = 0;
}

void input() // to press the key to move the snake
{
  if (kbhit()) {
    switch (getch()) {
    case 'w':
      key = 1;
      break;
    case 's':
      key = 2;
      break;
    case 'a':
      key = 3;
      break;
    case 'd':
      key = 4;
      break;
    }
  }
}

void setting() // when pressed move and when snake eat friut score++
{

  switch (key) {
  case 1:
    snakex--;
    break;
  case 2:
    snakex++;
    break;
  case 3:
    snakey--;
    break;
  case 4:
    snakey++;
    break;
  }
  if (snakex == 0 || snakex == height || snakey == 0 || snakey == width) {
    gameover = 1;
  }
  if (snakex == fruitx && snakey == fruity) {
  label3:
    fruitx = rand() % 20;
    if (fruitx == 0)
      goto label3;
  label4:
    fruity = rand() % 20;
    if (fruity == 0)
      goto label4;
    score += 1;
  }
}

int main() {
  int m, n;
  game();
  while (gameover != 1) {
    print();
    input();
    setting();
  }
  return 0;
}