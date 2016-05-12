//========================================================================
//File:                 tetrimino.h
//Author:               Austin Parrish
//Last Modified:		02/14/2016
//Dev Env:              Xcode
//Description:          Header file for the Well class
//========================================================================
#ifndef TETRIS_WELL
#define TETRIS_WELL

class Well{
private:
    char board[24][8];
    int height;
    int width;

	bool rowsFull(int row);
	void moveRowsDown(int firstRowToMove);
public:
    Well();
    bool tetriminoFit(Tetrimino tetrimino);
    void addTetriminoToWell(Tetrimino tetrimino);
    int clearFullRows();
    bool topReached();
    void getBoard(char boardOut[][8]) const;
    void boardDump();
};
#endif