#include <iostream>
using namespace std;

class Time {
private:
    int hour;
    int minute;
    int second;
public:
    Time(int h, int m, int s) {
        hour = h;
        minute = m;
        second = s;
    }
    
    Time() {
        hour = 0;
        minute = 0;
        second = 0;
    }
    
    void setHour(int h) {
        hour = h;
    }
    
    void setMinute(int m) {
        minute = m;
    }
    
    void setSecond(int s) {
        second = s;
    }
    
    int getHour() {
        return hour;
    }
    
    int getMinute() {
        return minute;
    }
    
    int getSecond() {
        return second;
    }
    
    void setTime(int h, int m, int s) {
        hour = h;
        minute = m;
        second = s;
    }
    
    string toString() {
        return to_string(hour) + ":" + to_string(minute) + ":" + to_string(second);
    }
    
    Time nextSecond() {
        second++;
        if (second >= 60) {
            second = 0;
            minute++;
            if (minute >= 60) {
                minute = 0;
                hour++;
                if (hour >= 24) {
                    hour = 0;
                }
            }
        }
        return *this;
    }
};

int main() {
    Time t1(1, 2, 3);
    cout << t1.toString() << endl;
    
    Time t2;
    cout << t2.toString() << endl;
    
    t1.setHour(4);
    t1.setMinute(5);
    t1.setSecond(6);
    cout << t1.toString() << endl;
    
    cout << "Hour is: " << t1.getHour() << endl;
    
    cout << "Minute is: " << t1.getMinute() << endl;
    
    cout << "Second is: " << t1.getSecond() << endl;
    
    t1.setTime(58, 59, 23);
    cout << t1.toString() << endl;
    
    cout << t1.nextSecond().toString() << endl;
    
    cout << t1.nextSecond().nextSecond().nextSecond().toString() << endl;
    
    return 0;
}