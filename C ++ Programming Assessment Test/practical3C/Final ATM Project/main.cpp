#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <limits>

using namespace std;

class ATM
{
private:
    string accountHolderName;
    string accountHolderAddress;
    string branchLocation;
    string accountNumber;
    double startingBalance;
    double currentBalance;
    const int correctPin;

public:
    ATM();  // Constructor
    void showWelcomeScreen();
    void showHelpScreen();
    bool authenticatePin();
    void showMainMenu();
    void deposit();
    void withdraw();
    void balanceInquiry();
    void showAccountDetails();
    void pauseScreen();
    void clearInputBuffer();
};

ATM::ATM() : correctPin(12345)
{
    accountHolderName = "Rakesh Kharva";
    accountHolderAddress = "Mumbai";
    branchLocation = "Andheri";
    accountNumber = "5678";
    startingBalance = 60000;
    currentBalance = 20000;
}

void ATM::clearInputBuffer()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void ATM::pauseScreen()
{
    cout << "\nPress any key to continue . . .";
    cin.ignore();
    cin.get();
}

void ATM::showWelcomeScreen()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);

    cout << "============================================================\n";
    cout << "                     WELCOME TO ATM                         \n";
    cout << "============================================================\n";
    cout << "\nCurrent date : "
         << put_time(ltm, "%a %b %d %H:%M:%S %Y") << "\n";
    cout << "\n------------------------------------------------------------\n";
    cout << "Press 1 and then Press Enter to Access Your Account Via Pin Number\n";
    cout << "or\n";
    cout << "Press 0 and press Enter to get Help.\n";
    cout << "------------------------------------------------------------\n";
}

void ATM::showHelpScreen()
{
    cout << "\n============================================================\n";
    cout << "                     ATM ACCOUNT STATUS                     \n";
    cout << "============================================================\n";
    cout << "\nYou must have the correct pin number to access this account.";
    cout << "\nSee your bank representative for assistance during bank opening hours.\n";
    cout << "\nThanks for your choice today!!\n";
    cout << "============================================================\n";
    pauseScreen();
}

bool ATM::authenticatePin()
{
    int pin;
    cout << "\n============================================================\n";
    cout << "                      ATM ACCOUNT ACCESS                    \n";
    cout << "============================================================\n";
    cout << "\nEnter Your Acc Pin Access Number! [Only one attempt is allowed]\n\n";
    cout << "Enter PIN: ";
    cin >> pin;

    if (cin.fail())
    {
        cin.clear();
        clearInputBuffer();
        return false;
    }

    if (pin == correctPin)
    {
        return true;
    }
    return false;
}

void ATM::showAccountDetails()
{
    cout << "\nThe Names of the Account Holders are : " << accountHolderName << "\n";
    cout << "The Account Holders' address is : " << accountHolderAddress << "\n";
    cout << "The Branch location is : " << branchLocation << "\n";
    cout << "Account number : " << accountNumber << "\n";
}

void ATM::deposit()
{
    double amount;
    cout << "\n============================================================\n";
    cout << "                    ATM ACCOUNT DEPOSIT SYSTEM              \n";
    cout << "============================================================\n";

    showAccountDetails();
    cout << "============================================================\n";
    cout << "\nPresent available balance : Rs. " << fixed << setprecision(0) << currentBalance << "\n";
    cout << "Enter the Amount to be Deposited Rs. ";
    cin >> amount;

    if (cin.fail() || amount <= 0)
    {
        cin.clear();
        clearInputBuffer();
        cout << "\nInvalid deposit amount.\n";
        pauseScreen();
        return;
    }

    currentBalance += amount;
    cout << "\nYour new available Balanced Amount is Rs. " << fixed << setprecision(0) << currentBalance << "\n";
    cout << "\nThank You!\n";
    pauseScreen();
}

void ATM::withdraw()
{
    double amount;
    cout << "\n============================================================\n";
    cout << "                    ATM ACCOUNT WITHDRAWAL                  \n";
    cout << "============================================================\n";

    showAccountDetails();
    cout << "============================================================\n";
    cout << "\nEnter the Amount to Withdraw Rs. ";
    cin >> amount;

    if (cin.fail() || amount <= 0)
    {
        cin.clear();
        clearInputBuffer();
        cout << "\nInvalid withdrawal amount.\n";
        pauseScreen();
        return;
    }

    if (amount > currentBalance)
    {
        cout << "\nInsufficient Available Balance in your account.\n";
        cout << "\nSorry !!\n";
    }
    else
    {
        currentBalance -= amount;
        cout << "\nWithdrawal successful.\n";
        cout << "Remaining Balance is Rs. " << fixed << setprecision(0) << currentBalance << "\n";
    }

    pauseScreen();
}

void ATM::balanceInquiry()
{
    cout << "\n============================================================\n";
    cout << "                     BALANCE INQUIRY                        \n";
    cout << "============================================================\n";

    showAccountDetails();
    cout << "============================================================\n";
    cout << "\nCurrent Account Balance is Rs. " << fixed << setprecision(0) << currentBalance << "\n";
    pauseScreen();
}

void ATM::showMainMenu()
{
    int choice = -1;

    while (true)
    {
        cout << "\n============================================================\n";
        cout << "                     ATM Main Menu Screen                   \n";
        cout << "============================================================\n";
        cout << "\nEnter [1] To Deposit Cash\n";
        cout << "Enter [2] To Withdraw Cash\n";
        cout << "Enter [3] To Balance Inquiry\n";
        cout << "Enter [0] to Exit ATM\n";
        cout << "\nPLEASE ENTER A SELECTION AND PRESS RETURN KEY: ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            clearInputBuffer();
            cout << "\nInvalid choice.\n";
            continue;
        }

        switch (choice)
        {
        case 1:
            deposit();
            break;
        case 2:
            withdraw();
            break;
        case 3:
            balanceInquiry();
            break;
        case 0:
            cout << "\nThank you for using ATM.\n";
            return;
        default:
            cout << "\nInvalid choice. Try again.\n";
        }
    }
}

int main()
{
    ATM atm;
    int choice;

    atm.showWelcomeScreen();
    cin >> choice;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nIncorrect input. Exiting...\n";
        return 0;
    }

    if (choice == 0)
    {
        atm.showHelpScreen();
        return 0;
    }
    else if (choice == 1)
    {
        if (atm.authenticatePin())
        {
            cout << "\nPIN correct. Access granted.\n";
            atm.showMainMenu();
        }
        else
        {
            cout << "\n============================================================\n";
            cout << "                          THANK YOU                          \n";
            cout << "============================================================\n";
            cout << "\nYou had made your attempt which failed!!! No More attempts allowed!! Sorry!!\n";
            cout << "\nPress any key to continue . . .";
            cin.ignore();
            cin.get();
        }
    }
    else
    {
        cout << "\nInvalid selection. Exiting...\n";
    }

    return 0;
}