#include <iostream>

using namespace std;

const int MAX_ROWS = 4;
const int MAX_COLS = 4;

void dumpData(const bool tetrimino[MAX_ROWS][MAX_COLS]);
void rotateLeft(const bool tetrimino[MAX_ROWS][MAX_COLS]);
void rotateRight(const bool tetrimino[MAX_ROWS][MAX_COLS]);

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

	cout << "1st Array:" << endl;
	dumpData(tetrimino1);
	cout << "rotated 90 degrees to the right:" << endl;
	rotateRight(tetrimino1);
	cout << "rotated 90 degrees to the Left:" << endl;
	rotateLeft(tetrimino1);
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


void rotateRight(const bool tetrimino[MAX_ROWS][MAX_COLS]){
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
	dumpData(holder);
}

void rotateLeft(const bool tetrimino[MAX_ROWS][MAX_COLS]){
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
	dumpData(holder);
}
