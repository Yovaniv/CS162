//========================================================================
//File:                 game.h
//Author:               Austin Parrish
//Last Modified:		02/25/2016
//Dev Env:              Xcode
//Description:          Header file for the Game class
//========================================================================
#ifndef TETRIS_GAME
#define TETRIS_GAME

#include <SFML/Graphics.hpp>
#include "tetrimino.h"
#include "well.h"

const int LAYOUT_WINDOW_WIDTH = 400;
const int LAYOUT_WINDOW_HEIGHT = 500;
const int LAYOUT_BOARD_TOP = 10;
const int LAYOUT_BOARD_LEFT = 200;
const int BLOCK_SIZE_PIXELS = 20;

enum GameState {TETRIS_SPLASH, TETRIS_PLAY, TETRIS_GAME_OVER};

class Game {
private:
	sf::RenderWindow window;
	sf::Font myFont;
	Well *gameWell;
	Tetrimino *tetriminoInPlay;
	Tetrimino *tetriminoOnDeck;
	int score;

	sf::Color convertToSfmlColor(char color);
	void drawWell(Well well, int topOfWell, int leftOfWell, int widthOfBlock);
	void drawTetrimino(Tetrimino *tetrimino, int topOfWell, int leftOfWell, int widthOfBlock);
	void processSplashScreen();
	void processGameScreen();
	bool processGameOverScreen();
	void drawScore();
public:
	Game();
	void playGame();
};

#endif
