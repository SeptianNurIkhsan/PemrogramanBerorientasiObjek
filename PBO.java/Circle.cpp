#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

class Circle {
private:
   double radius;
   std::string color;
   
public:
   Circle() {
      radius = 1.0;
      color = "red";
   }
   
   Circle(double r) {
      radius = r;
      color = "red";
   }
   
   Circle(double r, std::string c) {
      radius = r;
      color = c;
   }
   
   double getRadius() {
      return radius;
   }
   
   std::string getColor() {
      return color;
   }
   
   double getArea() {
      return radius * radius * M_PI;
   }
};

int main() {
   Circle circle1;
   Circle circle2(2.5);
   Circle circle3(3.0, "blue");
   
   std::cout << "Circle 1: Radius = " << circle1.getRadius() << ", Color = " << circle1.getColor() << ", Area = " << circle1.getArea() << std::endl;
   std::cout << "Circle 2: Radius = " << circle2.getRadius() << ", Color = " << circle2.getColor() << ", Area = " << circle2.getArea() << std::endl;
   std::cout << "Circle 3: Radius = " << circle3.getRadius() << ", Color = " << circle3.getColor() << ", Area = " << circle3.getArea() << std::endl;
   
   return 0;
}