//========================================================================
//Program:		StringDemo
//Author:		Austin Parrish
//Date:			01/07/2016
//Dev Env:		ICC
//Description:	
//========================================================================

//Remove Micro$oft's training wheels (Windows Only)
#define _CRT_SECURE_NO_WARNINGS

//Decalir header files
#include <iostream>
#include <string.h>
#include <string>

//Declair functions
void cStringDemo();
void stringTypeDemo();
char removeVowels(char* userName, char* holder);

//Declair namespace
using namespace std;

//Declair const
const int MAX_STRING_SIZE = 25;

//Main Function
int main (void){
	//Call cStringDemo function
	cStringDemo();

	//Call stringTypeDemo function
	stringTypeDemo();
}

//================================================================
// Function:		cStringDemo
// Description:		Output's data using cStrings
// Arguments:		N/A
// Return value:	Void
//================================================================
void cStringDemo(){
	//Declair vars
	char myName[15] = "Austin Parrish";
	char userName[MAX_STRING_SIZE];
	char noVowels[MAX_STRING_SIZE];

	// Ask the user to guess my name
	cout << "Say my name (first last): ";
	
	//Get users input
	cin.get (userName, MAX_STRING_SIZE);

	//Check if user guessed right
	if (strcmp(userName, myName) == 0){
		cout << "You smart. You're loyal. You're grateful. I appreciate that. Go buy your mama a house." << endl;
	}else{
		cout << "Nice try, but incorrect" << endl;
	}
	//Output what user entered
	cout << "You name you entered was: " << userName << endl;

	//Remove vowls
	removeVowels(userName, noVowels);
}

//================================================================
// Function:    isOdd
// Description: determines if given number is odd
// Arguments: 
// 	num (I) - number to check
// Return value: 
// 	true if number is odd, false if number is even
//================================================================
void stringTypeDemo(){
	
}


char removeVowels(char* userName, char* holder){
	char vowl[11] = "AaEeIiOoUu";
	bool check=false;

	for (int i = 0; i < strlen(userName); i++){
		for (int j = 0; j < strlen(vowl); j++){
			if (userName[i] == vowl[j]){
				check = true;
			}
		}
		if (check == true){
			cout << "*";
			check = false;
		}else{
			cout << userName[i];
		}
	}
	return 3;
}
