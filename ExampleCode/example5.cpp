// In-Class Example code 5
// By Austin Parrish
// 01/19/16
// Code we wrote in class
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

struct Car{
	string make;
	string model;
	int year;
	int mileage;
	float price;
};

struct MyPoint {
	float x;
	float y;
}; 

void outputVector(MyPoint point);
float pointDistance(MyPoint point1, MyPoint point2);
int sumOfVectors(MyPoint point1, MyPoint point2);
MyPoint findVector(int angle, int magnitude);

int main (void){
	MyPoint point1={1,7};
	MyPoint point2;
	MyPoint point3;

	point2.x=M_PI;

	cout << point2.x << endl;

	MyPoint vector1 = {1,2};
	MyPoint vector2 = {4,3};

	outputVector(vector1);
	outputVector(vector2);

	cout << "The distance betwee the two points is: " << pointDistance(vector1, vector2) << endl;

	cout << "The sum of the two points is: " << sumOfVectors(vector1, vector2) << endl;

	cout << "vector x: " << findVector(80,3).x << " y: " << findVector(80,3).y << endl;
}

void outputVector(MyPoint point){
	cout << "vector x: " << point.x << " y: " << point.y << endl;
}

float pointDistance(MyPoint point1, MyPoint point2){
	return sqrt((pow((point2.x-point1.x),2)) + (pow((point2.y-point1.y),2)));
}

int sumOfVectors(MyPoint point1, MyPoint point2){
	return ((point1.x+point2.x)+(point1.y+point2.y));
}

MyPoint findVector(int angle, int magnitude){
	MyPoint point;
	point.x=(3*cos(angle));
	point.y=(3*sin(angle));

	return point;
}
