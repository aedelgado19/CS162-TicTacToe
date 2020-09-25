/* Author: Allison Delgado
 * Last updated: 9/24/20
 * TicTacToe is a command line game of the classic TTT. 
 * Note: This program's algorithm is similar Delgado's TTT
 * program in Java created October 2019
 */


#include <iostream>
#include <cstring>
using namespace std;

#define BLANK 0
#define ROWS 3
#define COLS 3
#define X_MOVE 1
#define O_MOVE 2
//functions
void printBoard(int board[ROWS][COLS]);
void resetBoard(int board[ROWS][COLS]);
int checkWin(int board[ROWS][COLS]);
bool checkBoardFill(int board[ROWS][COLS]);
bool checkTie(int board[ROWS][COLS]);

int main() {
  
  //game variables
  int board[ROWS][COLS];
  int winner = 0;
  const int X_TURN = 0;
  const int O_TURN = 1;
  int xWins = 0;
  int oWins = 0;
  int turn = X_TURN;
  bool stillPlaying = true;
  bool successfulMove = false;
  char str[3]; //user move

  while (stillPlaying == true){
    //main gameplay 
    cout << "Welcome to TicTacToe!" << endl;
    cout << "Remember, enter your move in the letter then" << endl;
    cout << " number format. (ex a3 or b1)" << endl;

    resetBoard(board);
    turn = X_TURN;
    while (checkWin(board) == 0 && checkTie(board) == false){
      successfulMove = false;
      printBoard(board);
      cout << "Enter a move: " << endl;
      cin.get(str, 3); //gets user's choice move
      cin.get();
    
      //check legality
      if (strlen(str) != 2){ //input has to be 2 characters and null
	cout << "Please enter a letter followed by a number. (ex a1)" << endl;
      } else {
	if ((str[0] != 'a') && (str[0] != 'b') && (str[0] != 'c')){ //check letter
	  cout << "Row can only be a, b, or c." << endl;
	} else {
	  if (str[1] != '1' && str[1] != '2' && str[1] != '3'){ //check num
	    cout << "Column can only be 1, 2, or 3." << endl;
	  } else { 
	    int row = str[0] - 'a';
	    int column = str[1] - '1';
	  
	    //successful X move!
	    if ((turn == X_TURN) && (board[row][column] == BLANK)){
	      board[row][column] = X_MOVE;
	      successfulMove = true;
	    }
	    //if there is already a piece there...
	    else if ((turn == X_TURN) && (board[row][column] != BLANK)){
	      cout << "There is already a piece there." << endl;
	    }
	    //successful O move!
	    if ((turn == O_TURN) && (board[row][column] == BLANK)){
	      board[row][column] = O_MOVE;
	      successfulMove = true;
	    }
	  
	    //if there is already a piece there...
	    else if ((turn == O_TURN) && (board[row][column] != BLANK)) {
	      cout << "There is already a piece there." << endl;
	    }
	  
	    //swap turns
	    if (turn == O_TURN && successfulMove == true){
	      cout << "X turn" << endl;
	      turn = X_TURN;
	    }
	    else if (turn == X_TURN && successfulMove == true){
	      cout << "O turn" << endl;
	      turn = O_TURN;
	    }
	  }
	}
      }
    }
    //winning statements
    char playAgain = 'y';
    
    //if x, win = 1. if O, win = 2. If nobody wins or a tie, win = 0
    if (checkWin(board) == 0){ //game tie
      cout << "Tie!" << endl;
    }
    else if (checkWin(board) == 1){ //x win
      cout << "X wins!" << endl;
      xWins += 1; //increment num of wins
      cout << "Amount of X wins: " << xWins << endl;
      cout << "Amount of O wins: " << oWins << endl;
    }
    else if (checkWin(board) == 2){ //o win
      cout << "O wins!" << endl;
      oWins += 1; //increment num of wins
      cout << "Amount of X wins: " << xWins << endl;
      cout << "Amount of O wins: " << oWins << endl;
    }
    bool validResponse = false; //used in play again down below

    while (validResponse == false){
      //play again?
      cout << "Do you want to play again? (Y/N)" << endl;
      cin >> playAgain;
      cin.get();
      if (playAgain == 'Y' || playAgain == 'y'){
	stillPlaying = true;
	validResponse = true;
      }
      else if (playAgain == 'N' || playAgain == 'n'){
	stillPlaying = false;
	validResponse = true;
      }
      else {
	cout << "That's not a valid answer!" << endl;
	validResponse = false;
      }
    }
  }//end stillPlaying
  return 0;
}//end int main()


//set up board
void printBoard(int board[ROWS][COLS]){
  cout << "  1 2 3" << endl;
  char output[4];
   
  for (int i = 0; i < 3; i++){ //print out letters in column
    int counter = 0;
    output[0] = ('a'+i);
    counter++;
    
    for (int j = 0; j < 3; j++){
      if (board[i][j] == X_MOVE){
	output[counter] = 'X';
	counter++;
      } else if (board[i][j] == O_MOVE){
	output[counter] = 'O';
	counter++;
      } else if (board[i][j] == BLANK){
	output[counter] = ' ';
	counter++;
      }
    }
    cout << output[0] << " " << output[1] << " " << output[2] << " " << output[3] << endl;
  }
}

//set all spaces to blank
void resetBoard(int board[ROWS][COLS]){
  
  board[0][0] = BLANK;
  board[1][0] = BLANK;
  board[2][0] = BLANK;
  board[0][1] = BLANK;
  board[0][2] = BLANK;
  board[1][1] = BLANK;
  board[1][2] = BLANK;
  board[2][1] = BLANK;
  board[2][2] = BLANK;
}

/* Determine a win
 * Algorithm: searches board for 3 moves in row,col,diagonal
 * outputs: 0,1,2 where 0 = no win, 1 = X win, 2 = O win
 */

int checkWin(int board[ROWS][COLS]){
  for (int i = 1; i <= 2; i++){
    if(board[0][0] == i && board[0][1] == i && board[0][2] == i){ //top row across
      return i;
    }
    if(board[0][0] == i && board[1][1] == i && board[2][2] == i){ //diagonal top L to bottom R
      return i;
    }
    if(board[0][2] == i && board[1][1] == i && board[2][0] == i){ //diagonal top R to bottom L
      return i;
    }
    if(board[0][2] == i && board[1][2] == i && board[2][2] == i){ //right column down
      return i;
    }
    if(board[1][0] == i && board[1][1] == i && board[1][2] == i){ //middle row across
      return i;
    }
    if(board[2][0] == i && board[2][1] == i && board[2][2] == i){ //bottom row across
      return i;
    }
    if(board[0][0] == i && board[1][0] == i && board[2][0] == i){ //left column down
      return i;
    }
    if(board[0][1] == i && board[1][1] == i && board[2][1] == i){ //middle row down
      return i;
    }
  }
 return 0; //nobody won
}

//if everything is filled, returns true. else returns false
bool checkBoardFill(int board[ROWS][COLS]){
  if(
     board[0][0] != BLANK &&
     board[1][0] != BLANK &&
     board[2][0] != BLANK &&
     board[0][1] != BLANK &&
     board[0][2] != BLANK &&
     board[1][1] != BLANK &&
     board[1][2] != BLANK &&
     board[2][1] != BLANK &&
     board[2][2] != BLANK) {
    return true; //board is completely filled
  }
  else {
    return false; //board not completely filled
  }
}

//a tie occurs when board is filled and nobody has won
bool checkTie(int board[ROWS][COLS]){
  if ((checkBoardFill(board) == true) && (checkWin(board) == 0)){
    return true;
  }
  return false;
}

