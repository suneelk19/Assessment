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

    void withdraw();
};

void ATM::withdraw()
{
    double amount;

    cout << endl;
    cout << "==========================================================" << endl;
    cout << "               ATM ACCOUNT WITHDRAWAL                     " << endl;
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

    cout << "Enter Amount to Withdraw : Rs. ";
    cin >> amount;

    cout << endl;

    if(amount > balance)
    {
        cout << "Insufficient Available Balance in your account." << endl;
        cout << endl;
        cout << "Sorry !!" << endl;
    }
    else
    {
        balance = balance - amount;

        cout << "Withdrawal Successful." << endl;
        cout << endl;
        cout << "Remaining Balance : Rs. " << balance << endl;
    }

    cout << endl;
    cout << "Press any key to continue . . ." << endl;
}

int main()
{
    ATM obj;

    obj.withdraw();

    return 0;
}