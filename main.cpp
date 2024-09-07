#include <iostream>
#include <vector>
using std::cout, std::endl;

class Account
{
public:
    virtual void withdraw(double amount) const
    {
        cout << "In Account::withdraw" << endl;
    }
    virtual ~Account() {}
};

class Checking : public Account
{
public:
    virtual void withdraw(double amount) const override
    {
        cout << "In Checking::withdraw" << endl;
    }
    virtual ~Checking() {}
};

class Savings : public Account
{
    virtual void withdraw(double amount) const override
    {
        cout << "In Savings::withdraw" << endl;
    }
    virtual ~Savings() {}
};

class Trust : public Account
{
    virtual void withdraw(double amount) const override
    {
        cout << "In Trust::withdraw" << endl;
    }
    virtual ~Trust() {}
};

int main()
{
    Account *ptrToAccount = new Account();
    Account *ptrToChecking = new Checking();
    Account *ptrToSavings = new Savings();
    Account *ptrToTrust = new Trust();

    cout << "\nWithdraw 1000 from each Account type" << endl;
    cout << "=====================================" << endl;
    ptrToAccount->withdraw(1000);  // In Account::withdraw
    ptrToChecking->withdraw(1000); // In Checking::withdraw
    ptrToSavings->withdraw(1000);  // In Savings::withdraw
    ptrToTrust->withdraw(1000);    // In Trust::withdraw

    cout << "\nCreate an array and display the withdraw method" << endl;
    cout << "=====================================" << endl;
    Account *array[] = {ptrToAccount, ptrToChecking, ptrToSavings, ptrToTrust};
    for (auto i = 0; i < std::size(array); i++)
    {
        array[i]->withdraw(1000);
    }

    cout << "\nCreate a vector and display the withdraw method" << endl;
    cout << "=====================================" << endl;
    std::vector<Account *> accounts{ptrToAccount, ptrToChecking, ptrToSavings, ptrToTrust};
    for (auto account : accounts)
    {
        account->withdraw(1000);
    }
    accounts.push_back(ptrToTrust);
    accounts.push_back(ptrToSavings);
    for (auto account : accounts)
    {
        account->withdraw(1000);
    }

    cout << "\nDelete pointers" << endl;
    cout << "================" << endl;
    delete ptrToAccount;
    delete ptrToChecking;
    delete ptrToSavings;
    delete ptrToTrust;
}