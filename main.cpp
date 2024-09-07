#include <iostream>

class I_Printable
{
    friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);

public:
    virtual void print(std::ostream &os) const = 0;
    virtual ~I_Printable();
};

std::ostream &operator<<(std::ostream &os, const I_Printable &obj)
{
    obj.print(os);
    return os;
}

I_Printable::~I_Printable() {}

class Account : public I_Printable
{
public:
    virtual void print(std::ostream &os) const override { os << "Account display"; }
    virtual void withdraw(double amount) { std::cout << "Account::withdraw" << std::endl; }
    virtual ~Account() {}
};

class Checking : public Account
{
public:
    virtual void print(std::ostream &os) const override { os << "Checking display"; }
    virtual void withdraw(double amount) { std::cout << "Checking::withdraw" << std::endl; }
    virtual ~Checking() {}
};

class Savings : public Account
{
public:
    virtual void print(std::ostream &os) const override { os << "Savings display"; }
    virtual void withdraw(double amount) { std::cout << "Savings::withdraw" << std::endl; }
    virtual ~Savings() {}
};

class Trust : public Account
{
public:
    virtual void print(std::ostream &os) const override { os << "Trust display"; }
    virtual void withdraw(double amount) { std::cout << "Trust::withdraw" << std::endl; }
    virtual ~Trust() {}
};

class Dog : public I_Printable
{

public:
    virtual void print(std::ostream &os) const override
    {
        std::cout << "Dog Display" << std::endl;
        std::cout << "Woof Woof" << std::endl;
    }
    virtual ~Dog();
};

Dog::~Dog()
{
}

int main()
{
    Account *p1 = new Account();
    Account *p2 = new Checking();

    std::cout << *p1 << std::endl;
    std::cout << *p2 << std::endl;

    Dog *d = new Dog();
    std::cout << *d << std::endl;

    // Account a;
    // std::cout << a << std::endl;

    // Checking c;
    // std::cout << c << std::endl;

    // Savings s;
    // std::cout << s << std::endl;

    // Trust t;
    // std::cout << t << std::endl;
}
