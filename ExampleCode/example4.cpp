// In-Class Example code 4
// By Austin Parrish
// 01/14/16
// Code we wrote in class

#include<iostream>
#include<iomanip>

using namespace std;
const int ROWS = 10;
const int COLS = 10;

void initializeAllValues(int data[][COLS], int numOfRows);
void print(const int data[][COLS], int numOfRows);

int main (void){
	int timesTable[ROWS][COLS];
	initializeAllValues(timesTable, ROWS);
	print(timesTable, ROWS);
}

void initializeAllValues(int data[][COLS], int numOfRows){
	for (int i =0; i < numOfRows; i++){
		for (int j = 0; j < COLS; j++){
			data[i][j] = (i+1)*(j+1);
		}
	}
}

void print(const int data[][COLS], int numOfRows){
	for (int i =0; i < numOfRows; i++){
		for (int j = 0; j < COLS; j++){
			cout << setw(3) << data[i][j] << " ";
		}
		cout << endl;
	}
}
