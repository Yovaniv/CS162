#ifndef CLOCK_H
#define CLOCK_H

 class Clock {  
public:  
 //constructor  
 Clock();   
   
 //mutators  
 bool setTime(int hour, int Minute, int Second);  
   
 //accessors  
 int getHour() const;  
 int getMinute() const;  
 int getSecond() const;  
   
 //other  
 void showClock(); // Displays the clock  
 void tick(); //add one second to the clock  
 private:  
 int hour;     // 1-12  
 int minute;   // 0-59  
 int second;   // 0-59  
 };  
#endif