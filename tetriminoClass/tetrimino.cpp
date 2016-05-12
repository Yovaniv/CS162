#include <iostream>
#include <ctime>
#include "tetrimino.h"

Tetrimino::Tetrimino(int type){
	//If type is outside the boundery, give it a random value
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
	 case(3):

		 break;
	 case(4):

		 break;
	 case(5):

		 break;
	 case(6):

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

char Tetrimino::getColor() const{
	return Tetrimino::color;
	
}

Location Tetrimino::getLocation() const{
	return Tetrimino::location;
}

void Tetrimino::getGrid(int gridOut[][TETRIMINO_GRID_SIZE]) const{
	for (int i = 0; i < TETRIMINO_GRID_SIZE; i++){
		for (int j = 0; j < TETRIMINO_GRID_SIZE; j++){
			gridOut[i][j]=Tetrimino::grid[i][j];
		}
	}
}

bool Tetrimino::setLocation(Location newLocation){
	if (newLocation.col >= 0 &&  newLocation.row >= 0){
		Tetrimino::location.col = newLocation.col;
		Tetrimino::location.row = newLocation.row;
		return true;
	}else{
			return false;
	}
}

bool Tetrimino::setLocation(int row, int col){
	if (col >= 0 && row >= 0){
		Tetrimino::location.col = col;
		Tetrimino::location.row = row;
		return true;
	}else{
		return false;
	}
}

void Tetrimino::rotateLeft(){
	//initinlize the holding array
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

void Tetrimino::rotateRight(){
	//initinlize the holding array
	int rotatedTetrimino[TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE] = { 0 };
	int currentTetrimino[TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE] = { 0 };

	//Loads the current tetromino into a array
	Tetrimino::getGrid(currentTetrimino);

}

void Tetrimino::moveLeft(){
	Location currentLocation = Tetrimino::getLocation();
	Tetrimino::setLocation(currentLocation.row,currentLocation.col - 1);
}

void Tetrimino::moveRight(){
	Location currentLocation = Tetrimino::getLocation();
	Tetrimino::setLocation(currentLocation.row,currentLocation.col + 1);
}

void Tetrimino::moveDown(){
	Location currentLocation = Tetrimino::getLocation();
	Tetrimino::setLocation(currentLocation.row + 1, currentLocation.col);
}

void Tetrimino::moveUp(){
	Location currentLocation = Tetrimino::getLocation();
	Tetrimino::setLocation(currentLocation.row - 1, currentLocation.col);
}

int main(void){
	//Create the tetris peice
	Tetrimino TetriminoPiece(0);
	TetriminoPiece.dataDump();

	std::cout << std::endl;

	//Now lest test moving it down 6 times
	for (int i =0; i < 6; i++){
		TetriminoPiece.moveDown();
	}
	TetriminoPiece.dataDump();

	std::cout << std::endl;

	//Now lets move it to the right 6 times
	for (int i =0; i < 6; i++){
		TetriminoPiece.moveRight();
	}
	TetriminoPiece.dataDump();

	std::cout << std::endl;

	//Now lets move it left 3 peices
	for (int i =0; i < 3; i++){
		TetriminoPiece.moveLeft();
	}
	TetriminoPiece.dataDump();

	std::cout << std::endl;

	//Now lets move up by two
	for (int i =0; i < 2; i++){
		TetriminoPiece.moveUp();
	}
	TetriminoPiece.dataDump();

	//Lets test if the function will return fasles
	switch(TetriminoPiece.setLocation(-10,-10)){
	case(true):
		std::cout << "TRUE! The program allowed this position, please fix the code" << std::endl;
		TetriminoPiece.dataDump();
		break;
	case(false):
		std::cout << "FALSE! Nothing should have changed" << std::endl;
		TetriminoPiece.dataDump();
	}

	//Now lets set the position back to (0,0)
	TetriminoPiece.setLocation(0,0);
	TetriminoPiece.dataDump();

	//Now lets try rotating the piece 90 degrees
	TetriminoPiece.rotateRight();
	TetriminoPiece.dataDump();
}

void Tetrimino::dataDump(){
	std::cout << "The color of the Tetrimino is: " << Tetrimino::getColor() << std::endl;
	std::cout << "The col of the Tetrimino is: " <<Tetrimino::getLocation().col << std::endl;
	std::cout << "The row of the Tetrimino is: " <<Tetrimino::getLocation().row << std::endl;
	
	int currentTetrimino[TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE] = { 0 };

	Tetrimino::getGrid(currentTetrimino);

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