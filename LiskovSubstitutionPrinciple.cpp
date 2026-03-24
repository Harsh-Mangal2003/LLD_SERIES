#include <iostream>
using namespace std;
class Account{
    public:
    virtual void deposit(double amount)=0;
    virtual void withdraw(double amount)=0;
};
class SavingsAccount{

    private:
    double balance;
    public:
    SavingsAccount(){
        balance=0;
    }
    void deposit(double amount)
    {
        balance+=amount;
        cout<<"Deposited:"<<amount<<"in Saving Account"<<endl;
    }
    void withdraw(double amount)
    {
        if(balance>=amount)
        {
            balance-=amount;
            cout<<"Withdrawn:"<<amount<<"from Savings account"<<endl;
        }
        else{
            cout<<"Insufficient balance"<<endl;
        }
    }


};

class CurrentAccount{

    private:
    double balance;
    public:
    CurrentAccount(){
        balance=0;
    }
    void deposit(double amount)
    {
        balance+=amount;
        cout<<"Deposited:"<<amount<<"in Saving Account"<<endl;
    }
    void withdraw(double amount)
    {
        if(balance>=amount)
        {
            balance-=amount;
            cout<<"Withdrawn:"<<amount<<"from Savings account"<<endl;
        }
        else{
            cout<<"Insufficient balance"<<endl;
        }
    }


};
    