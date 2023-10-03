#include <iostream>
#include <iomanip>  // Diperlukan untuk std::setw

class Date {
private:
    int year;
    int month;
    int day;

public:
    Date(int year, int month, int day) {
        this->year = year;
        this->month = month;
        this->day = day;
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

    int getYear() const {
        return year;
    }

    int getMonth() const {
        return month;
    }

    int getDay() const {
        return day;
    }

    void setDate(int year, int month, int day) {
        this->year = year;
        this->month = month;
        this->day = day;
    }
};

// Fungsi operator<< untuk mencetak objek Date
std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << std::setw(4) << date.getYear() << '-';
    os << std::setw(2) << date.getMonth() << '-';
    os << std::setw(2) << date.getDay();
    return os;
}

int main() {
    Date d1(2020, 2, 8);
    std::cout << d1 << std::endl;

    d1.setYear(2012);
    d1.setMonth(12);
    d1.setDay(23);
    std::cout << d1 << std::endl;

    std::cout << "Year is: " << d1.getYear() << std::endl;
    std::cout << "Month is: " << d1.getMonth() << std::endl;
    std::cout << "Day is: " << d1.getDay() << std::endl;

    d1.setDate(2988, 1, 2);
    std::cout << d1 << std::endl;

    return 0;
}
