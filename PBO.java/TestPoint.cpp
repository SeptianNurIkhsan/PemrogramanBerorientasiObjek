#include <iostream>
#include <iomanip>
#include <cmath>

class Point {
private:
    double x;
    double y;

public:
    Point(double x = 0, double y = 0) : x(x), y(y) {}

    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

    void setX(double x) {
        this->x = x;
    }

    void setY(double y) {
        this->y = y;
    }

    void setXY(double x, double y) {
        this->x = x;
        this->y = y;
    }

    double* getXY() const {
        double* xy = new double[2];
        xy[0] = x;
        xy[1] = y;
        return xy;
    }

    double distance(double x, double y) const {
        double dx = this->x - x;
        double dy = this->y - y;
        return sqrt(dx * dx + dy * dy);
    }

    double distance(const Point& p) const {
        return distance(p.getX(), p.getY());
    }

    double distance() const {
        return distance(0, 0);
    }

    // Operator << untuk mencetak objek Point
    friend std::ostream& operator<<(std::ostream& os, const Point& point);
};

// Implementasi fungsi operator<<
std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "(" << point.getX() << ", " << point.getY() << ")";
    return os;
}

int main() {
    Point p1(1, 2);
    std::cout << p1 << std::endl;

    Point p2;
    std::cout << p2 << std::endl;

    p1.setX(3);
    p1.setY(4);
    std::cout << p1 << std::endl;

    std::cout << "X is: " << p1.getX() << std::endl;
    std::cout << "Y is: " << p1.getY() << std::endl;

    p1.setXY(5, 6);
    std::cout << p1 << std::endl;

    std::cout << "X is: " << p1.getXY()[0] << std::endl;
    std::cout << "Y is: " << p1.getXY()[1] << std::endl;

    p2.setXY(10, 11);
    printf("Distance is: %.2f\n", p1.distance(10, 11));
    printf("Distance is: %.2f\n", p1.distance(p2));
    printf("Distance is: %.2f\n", p2.distance(p1));
    printf("Distance is: %.2f\n", p1.distance());

    return 0;
}
