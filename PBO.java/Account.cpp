#include <iostream>
#include <string>

class Account {
private:
   int number;
   double balance;

public:
   Account(int number) {
      this->number = number;
      this->balance = 0.0;  
   }
   
   Account(int number, double balance) {
      this->number = number;
      this->balance = balance;
   }
   
   int getNumber() {
      return this->number;  
   }
   
   double getBalance() {
      return this->balance;  
   }
   
   std::string toString() {
      return "Account[number=" + std::to_string(number) + ",balance=$" + std::to_string(balance) + "]";
   }
   
   void credit(double amount) {
      balance += amount;
   }
};