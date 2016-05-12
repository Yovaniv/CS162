#include "clock.h"
#include <iostream>

Clock::Clock(){
	hour=12;
	minute=0;
	second=0;
}

bool Clock::setTime(int hour, int minute, int sceound){
	//Check if not valid
	if (hour < 1 || hour > 12){
		return false;
	}
	if (minute < 0 || minute > 59){
		return false;
	}

	if (sceound < 0 || sceound > 59){
		return false;
	}

	this->hour=hour;
	this->minute=minute;
	this->second=second;

	return true;
}

int Clock::getHour() const {
	return 0;
}

int Clock::getMinute() const{
	return 0;
}

int Clock::getSecond() const{
	return 0;
}

void Clock::showClock(){
	std::cout << hour << ':' << minute << ':' << second;
}

void Clock::tick(){

}

int main(){
	Clock bigBen;
	//bigBen.showClock();
	bigBen.setTime(0,0,0);
	bigBen.setTime(2,59,0);
	bigBen.showClock();
	getchar();
}