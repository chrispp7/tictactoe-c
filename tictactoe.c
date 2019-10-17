// Code TicTacToe with a usable interface in a language of your choice

// include appropriate libraries 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// checks for a winner
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
    //asdksadlash
  }
}

//---------------------------------------------------------

// returns true if a player has won the game
bool won (char *arr) {
  
  // if checkifwon returns a character, someone has won, returns true
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

// prints the board with appropriate spacing
void printboard (const char *arr) {
  printf(" %c | %c | %c\n", arr[0], arr[1], arr[2]);
  printf("--------------\n");
  printf(" %c | %c | %c\n", arr[3], arr[4], arr[5]);
  printf("--------------\n");
  printf(" %c | %c | %c\n", arr[6], arr[7], arr[8]);
}

//---------------------------------------------------------

// prints the player whose turn it is
void printturn(const int whoseturn) {
  if (whoseturn == 0) {
    printf("It is x's turn!\n");
  } else {
    printf("It is o's turn!\n");
  }
  printf("Enter a number between 0 and 8 to place your symbol in a box\n");
}

//---------------------------------------------------------

// updates player turns
void updateturn(int *whoseturn){
  if (whoseturn == 0) {
    *whoseturn = 1;
    printf("whoseturn: %d\n", whoseturn);
  } else {
    *whoseturn = 0;
  }
}

//---------------------------------------------------------

// updates the array based on who took the turn and where they placed their piece
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
  
  // allocates memory for the array
  char *arr = malloc(sizeof(char)*9);
  
  // initializing array
  for (int i = 0; i < 9; i++) {
    arr[i] = i;
  }
  
  // variable initialization
  int whoseturn = 0;
  int placement = -1;
  
  // prints the player's turn
  printturn(whoseturn);
  
  // prints the board
  printboard(arr);
  
  // scans for input
  int c = scanf("%d", &placement);
  
  // while there is input and no one has won
  while (c) {
    // update the array
    updatearray(whoseturn, placement, arr);
    // find out if someone won or not
    bool boolwon = won(arr);
    // break if someone wins
    if (boolwon) break;
    
    // if no one wins, continue
    updateturn(&whoseturn);
    // print whose turn it is
    printturn(whoseturn);
    // print the board
    printboard(arr);
    // re-scan for input
    c = scanf("%d", &placement);
  }
  
  // re-print the board
  printboard(arr);
  char whowon = checkwin(arr);
  // declare winner
  printf("%c wins!", whowon);
  // free memory from array
  free(arr);
}
