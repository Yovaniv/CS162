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

//Declair functions
void cStringDemo();
void stringTypeDemo();

//Declair namespace
using namespace std;

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
	char userName[15];

	// Ask the user to guess my name
	cout << "Say my name (first last): ";
	
	//Get users input
	cin.get (userName,15);

	if (strcmp(userName, myName) == 0){
		cout << "You smart. You're loyal. You're grateful. I appreciate that. Go buy your mama a house." << endl;
	}else{
		cout << "Nice try, but incorrect" << endl;
	}

	cout << "You name you entered was: " << userName << endl;


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
