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

    void checkBalance();
};

void ATM::checkBalance()
{
    cout << endl;

    cout << "==========================================================" << endl;
    cout << "                ATM BALANCE INQUIRY SYSTEM                " << endl;
    cout << "==========================================================" << endl;

    cout << endl;

    cout << "Account Holder Name : Rakesh Kharva" << endl;
    cout << endl;

    cout << "Account Number : 5678" << endl;
    cout << endl;

    cout << "Branch : Andheri" << endl;

    cout << endl;
    cout << "==========================================================" << endl;

    cout << endl;

    cout << "Your Current Available Balance is : Rs. "
         << balance << endl;

    cout << endl;

    cout << "Thank You!" << endl;

    cout << endl;

    cout << "Press any key to continue . . ." << endl;
}

int main()
{
    ATM obj;

    obj.checkBalance();

    return 0;
}