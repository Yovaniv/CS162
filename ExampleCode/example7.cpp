#include <iostream>
//----------------------------------------------------------
class Pig{
public:
	Pig(){
		weight=0;
		alive=true;
		std::cout << "Hello Pig" << std::endl;
	}
private:
	int weight;
	bool alive;
};
//----------------------------------------------------------
class Cow{
public:
	Cow(){
		weight=0;
		alive=true;
		std::cout << "Hello Cow" << std::endl;
	}
private:
	int weight;
	bool alive;
};
//----------------------------------------------------------
class Farm{
public:
	Farm(){
		std::cout << "Welcome to my farm fam!" << std::endl;
	}
private:
	Pig bestPig;
	Cow cows[3];
};
//----------------------------------------------------------
int main(void){
	Farm tomsFarm;
	getchar();
	return EXIT_SUCCESS;
}