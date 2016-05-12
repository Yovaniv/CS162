//========================================================================
//File:                 tetrimino.cpp
//Author:               Austin Parrish
//Last Modified:		02/25/2016
//Dev Env:              Xcode
//Description:          Implementation of the Game class
//========================================================================
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "game.h"
#include <iostream>

//================================================================
// Function:    Game(constructor)
// Description: Constructor for the Game class
//================================================================
Game::Game() {
	if (!myFont.loadFromFile("PressStart2P-Regular.ttf")) {

	}

	tetriminoInPlay = NULL;
	tetriminoOnDeck = NULL;

	score = 0;

	window.create(sf::VideoMode(LAYOUT_WINDOW_WIDTH, LAYOUT_WINDOW_HEIGHT), ">muh tetrus gayme", sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(60);
}

//================================================================
// Function:    Game::convertToSfmlColor
// Description: returns the SFML color of the char color
// Arguments:
//	color (I) - the color we want in SFML format
// Return value:
//	the SFML color
//================================================================
sf::Color Game::convertToSfmlColor(char color) {
	sf::Color sfmlColor;

	switch (color) {
	case 'B':
		sfmlColor = sf::Color::Black;
		break;
	case 'b':
		sfmlColor = sf::Color::Blue;
		break;
	case 'c':
		sfmlColor = sf::Color::Cyan;
		break;
	case 'g':
		sfmlColor = sf::Color::Green;
		break;
	case 'm':
		sfmlColor = sf::Color::Magenta;
		break;
	case 'r':
		sfmlColor = sf::Color::Red;
		break;
	case 'y':
		sfmlColor = sf::Color::Yellow;
		break;
	default:
		sfmlColor = sf::Color::White;
	}

	return sfmlColor;
}

//================================================================
// Function:    Game::drawWell
// Description: draws the well object
// Arguments:
//	well (I) - the well object
//	topOfWel (I) - The position of the well from the top
//	leftOfWell (I) - The position of the well from the left
//	widthOfBlock (I) - the width of a tetris block
//================================================================
void Game::drawWell(Well well, int topOfWell, int leftOfWell, int widthOfBlock) {
	char boardArray[MAX_HEIGHT][MAX_WIDTH];
	well.getBoard(boardArray);

	sf::RectangleShape boardShape;
	boardShape.setSize(sf::Vector2f(20, 20));
	boardShape.setOutlineThickness(1);
	boardShape.setOutlineColor(Game::convertToSfmlColor('B'));

	for (int i = 0; i < MAX_HEIGHT; i++) {
		for (int j = 0; j < MAX_WIDTH; j++) {
			boardShape.setPosition(sf::Vector2f(leftOfWell + widthOfBlock*j, topOfWell + widthOfBlock*i));
			window.draw(boardShape);
			if (boardArray[i][j] == ' ') {
				boardShape.setFillColor(Game::convertToSfmlColor('w'));
			}
			else {
				boardShape.setFillColor(Game::convertToSfmlColor(boardArray[i][j]));
			}
			window.draw(boardShape);
		}
	}
}

//================================================================
// Function:    Game::drawTetrimino
// Description: draws the tetromino object
// Arguments:
//	well (I) - the tetromino object
//	topOfWel (I) - The position of the well from the top
//	leftOfWell (I) - The position of the well from the left
//	widthOfBlock (I) - the width of a tetris block
//================================================================
void Game::drawTetrimino(Tetrimino *tetrimino, int topOfWell, int leftOfWell, int widthOfBlock) {
	int gridArray[TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE];
	tetrimino->getGrid(gridArray);
	Location currentTetriminoLocation = tetrimino->getLocation();

	sf::RectangleShape boardShape;
	boardShape.setSize(sf::Vector2f(19, 19));
	for (int i = 0; i < TETRIMINO_GRID_SIZE; i++) {
		for (int j = 0; j < TETRIMINO_GRID_SIZE; j++) {
			if (gridArray[i][j] == 1) {
				//boardShape.setOutlineThickness(1);
				//boardShape.setOutlineColor(Game::convertToSfmlColor('B'));
				boardShape.setPosition(sf::Vector2f(leftOfWell + widthOfBlock*(j + currentTetriminoLocation.col), topOfWell + widthOfBlock*(i + currentTetriminoLocation.row)));
				boardShape.setFillColor(Game::convertToSfmlColor(tetrimino->getColor()));
				window.draw(boardShape);
			}
		}
	}
}

//================================================================
// Function:    Game::playGame
// Description: The game loop
//================================================================
void Game::playGame() {
	GameState status = TETRIS_SPLASH;
	while (window.isOpen()) {
		switch (status) {
		case TETRIS_SPLASH:
			processSplashScreen();
			status = TETRIS_PLAY;
			break;
		case TETRIS_PLAY:
			processGameScreen();
			status = TETRIS_GAME_OVER;
			break;
		case TETRIS_GAME_OVER:
			if (processGameOverScreen() == true) {
				status = TETRIS_PLAY;
			}
			else {
				window.close();
			}
			break;
		}
	}
}

void Game::processSplashScreen() {
	std::cout << "Hi rich" << std::endl;
}

void Game::processGameScreen() {
	sf::Music music;
	if (!music.openFromFile("music.ogg"))
		std::cout << "Audio failed" << std::endl; // error
	music.setLoop(true);
	music.play();

	sf::Music sound;
	if (!sound.openFromFile("clear.ogg")) {
		std::cout << "Audio failed" << std::endl; // error
	}
	/*
	if (music.getStatus() == 0 && sound.getStatus() == 0) {
		music.play();
	}*/
	Well well;
	Tetrimino *tetriminoInPlay = new Tetrimino;
	Tetrimino *tetriminoOnDeck = new Tetrimino;
	int countDown = 100;

	std::cout << "Up Next: " << std::endl;
	tetriminoOnDeck->dataDump();
	tetriminoInPlay->setLocation(0, 2);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left) {
				tetriminoInPlay->moveLeft();
				if (well.tetriminoFit(*tetriminoInPlay) == false) {
					tetriminoInPlay->moveRight();
				}
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right) {
				tetriminoInPlay->moveRight();
				if (well.tetriminoFit(*tetriminoInPlay) == false) {
					tetriminoInPlay->moveLeft();
				}
			}
			/* For testing purposes
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up) {
			tetriminoMove.moveUp();
			if (well.tetriminoFit(tetriminoMove) == false) {
			tetriminoMove.moveDown();
			}
			}*/
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up) {
				tetriminoInPlay->rotateRight();
				if (well.tetriminoFit(*tetriminoInPlay) == false) {
					tetriminoInPlay->rotateLeft();
				}
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down) {
				tetriminoInPlay->moveDown();
				if (well.tetriminoFit(*tetriminoInPlay) == false) {
					tetriminoInPlay->moveUp();
				}
			}
		}
		countDown--;
		std::cout << music.getStatus() <<sound.getStatus() << std::endl;
		//std::cout << countDown << std::endl;
		if (music.getStatus() == 1 && sound.getStatus() == 0) {
			music.play();
		}
		if (countDown == 0) {
			tetriminoInPlay->moveDown();
			countDown = 100;
			// check to see if it fits -- if not, move it back up and call addTetriminoToWell
			if (well.tetriminoFit(*tetriminoInPlay) == false) {
				std::cout << "I've been trigered" << std::endl;
				tetriminoInPlay->moveUp();
				well.addTetriminoToWell(*tetriminoInPlay);

				// delete the memory allocated for tetriminoInPlay
				delete tetriminoInPlay;

				// clear any full rows
				if (well.clearFullRows() > 0) {
					music.pause();
					sound.play();

				}

				//TODO: update the score

				//TODO: check to see if game is over (was the top reached?)

				//set tetriminoInPlay = tetriminoOnDeck
				tetriminoInPlay = tetriminoOnDeck;

				// set its location to the top/middle of the well
				tetriminoInPlay->setLocation(0, 2);

				// allocate memory for a new tetriminoOnDeck
				tetriminoOnDeck = new Tetrimino;
				std::cout << "Up Next: " << std::endl;
				tetriminoOnDeck->dataDump();
			}
		}

		window.clear();
		drawWell(well, LAYOUT_BOARD_TOP, LAYOUT_BOARD_LEFT, BLOCK_SIZE_PIXELS);
		drawTetrimino(tetriminoInPlay, LAYOUT_BOARD_TOP, LAYOUT_BOARD_LEFT, BLOCK_SIZE_PIXELS);
		window.display();
	}
}
bool Game::processGameOverScreen() {
	return true;
}

//================================================================
// In the main function, we launch the game by activating the game
// object. 
//================================================================
int main() {
	Game game;
	game.playGame();
}