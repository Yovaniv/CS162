#include <iostream>

int main(){
	/*int number1=5;
	int number2=50;
	int number3=100;
	int number=7;
	int* intp=NULL;
	
	std::cout << &number1 << std::endl;
	std::cout << &number2 << std::endl;
	std::cout << &number3 << std::endl;
	
	std::cout << std::endl;

	intp = &number2;
	std::cout << intp << std::endl;
	std::cout << *intp << std::endl;
	
	intp++;
	std::cout << *intp << std::endl;
	
	intp = &number;
	
	std::cout << number << std::endl;
	std::cout << &number << std::endl;
	std::cout << intp << std::endl;
	std::cout << *intp << std::endl;
	
	*intp = *intp + 5;
	std::cout << *intp << std::endl;*/

	int* p1 = new int;  
	int* p2 = 0;  
	p2 = new int;  
	      
	*p1 = 7;  
	*p2 = 5;  
	std::cout << (*p1 + *p2) << std::endl;

	std::cout << std::endl;

	std::cout << &p1 << " -> " << p1 << std::endl;
	std::cout << &p2 << " -> " << p2 << std::endl;
	return 0;
}
