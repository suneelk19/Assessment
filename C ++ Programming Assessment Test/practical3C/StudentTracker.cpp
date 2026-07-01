#include <iostream>
#include <fstream>
using namespace std;

// Function Declarations
void logStudyHours();
void generateReport();

int main()
{
    int choice;

    do
    {
        cout << "\n====================================";
        cout << "\n   Student Productivity Tracker";
        cout << "\n====================================";
        cout << "\n1. Log Daily Study Hours";
        cout << "\n2. Generate Weekly Report";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                logStudyHours();
                break;

            case 2:
                generateReport();
                break;

            case 3:
                cout << "\nThank You!";
                break;

            default:
                cout << "\nInvalid Choice!";
        }

    } while(choice != 3);

    return 0;
}

// Function to save study hours
void logStudyHours()
{
    ofstream file("study.txt", ios::app);

    float hours;

    cout << "\nEnter today's study hours: ";
    cin >> hours;

    file << hours << endl;

    file.close();

    cout << "Study hours saved successfully." << endl;
}

// Function to generate report
void generateReport()
{
    ifstream file("study.txt");

    float hours;
    float total = 0;
    float average;
    int day = 1;

    if(!file)
    {
        cout << "\nNo study data found!" << endl;
        return;
    }

    cout << "\n========== Weekly Report ==========\n";

    while(file >> hours)
    {
        cout << "Day " << day << " : " << hours << " Hours" << endl;

        total += hours;
        day++;
    }

    file.close();

    int totalDays = day - 1;

    if(totalDays > 0)
    {
        average = total / totalDays;

        cout << "\nTotal Study Hours : " << total << endl;
        cout << "Average Study Hours : " << average << endl;

        if(average >= 8)
        {
            cout << "Excellent Performance!" << endl;
        }
        else if(average >= 5)
        {
            cout << "Good Performance!" << endl;
        }
        else
        {
            cout << "Need More Practice!" << endl;
        }
    }
}