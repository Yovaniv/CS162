// In-Class Example code 2
// By Austin Parrish
// 01/07/16
// Code we wrote in class

#include <iostream>
#include <string>

using namespace std;

int main (void){
	string favoriteName = "Spot";
	string petName;

	cout << "Enter your pets name: ";
	getline(cin, petName);

	cout << favoriteName << endl;
	cout << petName << endl;

	if (favoriteName == petName){
		cout << "Same" << endl;
	}else{
		cout << "NOT Same" << endl;
	}

	cout << petName[0] << endl;


	for (int i = petName.length()-1; i >=0 ; --i){
		cout << petName[i];
	}

	cout << endl;
}
