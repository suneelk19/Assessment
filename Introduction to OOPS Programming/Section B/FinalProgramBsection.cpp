#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

void studyMoodAssistant() {
    int hours;
    cout << "\nEnter hours studied today: ";
    cin >> hours;

    if (hours < 0) {
        cout << "Invalid input.\n";
    } else if (hours == 0) {
        cout << "Start today. Even small effort matters.\n";
    } else if (hours <= 2) {
        cout << "Good start, keep going!\n";
    } else if (hours <= 5) {
        cout << "Great job! You are doing well.\n";
    } else {
        cout << "Excellent! Very productive day.\n";
    }
}

void screenTimeReport() {
    float screenTime[7], total = 0, average;
    const float healthyLimit = 4.0;

    for (int i = 0; i < 7; i++) {
        cout << "Enter screen time for day " << i + 1 << ": ";
        cin >> screenTime[i];
        total += screenTime[i];
    }

    average = total / 7;

    cout << "\nTotal screen time: " << total << " hours\n";
    cout << "Average screen time: " << average << " hours\n";

    if (average > healthyLimit) {
        cout << "Warning: Average screen time exceeds healthy limit.\n";
    } else {
        cout << "Screen time is within healthy limit.\n";
    }
}

void swapUsingReference(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void swapUsingPointers(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void pointerSwapDemo() {
    int x, y;
    cout << "\nEnter two numbers: ";
    cin >> x >> y;

    cout << "Before swap: " << x << " " << y << endl;

    swapUsingReference(x, y);
    cout << "After swap by reference: " << x << " " << y << endl;

    swapUsingPointers(&x, &y);
    cout << "After swap using pointers: " << x << " " << y << endl;

    cout << "Pass-by-reference is needed because the original variables must be modified directly.\n";
}

void fileHandlingGoals() {
    ofstream outFile("goals.txt", ios::app);
    if (!outFile) {
        cout << "Error opening file for writing.\n";
        return;
    }

    int n;
    cout << "\nHow many goals do you want to add? ";
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < n; i++) {
        string goal;
        cout << "Enter goal " << i + 1 << ": ";
        getline(cin, goal);
        outFile << goal << endl;
    }

    outFile.close();

    cout << "\nSaved goals. Reading all stored goals:\n\n";

    ifstream inFile("goals.txt");
    if (!inFile) {
        cout << "Error opening file for reading.\n";
        return;
    }

    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close();
}

int main() {
    int choice;

    do {
        cout << "\n===== SECTION B MENU =====\n";
        cout << "1. Study Mood Assistant\n";
        cout << "2. Screen Time Report\n";
        cout << "3. Swap Numbers\n";
        cout << "4. File Handling Goals\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                studyMoodAssistant();
                break;
            case 2:
                screenTimeReport();
                break;
            case 3:
                pointerSwapDemo();
                break;
            case 4:
                fileHandlingGoals();
                break;
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}