#include <iostream>

using namespace std;

const int MAX_ROWS = 4;
const int MAX_COLS = 4;

void dumpData(const bool tetrimino[MAX_ROWS][MAX_COLS]);
void rotateLeft(bool tetrimino[MAX_ROWS][MAX_COLS]);
void rotateRight(bool tetrimino[MAX_ROWS][MAX_COLS]);
void outputData(bool tetrimino[MAX_ROWS][MAX_COLS], int tetriminoNum);

int main (void){
	bool tetrimino1[MAX_ROWS][MAX_COLS] = {
		{false,false,false,false},
		{false,true,false,false},
		{false,true,true,true},
		{false,false,false,false}};
	
	bool tetrimino2[MAX_ROWS][MAX_COLS] = {
		{false,false,false,false},
		{false,false,false,false},
		{false,true,false,false},
		{true,true,true,false}};

	bool tetrimino3[MAX_ROWS][MAX_COLS] = {false};
	for (int i = 0; i < 4; i++){
		tetrimino3[3][i] = true;
	}

	bool tetrimino4[MAX_ROWS][MAX_COLS] = {false};
	for (int i = 0; i < 4; i++){
		tetrimino4[i][0] = true;
	}

	outputData(tetrimino1,1);
	outputData(tetrimino2,2);
	outputData(tetrimino3,3);
	outputData(tetrimino4,4);
}

void dumpData(const bool tetrimino[MAX_ROWS][MAX_COLS]){
	for (int i = 0; i < MAX_ROWS; i++){
		for (int j = 0; j < MAX_COLS; j++){
			if (tetrimino[i][j] == true){
				cout << "#";
			}else{
				cout << " ";
			}
		}
		cout << endl;
	}
}


void rotateRight(bool tetrimino[MAX_ROWS][MAX_COLS]){
	bool holder[MAX_ROWS][MAX_COLS];
	for (int row = 3; row >= 0; row--){
		for (int col = 0; col < MAX_COLS; col++){
			if (tetrimino[row][col]==true){
				holder [col][3-row] = true;
			}else{
				holder [col][3-row] = false;
			}
		}
	}
	for (int i = 0; i < MAX_ROWS; i++){
		for (int j = 0; j < MAX_COLS; j++){
			tetrimino[i][j]=holder[i][j];
		}
	}
}

void rotateLeft(bool tetrimino[MAX_ROWS][MAX_COLS]){
	bool holder[MAX_ROWS][MAX_COLS];
	for (int row = 0; row < MAX_ROWS; row++){
		for (int col = 3; col >= 0; col--){
			if (tetrimino[row][col]==true){
				holder [3-col][row] = true;
			}else{
				holder [3-col][row] = false;
			}
		}
	}
	for (int i = 0; i < MAX_ROWS; i++){
		for (int j = 0; j < MAX_COLS; j++){
			tetrimino[i][j]=holder[i][j];
		}
	}
}

void outputData(bool tetrimino[MAX_ROWS][MAX_COLS], int tetriminoNum){
	switch(tetriminoNum){
	case 1:
		cout << tetriminoNum <<"st Array:" << endl;
		break;
	case 2:
		cout << tetriminoNum <<"nd Array:" << endl;
		break;
	case 3:
		cout << tetriminoNum <<"nd Array:" << endl;
		break;
	default:
		cout << tetriminoNum <<"th Array:" << endl;
	}

	dumpData(tetrimino);
	cout << "rotated 90 degrees to the right:" << endl;
	rotateRight(tetrimino);
	dumpData(tetrimino);
	cout << "rotated 90 degrees to the Left:" << endl;
	rotateLeft(tetrimino);
	rotateLeft(tetrimino);
	dumpData(tetrimino);
}

