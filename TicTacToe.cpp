/* Author: Allison Delgado
 * Last updated: 9/22/20
 * TicTacToe is a command line game of the classic TTT. 
 * Note: This program's algorithm is similar Delgado's TTT
 * program in Java created October 2019
 */


#include <iostream>
#include <cstring>
using namespace std;

//functions
void printBoard();
void resetBoard();
int checkWin();
bool checkBoardFill();
bool checkTie();

int main() {

  //print out board format
  int board[3][3];
  int winner = 0;
  const int BLANK = 0;
  const int X_MOVE = 1;
  const int O_MOVE = 2;
  const int X_TURN = 0;
  const int O_TURN = 1;
  int xWins = 0;
  int oWins = 0;
  int turn = X_TURN;
  bool stillPlaying = true;
  bool successfulMove = false;
  char str[2];
  
  //main gameplay 
  cout << "Welcome to TicTacToe!" << endl;
  cout << "Remember, enter your move in the letter then" << endl;
  cout << " number format. (ex a3 or b1)" << endl;
  resetBoard();
  turn = X_TURN;
  while (checkWin == 0 && checkTie == false){
    successfulMove = false;
    printBoard();
    cout << "Enter a move: " << endl;
    cin.get(str, 2); //gets user's choice move

    //check legality
    if (strlen(str) != 2){ //input has to be 2 characters
      cout << "Please enter a letter followed by a number. (ex a1)" << endl;
    }
    else if (str[0] != 'a' || str[0] != 'b' || str[0] != 'c'){ //check letter
      cout << "Row can only be a, b, or c." << endl;
    }
    else if (str[0] != '1' || str[0] != '2' || str[0] != '3'){ //check num
      cout << "Column can only be 1, 2, or 3." << endl;
    }
    else { //otherwise it is legal
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
	turn = X_TURN;
      }
      else if (turn == X_TURN && successfulMove == true){
	turn = O_TURN;
      }
    }
  }// end while loop

  
  return 0;
}
