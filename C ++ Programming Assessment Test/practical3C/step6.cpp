#include <iostream>

using namespace std;

class ATM
{
private:
    double balance;

public:
    ATM()
    {
        balance = 20000;
    }

    void deposit();
};

void ATM::deposit()
{
    double amount;

    cout << endl;
    cout << "==========================================================" << endl;
    cout << "               ATM ACCOUNT DEPOSIT SYSTEM                 " << endl;
    cout << "==========================================================" << endl;

    cout << endl;

    cout << "The Name of the Account Holder is : Rakesh Kharva" << endl;
    cout << endl;

    cout << "The Account Holder's Address is : Mumbai" << endl;
    cout << endl;

    cout << "The Branch Location is : Andheri" << endl;
    cout << endl;

    cout << "Account Number : 5678" << endl;

    cout << endl;
    cout << "==========================================================" << endl;

    cout << endl;

    cout << "Present Available Balance : Rs. " << balance << endl;

    cout << endl;

    cout << "Enter the Amount to be Deposited Rs. ";
    cin >> amount;

    balance = balance + amount;

    cout << endl;

    cout << "Your New Available Balance Amount is Rs. "
         << balance << endl;

    cout << endl;

    cout << "Thank You!" << endl;

    cout << endl;

    cout << "Press any key to Return to the Main Menu." << endl;
}

int main()
{
    ATM obj;

    obj.deposit();

    return 0;
}