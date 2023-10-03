#include <iostream>
#include <string>

class Time {
private:
   int second, minute, hour;

public:
   Time(int second, int minute, int hour) {
      this->second = second;
      this->minute = minute;
      this->hour = hour;
   }

   Time() {
      this->second = 0;
      this->minute = 0;
      this->hour = 0;
   }

   int getSecond() {
      return this->second;
   }

   int getMinute() {
      return this->minute;
   }

   int getHour() {
      return this->hour;
   }

   void setSecond(int second) {
      this->second = second;
   }

   void setMinute(int minute) {
      this->minute = minute;
   }

   void setHour(int hour) {
      this->hour = hour;
   }

   std::string toString() {
      // TODO: Implement toString() method
   }
};