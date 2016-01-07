// In-Class Example code 1
// By Austin Parrish
// 01/05/16
// Code we wrote in class

#include <iostream>
#include <string>

using namespace std;
int main (void){
	char favoriteName[20] = "Spot";
	cout << favoriteName;
	
	char petName[20];
	cout << "What's your pet's name?" << endl;
	cin.get (petName,20);
	cout << endl << petName;

	if (strcmp(petName, favoriteName) == 0){
		cout << endl << "Same name!" << endl;
	}else{
		cout << endl << "NOT same name!" << endl;
	}

	cout << petName[0] << endl;

	for (int i = strlen(petName)-1; i >=0 ; --i){
		cout << petName[i];
	}
	
	cout << endl;
}
