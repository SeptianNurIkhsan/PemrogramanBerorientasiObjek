#include <iostream>
#include <iomanip>
#include <string>

class Circle {
private:
    double radius;
    std::string color;

public:
    Circle(double r = 0.0, std::string c = "") : radius(r), color(c) {}

    double getRadius() {
        return radius;
    }

    std::string getColor() {
        return color;
    }

    double getArea() {
        return 3.14159 * radius * radius;
    }
};

int main() {
    Circle c1(2.0, "blue");
    std::cout << "The radius is: " << c1.getRadius() << std::endl;
    std::cout << "The color is: " << c1.getColor() << std::endl;
    std::cout << "The area is: " << std::fixed << std::setprecision(2) << c1.getArea() << std::endl;

    Circle c2(2.0);
    std::cout << "The radius is: " << c2.getRadius() << std::endl;
    std::cout << "The color is: " << c2.getColor() << std::endl;
    std::cout << "The area is: " << std::fixed << std::setprecision(2) << c2.getArea() << std::endl;

    Circle c3;
    std::cout << "The radius is: " << c3.getRadius() << std::endl;
    std::cout << "The color is: " << c3.getColor() << std::endl;
    std::cout << "The area is: " << std::fixed << std::setprecision(2) << c3.getArea() << std::endl;

    return 0;
}