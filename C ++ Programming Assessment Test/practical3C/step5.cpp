#include <iostream>
#include <ctime>

using namespace std;

class ATM
{
public:
    void welcomeScreen();
    bool verifyPin();
    void menu();
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

    cout << "==========================================================" << endl;
    cout << "                ATM ACCOUNT ACCESS                        " << endl;
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
        cout << "##########################################################" << endl;
        cout << "                      THANK YOU                           " << endl;
        cout << "##########################################################" << endl;

        cout << endl;
        cout << "You had made your attempt which failed!!" << endl;
        cout << "No More Attempts Allowed!!" << endl;
        cout << "System Closed." << endl;

        return false;
    }
}

// ATM Main Menu
void ATM::menu()
{
    cout << endl;

    cout << "==========================================================" << endl;
    cout << "                  ATM Main Menu Screen                    " << endl;
    cout << "==========================================================" << endl;

    cout << endl;

    cout << "\tEnter [1] To Deposit Cash" << endl;
    cout << "\tEnter [2] To Withdraw Cash" << endl;
    cout << "\tEnter [3] To Balance Inquiry" << endl;
    cout << "\tEnter [0] To Exit ATM" << endl;

    cout << endl;

    cout << "PLEASE ENTER A SELECTION AND PRESS RETURN KEY : ";
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
        if(obj.verifyPin())
        {
            obj.menu();

            int option;
            cin >> option;

            switch(option)
            {
                case 1:
                    cout << "\nDeposit Cash Module will be added in Step 6." << endl;
                    break;

                case 2:
                    cout << "\nWithdraw Cash Module will be added in Step 7." << endl;
                    break;

                case 3:
                    cout << "\nBalance Inquiry Module will be added in Step 8." << endl;
                    break;

                case 0:
                    cout << "\nThank You For Using ATM." << endl;
                    break;

                default:
                    cout << "\nInvalid Selection!" << endl;
            }
        }
    }
    else if(choice == 0)
    {
        cout << "\nATM Help Screen will be added in previous step." << endl;
    }
    else
    {
        cout << "\nInvalid Choice!" << endl;
    }

    return 0;
}