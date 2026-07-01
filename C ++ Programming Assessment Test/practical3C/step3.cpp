#include <iostream>
#include <ctime>

using namespace std;

class ATM
{
public:

    void welcomeScreen();

    bool verifyPin();

    void helpScreen();
};

// Welcome Screen
void ATM::welcomeScreen()
{
    time_t now = time(0);

    cout << "==========================================================" << endl;
    cout << "                  WELCOME TO ATM                          " << endl;
    cout << "==========================================================" << endl;

    cout << endl;

    cout << "Current Date & Time : " << ctime(&now);

    cout << endl;

    cout << "Press 1 and Then Press Enter to Access Your Account Via Pin Number" << endl;

    cout << endl;

    cout << "                     OR" << endl;

    cout << endl;

    cout << "Press 0 and Press Enter to Get Help." << endl;

    cout << endl;
}

// PIN Verification
bool ATM::verifyPin()
{
    int pin;

    cout << endl;

    cout << "==========================================================" << endl;
    cout << "                 ATM ACCOUNT ACCESS                       " << endl;
    cout << "==========================================================" << endl;

    cout << endl;

    cout << "Enter Your Account PIN : ";
    cin >> pin;

    if(pin == 12345)
    {
        cout << endl;
        cout << "PIN Verified Successfully." << endl;
        cout << "Login Successful." << endl;

        return true;
    }
    else
    {
        cout << endl;
        cout << "THANK YOU" << endl;
        cout << "You had made your attempt which failed!!" << endl;
        cout << "No More Attempts Allowed!!" << endl;

        return false;
    }
}

// Help Screen
void ATM::helpScreen()
{
    cout << endl;

    cout << "==========================================================" << endl;
    cout << "                 ATM ACCOUNT STATUS                       " << endl;
    cout << "==========================================================" << endl;

    cout << endl;

    cout << "You must have the correct PIN number to access this account." << endl;

    cout << "See your bank representative for assistance during bank opening hours." << endl;

    cout << "If you are unable to access your account, contact your bank." << endl;

    cout << endl;

    cout << "THANK YOU FOR CHOOSING OUR ATM SERVICE." << endl;
}

int main()
{
    ATM obj;

    obj.welcomeScreen();

    int choice;

    cout << "Enter Choice : ";
    cin >> choice;

    if(choice == 1)
    {
        obj.verifyPin();
    }
    else if(choice == 0)
    {
        obj.helpScreen();
    }
    else
    {
        cout << "\nInvalid Choice!" << endl;
    }

    return 0;
}