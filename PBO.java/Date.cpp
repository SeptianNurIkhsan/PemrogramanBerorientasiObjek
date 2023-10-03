#include <iostream>
#include <string>
using namespace std;

class Date {
private:
   int year, month, day;

public:
   Date(int year, int month, int day) {
      this->year = year;
      this->month = month;
      this->day = day;
   }

   int getYear() {
      return this->year;
   }

   int getMonth() {
      return this->month;
   }

   int getDay() {
      return this->day;
   }

   void setYear(int year) {
      this->year = year;
   }

   void setMonth(int month) {
      this->month = month;
   }

   void setDay(int day) {
      this->day = day;
   }

   string toString() {
      return to_string(month) + "/" + to_string(day) + "/" + to_string(year);
   }

   void setDate(int year, int month, int day) {
      this->year = year;
      this->month = month;
      this->day = day;
   }
};

int main() {
   Date date(2022, 10, 31);
   cout << date.toString() << endl;
   return 0;
}