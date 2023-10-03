#include <iostream>
#include <cmath>

class Point {
private:
   int x, y;
   
public:
   Point() {
      this->x = 0;
      this->y = 0;
   }
   
   Point(int x, int y) {
      this->x = x;
      this->y = y;
   }
   
   int getX() {
      return this->x;
   }
   
   void setX(int x) {
      this->x = x;
   }
   
   int getY() {
      return this->y;
   }
   
   void setY(int y) {
      this->y = y;
   }
   
   std::string toString() {
      return "(" + std::to_string(this->x) + "," + std::to_string(this->y) + ")";
   }
   
   int* getXY() {
      int* results = new int[2];
      results[0] = this->x;
      results[1] = this->y;
      return results;
   }
   
   void setXY(int x, int y) {
      this->x = x;
      this->y = y;
   }
   
   double distance(int x, int y) {
      int xDiff = this->x - x;
      int yDiff = this->y - y;
   }
};