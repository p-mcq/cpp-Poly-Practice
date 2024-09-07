#include <iostream>

class Account
{
public:
    virtual void withdraw(double amount) { std::cout << "Account::withdraw" << std::endl; }
    virtual ~Account() {}
};

class Checking : public Account
{
public:
    virtual void withdraw(double amount) { std::cout << "Checking::withdraw" << std::endl; }
    virtual ~Checking() {}
};

class Savings : public Account
{
public:
    virtual void withdraw(double amount) { std::cout << "Savings::withdraw" << std::endl; }
    virtual ~Savings() {}
};

class Trust : public Account
{
public:
    virtual void withdraw(double amount) { std::cout << "Trust::withdraw" << std::endl; }
    virtual ~Trust() {}
};

void doWithdrawal(Account &account, double amount = 1000)
{
    account.withdraw(amount);
}

int main()
{
    Account a;
    Account &ref = a;
    ref.withdraw(1000);

    Checking c;
    Account &ref1 = c;
    ref1.withdraw(1000);

    Savings s;
    Trust t;

    doWithdrawal(a);
    doWithdrawal(c);
    doWithdrawal(s);
    doWithdrawal(t);
    
    return 0;
}