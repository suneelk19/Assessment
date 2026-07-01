#include <iostream>
#include <ctime>

using namespace std;

class ATM
{
public:

    void welcomeScreen();
};

void ATM::welcomeScreen()
{
    time_t now = time(0);

    cout << "\n\n";

    cout << "##############################################################" << endl;

    cout << "                    WELCOME TO ATM                           " << endl;

    cout << "##############################################################" << endl;

    cout << endl;

    cout << "                     --------------------" << endl;

    cout << "                     Current Date : ";

    cout << ctime(&now);

    cout << "                     --------------------" << endl;

    cout << endl;

    cout << "##############################################################" << endl;

    cout << endl;

    cout << " Press 1 and Then Press Enter to Access Your Account Via Pin Number"
         << endl;

    cout << endl;

    cout << "                           OR" << endl;

    cout << endl;

    cout << " Press 0 and Press Enter to Get Help." << endl;

    cout << endl;
}

int main()
{
    ATM obj;

    obj.welcomeScreen();

    return 0;
}