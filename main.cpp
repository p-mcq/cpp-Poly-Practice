// Section 16
// Challenge
#include <iostream>
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;

int main()
{
    cout.precision(2);
    cout << fixed;

    Account *p1 = new Checking_Account("Paul's Checking Account", 1000);
    Account *p2 = new Savings_Account("Paul's Savings Account", 5000, 0.05);
    Account *p3 = new Trust_Account("Paul's Trust Account", 20, 0.04);

    Savings_Account sav{"Frank's Savings Account", 5000, 0.05};
    Checking_Account check{"Frank's Checking Account", 1000};
    Trust_Account trust{"Frank's Trust Account", 5000, 0.10};

    cout << check << endl;
    cout << trust << endl;

    cout << *p1 << endl;
    cout << *p2 << endl;
    cout << *p3 << endl;
    std::vector<Account *> accounts{p1, p2, p3};
    display(accounts);

    deposit(accounts, 1000);
    withdraw(accounts, 2000);
    return 0;

    return 0;
}
