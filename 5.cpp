#include <iostream>
#include <string>

using namespace std;

class BankAccount {
protected:
    string accountNumber;
    string ownerName;
    double balance;

public:
    BankAccount(string accountNumber, string ownerName, double initialBalance): accountNumber(accountNumber), ownerName(ownerName), balance(initialBalance) {}

    virtual ~BankAccount() = default;

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Пополнение на " << amount << " успешно. Баланс: " << balance << endl;
        } 
        else {
            cout << "Сумма пополнения должна быть положительной." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Снятие " << amount << " успешно. Баланс: " << balance << endl;
        } 
        else {
            cout << "Недостаточно средств или неверная сумма." << endl;
        }
    }

    void printAccountInfo() const {
        cout << "Номер счета: " << accountNumber << endl;
        cout << "Владелец: " << ownerName << endl;
        cout << "Баланс: " << balance << endl;
    }
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(string accountNumber, string ownerName, double initialBalance, double interestRate): BankAccount(accountNumber, ownerName, initialBalance), interestRate(interestRate) {}

    void applyInterest() {
        double interest = balance * interestRate / 100;
        balance += interest;
        cout << "Начислены проценты: " << interest << ". Новый баланс: " << balance << endl;
    }

    void printAccountInfo() const {
        BankAccount::printAccountInfo();
        cout << "Процентная ставка: " << interestRate << "%" << endl;
    }
};

int main() {
    BankAccount account1("12345", "Ядыкина ДМ", 1000);
    SavingsAccount account2("67890", "Михайлова СС", 2000, 5);

    account1.deposit(500);
    account1.withdraw(200);
    account1.printAccountInfo();

    account2.deposit(1000);
    account2.withdraw(500);
    account2.applyInterest();
    account2.printAccountInfo();

    return 0;
}
