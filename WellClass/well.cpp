//========================================================================
//File:             well.cpp
//Author:           Austin Parrish
//Last Modified:    02/14/2016
//Dev Env:          Xcode
//Description:      Implementation of the Well class
//========================================================================
#include <iostream>
#include <ctime>
#include "tetrimino.h"
#include "well.h"

//================================================================
// Function:    Tetrimino(constructor)
// Description: Constructor for the Well class
//================================================================
Well::Well(){
	height = 24;
	width = 8;

	//Setup a blank board
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			board[i][j] = ' ';
		}
	}
}

//================================================================
// Function:    Well::tetriminoFit
// Description: Checks if the tetrimino object will fit in it's
//              location
// Arguments:
//	tetrimino (I) - The tetrimino object that we want to test
// Return value:
//	Wether or not the piece fits (true or false)
//================================================================
bool Well::tetriminoFit(Tetrimino tetrimino){
	int currentTetrimino[TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE] = { 0 };
	char currentBoard[24][8] = { ' ' };
	Location currentTetriminoLocation;
	bool doesItFit = true;

	tetrimino.getGrid(currentTetrimino);
	currentTetriminoLocation = tetrimino.getLocation();
	Well::getBoard(currentBoard);

	for (int i = 0; i < TETRIMINO_GRID_SIZE; i++){
		for (int j = 0; j < TETRIMINO_GRID_SIZE; j++){
			if (currentTetrimino[i][j] == 1 && currentBoard[i+currentTetriminoLocation.row][j+currentTetriminoLocation.col] != ' '){
				doesItFit = false;
			}
		}
	}
	return doesItFit;
}

//================================================================
// Function:    Well::addTetriminoToWell
// Description: Adds the tetromino object to the program
// Arguments:
//	tetrimino (I) - The tetrimino object that we want to add
//================================================================
void Well::addTetriminoToWell(Tetrimino tetrimino){
	int currentTetrimino[TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE] = { 0 };
	Location currentTetriminoLocation;

	tetrimino.getGrid(currentTetrimino);
	currentTetriminoLocation = tetrimino.getLocation();

	if (Well::tetriminoFit(tetrimino) == true){
		for (int i = 0; i < TETRIMINO_GRID_SIZE; i++){
			for (int j = 0; j < TETRIMINO_GRID_SIZE; j++){
				if(currentTetrimino[i][j] == 1){
					board [i+currentTetriminoLocation.row][j+currentTetriminoLocation.col] = tetrimino.getColor();
				}
			}
		}
	}
}

//================================================================
// Function:    Well::clearFullRows
// Description: Checks for all rows to see if any rows are full
// Return value:
//	How many rows we cleared (for score keeping)
//================================================================
int Well::clearFullRows(){
	int rowsCleared;
    
	for (int i = 0; i < height; i++){
		if(Well::rowsFull(i)==true){
            for (int j = 0; j < width; j++){
                board[i][j] = ' ';
            }
            
			rowsCleared++;
			Well::moveRowsDown(i);
		}
	}
    
	return rowsCleared;
}

//================================================================
// Function:    Well::rowsFull
// Description: checks if the a row is full
// Arguments:
//	row (I) - The row we want to check
// Return value:
//	Wether or not the row is full or not (true or false)
//================================================================
bool Well::rowsFull(int row){
	bool full = true;
	for (int i = 0; i < width; i++){
		if (board[row][i] == ' '){
			full = false;
		}
	}
	return full;
}

//================================================================
// Function:    Well::moveRowsDown
// Description: moves all rows down in the well
// Arguments:
//	firstRowToMove (I) - the first row we want to move down
//================================================================
void Well::moveRowsDown(int firstRowToMove){
    for (int i = firstRowToMove; i >=1; i--){
        for (int j = 0; j <= width; j++){
            if (board[i-1][j] != ' '){
                board[i][j] = board[i-1][j];
                board[i-1][j] = ' ';
            }
        }
    }
}

//================================================================
// Function:    Well::topReached
// Description: Checks if the tetrimino has a peice in the 1st row
// Return value:
//	Wether or not their is a peice in the first row (true or false)
//================================================================
bool Well::topReached(){
	bool full = false;
	for (int i = 0; i < width; i++){
		if (board[0][i] != ' '){
			full = true;
		}
	}
	return full;
}

//================================================================
// Function:    Well::getBoard
// Description: grabs the well from the object
// Arguments:
//	boardOut[][8] (I/O) - The Well array
//================================================================
void Well::getBoard(char boardOut[][8]) const{
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			boardOut[i][j]=Well::board[i][j];
		}
	}
}

//================================================================
// Function:    Well::boardDump
// Description: cout's the board
//================================================================
void Well::boardDump(){
	//std::cout << " 012345678" << std::endl;
	for (int i = 0; i < height; i++){
		//std::cout << i;
		for (int j = 0; j < width; j++){
			std::cout << board[i][j];
		}
		std::cout << std::endl;
	}
}

//================================================================
// In our main program, we will test our class function by
// implementing the following actions:
//		- Add tetromino blocks to the well and see if we can
//		overlap another piece
//		- create a row full of pieces and see if we can clear them
//		- add some pieces in the top row 
//================================================================
int main(void){
	//We'll start by testing if we can overlap a piece
	Well Well1;

	//tetrimino1 will load because its the only one on the board
	Tetrimino Tetrimino1;
	Tetrimino1.setLocation(14,4);
	Well1.addTetriminoToWell(Tetrimino1);

	//tetrimino2 can load if the tetris piece does not overlap with another piece
	Tetrimino Tetrimino2;
	Tetrimino2.setLocation(14,2);
	Well1.addTetriminoToWell(Tetrimino2);

	//tetrimino3 will not load becasue it will overlap with another piece
	Tetrimino Tetrimino3;
	Tetrimino3.setLocation(14,3);
	Well1.addTetriminoToWell(Tetrimino3);

	Well1.boardDump();

    
	//Now we will test the clearFullRows function
	Well Well2;

	//Lets create a situation where the tetris peices will be full
	Tetrimino Tetrimino4(1);
	Tetrimino4.setLocation(1,0);
	Well2.addTetriminoToWell(Tetrimino4);

	Tetrimino Tetrimino5(0);
	Tetrimino5.setLocation(1,3);
	Well2.addTetriminoToWell(Tetrimino5);

	Tetrimino Tetrimino6(1);
	Tetrimino6.rotateLeft();
	Tetrimino6.setLocation(0,6);
	Well2.addTetriminoToWell(Tetrimino6);

	Well2.boardDump();
	Well2.clearFullRows();
	Well2.boardDump();
    
    
    //Now lets test if we can detect if a peice is located in the first row
    Well Well3;
    
    //Add a tetromino that will place a peice inside the first row
    Tetrimino Tetrimino7(1);
    Tetrimino7.rotateLeft();
    Well3.addTetriminoToWell(Tetrimino7);
    
    //Test the function if it can detect the peioce in the first row
    if (Well3.topReached() == true) {
        std::cout << "True" << std::endl;
    }else{
        std::cout << "False" << std::endl;
    }
}