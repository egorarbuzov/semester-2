#include <iostream>
#include <string>

typedef std::string AccountNumber;
typedef std::string DepositType;
typedef double Balance;
typedef std::string OpeningDate;
typedef std::string Owner;
typedef bool SmsNotification;
typedef bool InternetBanking;

struct BankAccount {
    AccountNumber accountNumber;
    DepositType depositType;
    Balance balance;
    OpeningDate openingDate;
    Owner owner;
    SmsNotification smsNotification;
    InternetBanking internetBanking;
};

BankAccount& operator+(BankAccount& acc, double amount) {
    if (amount > 0) {
        acc.balance += amount;
        std::cout << "Пополнено на " << amount << ". Новый баланс: " << acc.balance << std::endl;
    }
    return acc;
}

bool operator==(const BankAccount& acc1, const BankAccount& acc2) {
    if (acc1.balance == acc2.balance) {
        std::cout << "Балансы счетов равны" << std::endl;
        return true;
    } else if (acc1.balance > acc2.balance) {
        std::cout << "Первый счет больше второго" << std::endl;
        return false;
    } else {
        std::cout << "Первый счет меньше второго" << std::endl;
        return false;
    }
}

int main() {
    BankAccount myAccount;
    myAccount.accountNumber = "1";
    myAccount.depositType = "Сберегательный";
    myAccount.balance = 10000.0;
    myAccount.openingDate = "12.03.2026";
    myAccount.owner = "Арбузов Е. А.";
    myAccount.smsNotification = true;
    myAccount.internetBanking = true;
    
    BankAccount anotherAccount;
    anotherAccount.accountNumber = "2";
    anotherAccount.depositType = "Текущий";
    anotherAccount.balance = 20000.0;
    anotherAccount.openingDate = "12.03.2026";
    anotherAccount.owner = "Иванов И. И.";
    anotherAccount.smsNotification = false;
    anotherAccount.internetBanking = false;
    
    myAccount + 5000.00;
    std::cout << myAccount.balance << std::endl;
    bool equal = myAccount == anotherAccount;
    std::cout << equal << std::endl;
    
    return 0;
}
