//========================================================================
//Program:		StringDemo
//Author:		Austin Parrish
//Date:			01/07/2016
//Dev Env:		ICC
//Description:		Ask the user to guess the name, then manipulate
//			that string in multiple ways
//========================================================================

//Remove Micro$oft's training wheels (Windows Only)
#define _CRT_SECURE_NO_WARNINGS

//Declare header files
#include <iostream>
#include <string.h>
#include <string>

//Declare namespace
using namespace std;

//Declare functions
void cStringDemo();
void stringTypeDemo();
char* removeVowels(char* userString);
string removeVowels(string userString);

//Declare const
const int MAX_STRING_SIZE = 25;

//Main Function
int main (void){
	//Call cStringDemo function
	cout << "cString Demo:" << endl;
	cStringDemo();

	
	//Call stringTypeDemo function
	cout << "String Demo:" << endl;
	stringTypeDemo();
}

//================================================================
// Function:		cStringDemo
// Description:		Output's data using cStrings
// Arguments:		N/A
// Return value:	Void
//================================================================
void cStringDemo(){
	//Declare vars
	char myName[15] = "Austin Parrish";
	char userString[MAX_STRING_SIZE];
	char userStringBarbarian[MAX_STRING_SIZE + 15];

	//Ask the user to guess my name
	cout << "Say my name (first last): ";
	
	//Get users input
	cin.get (userString, MAX_STRING_SIZE);

	//Check if user guessed right
	if (strcmp(userString, myName) == 0){
		cout << "You smart. You're very smart. Matter of fact, you're a genius." << endl;
	}else{
		cout << "Nice try, but incorrect" << endl;
	}
	//Output what user entered
	cout << "You guessed " << userString << endl;

	//Remove vowels
	cout << "Without vowels, that's " << removeVowels(userString) << endl;
	
	//Add the barbarian text next to users name
	strcpy(userStringBarbarian, userString);
	strcat(userStringBarbarian, " the Barbarian");
	
	//Output text
	cout << "And in less civilized times, it would be " << userStringBarbarian << endl;
}

//================================================================
// Function:		stringTypeDemo
// Description:		Output's data using Strings
// Arguments:		N/A
// Return value:	Void
//================================================================
void stringTypeDemo(){
	//Declare vars
	string myName = "Austin Parrish";
	string userString;
	string userStringBarbarian;

	//Ask user for name
	cout << "Say my name (first last): ";
	cin.get();
	getline(cin, userString);
	
	//Check if user was right
	if (userString==myName){
		cout << "You smart. You're loyal. You're grateful. I appreciate that. Go buy your mama a house." << endl;
	}else{
		cout << "Nice try, but incorrect" << endl;
	}
	
	//Output what user said
	cout << "You guessed " << userString << endl;
	
	//Output text without vowls
	cout << "Without vowels, that's " << removeVowels(userString) << endl;
	
	//Add barbarian text to users name
	userStringBarbarian = userString + " the Barbarian";
	cout << "And in less civilized times, it would be " << userStringBarbarian << endl;
}

//================================================================
// Function:    removeVowels (cString)
// Description: Removes vowels from a cString
// Arguments: 
// 	userString (I) - the input of the users cString
// Return value: 
// 	returns the string with no vowels
//================================================================
char* removeVowels(char* userString){
	//Declare vars
	char vowels[11] = "AaEeIiOoUu";
	bool check=false;
	static char holder[MAX_STRING_SIZE] = "";
	int stringCharCount=0;

	//Start a for loop that that will check each character and compare it to
	//any of the vowels in the vowel cString. We start our for loop by looping
	//through each character in the userString cString
	for (int i = 0; i < strlen(userString); i++){
		//From here, we will loop though each vowel to see if the current selected
		//character in the c string is a vowel.
		for (int j = 0; j < strlen(vowels); j++){
			//We will now compare both the current selected userString char with the 
			//current selected vowel to see if they match
			if (userString[i] == vowels[j]){
				//If they do match, we will set the check bool to true
				check = true;
			}
		}
		//If the char does not match, we will add it to the holder string
		if (check == false){
			holder[stringCharCount]=userString[i];
			stringCharCount++;
		}else{
			//If we do have a vowel, we set the check back to false and skip to the next character
			check = false;
		}
	}

	//Once the for loop is complete, we will return whatever we have in our holder
	return holder;
}

//================================================================
// Function:    removeVowels (String)
// Description: Removes vowels from a String
// Arguments: 
// 	userString (I) - the input of the users String
// Return value: 
// 	returns the string with no vowels
//================================================================
string removeVowels(string userString){
	string vowels = "AaEeIiOoUu";
	bool check=false;
	string holder;
	int stringCharCount=0;

	//Start a for loop that that will check each character and compare it to
	//any of the vowel in the vowel String. We start our for loop by looping
	//through each character in the userString cString
	for (int i = 0; i < userString.length(); i++){
		//From here, we will loop though each vowel to see if the current selected
		//character in the c string is a vowel.
		for (int j = 0; j < vowels.length(); j++){
			//We will now compare both the current selected userString char with the 
			//current selected vowel to see if they match
			if (userString[i] == vowels[j]){
				//If they do match, we will set the check bool to true
				check = true;
			}
		}
		//If the char does not match, we will add it to the holder string
		if (check == false){
			holder= holder + userString[i];
			stringCharCount++;
		}else{
			//If we do have a vowel, we set the check back to false and skip to the next character
			check = false;
		}
	}
	
	//Once the for loop is complete, we will return whatever we have in our holder
	return string(holder);
}
