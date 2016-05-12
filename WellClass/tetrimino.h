//========================================================================
//File:                 tetrimino.h
//Author:               Austin Parrish
//Last Modified:		02/14/2016
//Dev Env:              Xcode
//Description:          Header file for the Tetrimino class
//========================================================================
#ifndef TETRIS_TETRIMINO
#define TETRIS_TETRIMINO

const int TETRIMINO_GRID_SIZE = 4;

struct Location {
    int row;
    int col;
};

class Tetrimino {
    
public:
    // constructor
    // Initialize grid, color, and location
    // The ëtypeí parameter will determine which piece we initialize grid to
    Tetrimino(int type = 7); 			// valid type values are 0-6
    
    //---------------------------------------------
    //accessors
    char getColor() const; 			// returns the color of the tetrimino object
    Location getLocation() const; 		// returns the location of the Tetrimino
    void getGrid(int gridOut[][TETRIMINO_GRID_SIZE]) const;  // returns the grid
    
    //---------------------------------------------
    //mutators
    bool setLocation(Location newLocation); 	// modify location.row and location.col
    bool setLocation(int row, int col); 	// modify location.row and location.col
    
    void rotateLeft();
    void rotateRight();
    void moveLeft();
    void moveRight();
    void moveDown();
    void moveUp();
    
    //---------------------------------------------
    //others
    void dataDump(); // print out the value of grid, color, and location
    
private:
    int grid[TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE]; //contains only zeros and ones
    char color;
    Location location;
    int getRandomNumber(int low, int high);		//helper function
};
#endif
