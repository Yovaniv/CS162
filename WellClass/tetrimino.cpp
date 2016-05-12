//========================================================================
//File:                 tetrimino.cpp
//Author:               Austin Parrish
//Last Modified:		02/14/2016
//Dev Env:              Xcode
//Description:          Implementation of the Tetrimino class
//========================================================================
#include <iostream>
#include <ctime>
#include "tetrimino.h"

//================================================================
// Function:    Tetrimino(constructor)
// Description: Constructor for the Tetrimino class
//================================================================
Tetrimino::Tetrimino(int type){
	//If type is outside the boundary, give it a random value
	if (type < 0 || type > 6){
		type = getRandomNumber(0,6);
	}

	Tetrimino::location.col=0;
	Tetrimino::location.row=0;

	for (int i =0; i < TETRIMINO_GRID_SIZE; i++){
		for (int j = 0; j < TETRIMINO_GRID_SIZE; j++){
			grid [i][j] = 0;
		}
	}

	//Set the grid
	switch (type){
	case (0):
		grid [1][1] = 1;
		for (int i = 0; i < 3; i++){
			grid [2][i+1] = 1;
		}
		break;
	case(1):
		for (int i = 0; i < 4; i++){
			grid[2][i]=1;
		}
		break;
	case(2):
		grid [1][3] = 1;
		for (int i = 0; i < 3; i++){
			grid [2][i+1] = 1;
		}
		break;
	case(3) :
		for (int i = 1; i < 3; i++) {
			for (int j = 1; j < 3; j++) {
				grid[i][j] = 1;
			}
		}
		break;
	case(4) :
		grid[1][2] = 1;
		grid[1][3] = 1;
		grid[2][1] = 1;
		grid[2][2] = 1;
		break;
	case(5):
		grid[1][2] = 1;
		grid[2][1] = 1;
		grid[2][2] = 1;
		grid[2][3] = 1;
		break;
	case(6):
		grid[1][1] = 1;
		grid[1][2] = 1;
		grid[2][2] = 1;
		grid[2][3] = 1;
		break;
	}

	//Assign a color
	switch(getRandomNumber(0,6)){
	case(0):
		color = 'r';
		break;
	case(1):
		color = 'y';
		break;
	case(2):
		color = 't';
		break;
	case(3):
		color = 'b';
		break;
	case(4):
		color = 'o';
		break;
	case(5):
		color = 'g';
		break;
	case(6):
		color = 'p';
		break;
	}

	color = Tetrimino::getColor();
}

//================================================================
// Function:    getColor
// Description: Get's the color of the Tetrimino object
// Return value:
//	The color value of the Tetrimino object (as a char)
//================================================================
char Tetrimino::getColor() const{
	return Tetrimino::color;
}

//================================================================
// Function:    getLocation
// Description: Get's the current location of the Tetrimino object
// Return value:
//	The current location of the Tetrimino object (as a Location)
//================================================================
Location Tetrimino::getLocation() const{
	return Tetrimino::location;
}

//================================================================
// Function:    getGrid
// Description: Get's the grid of the Tetrimino object
// Arguments:
//	gridOut (I/O) - The grid array that you want to copy the
//	Tetrimino grid into (through pass by reference)
//================================================================
void Tetrimino::getGrid(int gridOut[][TETRIMINO_GRID_SIZE]) const{
	for (int i = 0; i < TETRIMINO_GRID_SIZE; i++){
		for (int j = 0; j < TETRIMINO_GRID_SIZE; j++){
			gridOut[i][j]=Tetrimino::grid[i][j];
		}
	}
}

//================================================================
// Function:    setLocation
// Description: Allows you to pass a Location to set the location
//	of an object.
// Arguments:
//	newLocation (I/O) - The location the the tetris piece will be
//	set to.
// Return value:
//	True if set successfully, False if set outside the range
//================================================================
bool Tetrimino::setLocation(Location newLocation){
	Tetrimino::location.col = newLocation.col;
	Tetrimino::location.row = newLocation.row;
	return true;
}

//================================================================
// Function:    setLocation
// Description: Allows you to manually enter the cords. to set the
//	location of the tetris piece
// Arguments:
//	row (I) - The row where the piece will be placed
//	col (I) - The col where the piece will be placed
// Return value:
//	True if set successfully, False if set outside the range
//================================================================
bool Tetrimino::setLocation(int row, int col){
	if (col >= 0 && row >= 0){
		Tetrimino::location.col = col;
		Tetrimino::location.row = row;
		return true;
	}else{
		return false;
	}
}

//================================================================
// Function:    Tetrimino::rotateLeft
// Description: Rotates the tetris piece to the left
//================================================================
void Tetrimino::rotateLeft(){
	//initialize the holding array
	int rotatedTetrimino[TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE] = { 0 };
	int currentTetrimino[TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE] = { 0 };

	//Loads the current tetromino into a array
	Tetrimino::getGrid(currentTetrimino);

	for (int row = TETRIMINO_GRID_SIZE-1; row >= 0; row--){
		for (int col = 0; col < TETRIMINO_GRID_SIZE; col++){
			if (currentTetrimino[row][col]==1){
				rotatedTetrimino [col][(TETRIMINO_GRID_SIZE-1)-row] = 1;
			}else{
				rotatedTetrimino [col][(TETRIMINO_GRID_SIZE-1)-row] = 0;
			}
		}
	}
	for (int i = 0; i < TETRIMINO_GRID_SIZE; i++){
		for (int j = 0; j < TETRIMINO_GRID_SIZE; j++){
			Tetrimino::grid[i][j]=rotatedTetrimino[i][j];
		}
	}
}

//================================================================
// Function:    Tetrimino::rotateRight
// Description: Rotates the tetris piece to the right
//================================================================
void Tetrimino::rotateRight(){
	//initialize the holding array
	int rotatedTetrimino[TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE] = { 0 };
	int currentTetrimino[TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE] = { 0 };

	//Loads the current tetromino into a array
	Tetrimino::getGrid(currentTetrimino);

	for (int row = 0; row < TETRIMINO_GRID_SIZE; row++) {
		for (int col = TETRIMINO_GRID_SIZE - 1; col >= 0; col--) {
			if (currentTetrimino[row][col] == true) {
				rotatedTetrimino[(TETRIMINO_GRID_SIZE - 1) - col][row] = true;
			}
			else {
				rotatedTetrimino[(TETRIMINO_GRID_SIZE - 1) - col][row] = false;
			}
		}
	}
	for (int i = 0; i < TETRIMINO_GRID_SIZE; i++) {
		for (int j = 0; j < TETRIMINO_GRID_SIZE; j++) {
			Tetrimino::grid[i][j] = rotatedTetrimino[i][j];
		}
	}
}

//================================================================
// Function:    Tetrimino::moveLeft
// Description: Moves the tetris piece to the left
//================================================================
void Tetrimino::moveLeft(){
	Location currentLocation = Tetrimino::getLocation();
	Tetrimino::setLocation(currentLocation.row,currentLocation.col - 1);
}

//================================================================
// Function:    Tetrimino::moveRight
// Description: Moves the tetris piece to the right
//================================================================
void Tetrimino::moveRight(){
	Location currentLocation = Tetrimino::getLocation();
	Tetrimino::setLocation(currentLocation.row,currentLocation.col + 1);
}

//================================================================
// Function:    Tetrimino::moveDown
// Description: Moves the tetris piece down
//================================================================
void Tetrimino::moveDown(){
	Location currentLocation = Tetrimino::getLocation();
	Tetrimino::setLocation(currentLocation.row + 1, currentLocation.col);
}

//================================================================
// Function:    Tetrimino::moveUp
// Description: Moves the tetris piece up
//================================================================
void Tetrimino::moveUp(){
	Location currentLocation = Tetrimino::getLocation();
	Tetrimino::setLocation(currentLocation.row - 1, currentLocation.col);
}

//================================================================
// Function:    Tetrimino::dataDump
// Description: Outputs all internal vars for the tetris piece
//================================================================
void Tetrimino::dataDump(){
	//Output color and location of piece
	std::cout << "The color of the Tetrimino is: " << Tetrimino::getColor() << std::endl;
	std::cout << "The col of the Tetrimino is: " <<Tetrimino::getLocation().col << std::endl;
	std::cout << "The row of the Tetrimino is: " <<Tetrimino::getLocation().row << std::endl;

	//Get the current tetris piece
	int currentTetrimino[TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE] = { 0 };
	Tetrimino::getGrid(currentTetrimino);

	//Output tetris piece
	for (int i = 0; i < TETRIMINO_GRID_SIZE; i++){
		for (int j = 0; j < TETRIMINO_GRID_SIZE; j++){
			if (currentTetrimino[i][j] == 1){
				std::cout << "#";
			}else{
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
}

//================================================================
// Function:    getRandomNumber
// Description: returns a random number between given low and high
//	values, inclusive. 
//	Note: include cstdlib (for rand) and ctime (for time).
// Arguments:
//	low (I) - The lowest number to be generated
//	high (I) - The highest number to be generated (must be > low)
// Return value:
//	A random number between low and high (inclusive)
//================================================================
int Tetrimino::getRandomNumber(int low, int high) {
	static bool firstTime=true;
	int randNum;

	//if first time called, seed random number generator
	if (firstTime) {
		srand( static_cast<unsigned int>(time(NULL)) );
		firstTime=false;
	}

	//generate random number between given low and high values (inclusive)
	randNum = rand() % (high-low+1) + low;

	return randNum;
}