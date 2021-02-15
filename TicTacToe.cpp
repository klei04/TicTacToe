/*
 * This is a Tic Tac Toe game where two users can play against each other.
 * Author: Kevin Lei
 * Date: 2/15/2021
 */

#include <iostream>
#include <cctype>

using namespace std;

//Function Prototypes
void printBoard (int board[3][3]);
bool checkWin (int player, int board[3][3]);
bool checkTie (int board[3][3]);

//Constants
const int BLANK = 0;
const int X_MOVE = 1;
const int O_MOVE = 2;
const int X_TURN = 0;
const int O_TURN = 1;

//Main Method
int main() {

  int board[3][3];
  int turn = X_TURN;
  bool stillPlaying = true;
  int xWins = 0;
  int oWins = 0;
  char input[3];

  //Clears board
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = BLANK;
    }
  }

  //Game will continue playing while stillPlaying is true
  while (stillPlaying == true) {
    while (checkWin(X_MOVE, board) == false
	   && checkWin(O_MOVE, board) == false
	   && checkTie(board) == false) {
      
      printBoard(board);
      cin >> input;

      //Checks if the player entered a valid location on the grid
      if (strlen(input)!= 2) {
	cout << "ERROR: Enter a letter followed by a number" << endl;
      } else if (input[0] != 'a' && input[0] != 'b' && input[0] != 'c') {
	cout << "ERROR: Row must by 'a', 'b', or 'c'" << endl;
      } else if (input[1] != '1' && input[1] != '2' && input[1] != '3') {
	cout << "ERROR: Column must be '1', '2', or '3'" << endl;
      } else {
	int row = input[0] - 'a';
	int column = input[1] - '1';

	//Checks if the space is occupied and then places the piece
        if (board[row][column] == BLANK) {
	  if (turn == X_TURN) {
	    board[row][column] = X_MOVE;
	    turn = O_TURN;
	  } else {
	    board[row][column] = O_MOVE;
	    turn = X_TURN;
	  }
	} else {
	  cout << "ERROR: There is already a piece there, please pick a new piece" << endl;
	}
      }
    }

    printBoard(board);

    //Reports who won or if it was a tie
    if (checkWin(X_MOVE, board) == true) {
      cout << "X Wins!" << endl;
      xWins++;
      cout << "X has won " << xWins << " times and O has won " << oWins << " times." << endl;
    } else if (checkWin(O_MOVE, board) == true) {
      cout << "O Wins!" << endl;
      oWins++;
      cout << "X has won " << xWins << " times and O has won " << oWins << " times." << endl;
    } else if (checkTie(board) == true) {
      cout << "It's a tie!" << endl;
    }

    //Asking if players would like to play again
    cout << "Would you like to play again? Type 'y' for yes, type 'n' for no." << endl;
    cin >> input;

    //If players don't want to play anymore, program will end.
    //If players want to keep playing, the board is cleared and the turn is set back to x's move
    if (input[0] == 'n') {
      stillPlaying = false;
    }  else if (input[0] == 'y') {
      for (int i = 0; i < 3; i++) {
	for (int j = 0; j < 3; j++) {
	  board[i][j] = BLANK;
	}
      }
      turn = X_TURN;
    }
  }
}

//This function prints the board
void printBoard(int board[3][3]) {
  cout << " \t1\t2\t3" << endl;
  for (int i = 0; i < 3; i++) {
    cout << static_cast<char>('a' + i) << "\t";
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == BLANK) {
	cout << " \t";
      } else if (board[i][j] == X_MOVE) {
	cout << "X\t";
      } else if (board[i][j] == O_MOVE) {
	cout << "O\t";
      }
    }
    cout << endl;
  }  
}

//This function checks if anyone has won
bool checkWin(int player, int board[3][3]) {
         if (board[0][0] == player
             && board[0][1] == player
             && board[0][2] == player) {		
    return true;
  } else if (board[1][0] == player
	     && board[1][1] == player
	     && board[1][2] == player) {				
    return true;
  } else if (board[2][0] == player
	     && board[2][1] == player
	     && board[2][2] == player) {				
    return true;
  } else if (board[0][0] == player
	     && board[1][0] == player
	     && board[2][0] == player) {
    return true;
  } else if (board[0][1] == player
	     && board[1][1] == player
	     && board[2][1] == player) {
    return true;
  } else if (board[0][2] == player
	     && board[1][2] == player
	     && board[2][2] == player) {
    return true;
  } else if (board[0][0] == player
	     && board[1][1] == player
	     && board[2][2] == player) {
    return true;
  } else if (board[0][2] == player
	     && board[1][1] == player
	     && board[2][0] == player) {
    return true;
  }		
  return false;
}

//Method to check for a tie
bool checkTie(int board[3][3]) {		
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == BLANK) {	
	return false;
      }
    }
  }
  return true;
}
