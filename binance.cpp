#include <iostream>
#include <string>

class BankAccount {
private:
    std::string accountHolder;
    int accountNumber;
    double balance;
    std::string password;
public:
    BankAccount(std::string name, int number, double initialBalance, std::string pass) {
        accountHolder = name;
        accountNumber = number;
        balance = initialBalance;
        password = pass;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    bool verifyPassword(std::string inputPassword) {
        return inputPassword == password;
    }

    void menu() {
        while (true)
        {
            int choice;

            std::cout << "\n";
            std::cout << accountHolder << ", добро пожаловать в банк!" << std::endl;
            std::cout << "1. Узнать баланс" << std::endl;
            std::cout << "2. Пополнить счет" << std::endl;
            std::cout << "3. Снятие денег" << std::endl;
            std::cout << "4. Узнать номер счета" << std::endl;
            std::cout << "5. Выход" << std::endl;
            std::cout << "Выберите опцию: ";
            std::cin >> choice;

            if (choice == 1) {
                getBalance();
            }
            else if (choice == 2)
            {
                deposit();
            }
            else if (choice == 3)
            {
                withdraw();
            }
            else if (choice == 4)
            {
                id();
            }
            else if (choice == 5)
            {
                break;
            }
                
        }
    }
    void getBalance() {
        std::cout << "Ваш баланс: " << balance << std::endl;
    }
    void deposit() {
        double amount;

        std::cout << "Введите сумму на которую хотите поплнить баланс: ";
        std::cin >> amount;

        balance = balance + amount;
        std::cout << "Ваш баланс: " << balance << std::endl;
    }
    void withdraw() {
        double amount;

        std::cout << "Введите сумму которую хотите снять: ";
        std::cin >> amount;

        if (amount > balance) {
            std::cout << "Ошибка! Недостаточно средств!" << std::endl;
        } else
        {
            balance = balance - amount;
            std::cout << "Вы сняли: " << amount << " рублей" << std::endl;
            std::cout << "Ваш баланс: " << balance << std::endl;
        }  
    }
    void id() {
        std::cout << "Счет аккаунта: " << accountNumber << std::endl;
    }
};

int main() {
    BankAccount alexey("Алексей Морозов", 298167234, 46781.85, "Alexei1234");
    BankAccount ivan("Иван Петрович", 556141860, 86843.47, "IvanPetrovich4321");

    int inputNumber;
    std::cout << "Введите номер вашего счета: ";
    std::cin >> inputNumber;

    BankAccount* currentAccount = nullptr; 

    if (inputNumber == alexey.getAccountNumber()) {
        currentAccount = &alexey;
    } else if (inputNumber == ivan.getAccountNumber()) {
        currentAccount = &ivan;
    } else {
        std::cout << "Аккаунт с таким номером не найден!" << std::endl;
        return 0;
    }

    std::string inputPass;
    std::cout << "Введите пароль: ";
    std::cin >> inputPass;

    if (currentAccount->verifyPassword(inputPass)) {
        std::cout << "Успешный вход!" << std::endl;
        currentAccount->menu();
    } else {
        std::cout << "Неверный пароль!" << std::endl;
    }

    return 0;
}