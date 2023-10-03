#include <iostream>

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
        return number;
    }

    double getBalance() {
        return balance;
    }

    void credit(double amount) {
        balance += amount;
    }

    void debit(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            std::cout << "Insufficient funds" << std::endl;
        }
    }

    void transferTo(double amount, Account& destination) {
        if (amount <= balance) {
            balance -= amount;
            destination.credit(amount);
        } else {
            std::cout << "Insufficient funds" << std::endl;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Account& account) {
        os << "Account Number: " << account.number << ", Balance: " << account.balance;
        return os;
    }
};

int main() {
    Account a1(5566);
    std::cout << a1 << std::endl;

    Account a2(1234, 99.9);
    std::cout << a2 << std::endl;

    std::cout << "The account Number is: " << a2.getNumber() << std::endl;

    std::cout << "The balance is: " << a2.getBalance() << std::endl;

    a1.credit(11.1);
    std::cout << a1 << std::endl;

    a1.debit(5.5);
    std::cout << a1 << std::endl;

    a1.debit(500);

    std::cout << a1 << std::endl;

    a2.transferTo(1.0, a1);
    std::cout << a1 << std::endl;

    std::cout << a2 << std::endl;

    return 0;
}