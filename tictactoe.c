#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


// Code TicTacToe with a usable interface in a language of your choice

char checkwin (const char *arr) {
  for (int i = 0; i < 3; i++) { // 0, 3, 6 OR 1, 4, 7 OR 2, 5, 8
    if (arr[i] == arr[i+3] == arr[i+6]) {
      return arr[i];
    }
    else if (arr[i*3] == arr[(i*3)+1] == arr[(i*3) + 2]) {
      return arr[i*3];
    }
  }
  if (arr[0] == arr[4] == arr[8]) {
    return arr[0];
  }
  else if (arr[2] == arr[4] == arr[6]) {
    return arr[2];
  }
  else {
    return ' ';
  }
}

//---------------------------------------------------------

bool won (char *arr) {
  char checkifwon = checkwin(arr);
  if (checkifwon == ' ') {
    printf("No one has won yet!\n");
    return false;
  }
  else {
    printf("%c won!\n", checkifwon);
    return true;
  }
}

//---------------------------------------------------------

void printboard (const char *arr) {
  printf(" %c | %c | %c\n", arr[0], arr[1], arr[2]);
  printf("--------------\n");
  printf(" %c | %c | %c\n", arr[3], arr[4], arr[5]);
  printf("--------------\n");
  printf(" %c | %c | %c\n", arr[6], arr[7], arr[8]);
}

//---------------------------------------------------------

void printturn(const int whoseturn) {
  if (whoseturn == 0) {
    printf("It is x's turn!\n");
  } else {
    printf("It is o's turn!\n");
  }
  printf("Enter a number between 0 and 8 to place your symbol in a box\n");
}

//---------------------------------------------------------

void updateturn(int *whoseturn){
  if (whoseturn == 0) {
    *whoseturn = 1;
    printf("whoseturn: %d\n", whoseturn);
  } else {
    *whoseturn = 0;
  }
}

//---------------------------------------------------------

void updatearray(const int whoseturn, const int index, char *arr){
  if (index >= 0 && index <= 8 && arr[index] != 'x' && arr[index] != 'o') {
    if (whoseturn == 0) {
      printf("x just took their turn\n");
      arr[index] = 'x';
    } else {
      printf("o just took their turn\n");
      arr[index] = 'o';
    }
  } else {
    printf("error: invalid input\n");
  }
}

//---------------------------------------------------------

int main () {
  char *arr = malloc(sizeof(char)*9);
  for (int i = 0; i < 9; i++) {
    arr[i] = i;
  }
  int whoseturn = 0;
  int placement = -1;
  printturn(whoseturn);
  printboard(arr);
  int c = scanf("%d", &placement);
  while (c) {
    updatearray(whoseturn, placement, arr);
    bool boolwon = won(arr);
    if (boolwon) break;
    updateturn(&whoseturn);
    printturn(whoseturn);
    printboard(arr);
    c = scanf("%d", &placement);
  }
  printboard(arr);
  char whowon = checkwin(arr);
  printf("%c wins!", whowon);
  free(arr);
}
