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
		{false,false,false,false},
		{false,false,false,true},
		{true,true,true,true}};
	
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
	cout << "rotated 90 degrees to the Left:" << endl;

	cout << "2nd Array:" << endl;
	dumpData(tetrimino2);
	cout << "rotated 90 degrees to the right:" << endl;
	cout << "rotated 90 degrees to the Left:" << endl;

	cout << "3rd Array:" << endl;
	dumpData(tetrimino3);
	cout << "rotated 90 degrees to the right:" << endl;
	cout << "rotated 90 degrees to the Left:" << endl;

	cout << "4th Array:" << endl;
	dumpData(tetrimino4);
	cout << "rotated 90 degrees to the right:" << endl;
	cout << "rotated 90 degrees to the Left:" << endl;
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


void rotateLeft(const bool tetrimino[MAX_ROWS][MAX_COLS]){
	
}

void rotateRight(const bool tetrimino[MAX_ROWS][MAX_COLS]){

}
