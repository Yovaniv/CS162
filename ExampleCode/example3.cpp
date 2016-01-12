// In-Class Example code 3
// By Austin Parrish
// 01/12/16
// Code we wrote in class

#include <iostream>

using namespace std;

const int TOTAL_SALES_PEOPLE = 3;
const int TOTAL_STUDENTS = 24;
const int TOTAL_DAYS = 20;
const int PUZZLE_SIZE = 9;

int main (void){
	double monthlySales [TOTAL_SALES_PEOPLE][12] = {};
	bool studentAttendence [TOTAL_STUDENTS][TOTAL_DAYS];
	int sudoku[PUZZLE_SIZE][PUZZLE_SIZE] = {{0,0,0,0,0,0,0,0,0},
										   {0,0,0,0,0,0,0,0,0},
										   {0,0,0,0,4,0,0,0,0},
										   {0,0,0,0,0,0,0,0,0},
										   {0,0,0,0,0,0,0,0,0},
										   {0,0,0,0,0,0,0,0,5},
										   {0,0,0,0,0,0,0,0,0},
										   {0,0,0,0,0,0,0,0,0},
										   {0,0,0,0,0,0,0,0,0}};

	sudoku[5][3]=7;

	for (int row = 0; row < TOTAL_STUDENTS; row++){
		studentAttendence [row][0] = true;
	}
	
	for (int row = 0; row < TOTAL_STUDENTS; row++){
		for(int col=1; col < TOTAL_DAYS; col++){
			studentAttendence [row][0] = false;
		}
	}
}
