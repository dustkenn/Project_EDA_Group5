// Group 5: Measures of Central Tendency (Mean, Median, and Mode)
// Group Members: Baraero, Dimasangal, Gelotin, Sarte, Servidad, Tangilon
// Engineering Data Analysis Final Project

// ======================= LIBRARIES =======================
#include <iostream>   // for input/output operations
#include <vector>     // for dynamic array (list of numbers)
#include <algorithm>  // for sorting data
#include <iomanip>    // for setting decimal precision
#include <cctype>     // for character handling (tolower)

using namespace std;

// ======================= MEAN FUNCTION =======================
// This function calculates the average of all numbers in the dataset

double calculateMean(const vector<double>& data) {
    double sum = 0; // variable to store total sum

    // loop through all elements in the vector
    for (size_t i = 0; i < data.size(); i++) {
        sum += data[i]; // add each value to sum
    }

    // divide total sum by number of elements
    return sum / data.size();
}

// ======================= MEDIAN FUNCTION =======================
// This function finds the middle value after sorting the dataset

double calculateMedian(vector<double> data) {
    sort(data.begin(), data.end()); // sort data in ascending order

    size_t n = data.size(); // get number of elements

    // if number of elements is even
    if (n % 2 == 0)
        return (data[n / 2 - 1] + data[n / 2]) / 2.0; // average of two middle values
    else
        // if odd, return the middle element
        return data[n / 2];
}

// ======================= MODE FUNCTION =======================
// This function finds the most frequently occurring values

vector<double> calculateMode(vector<double> data) {
    sort(data.begin(), data.end()); // sort data first for easier counting

    vector<double> mode; // store mode values
    int maxCount = 0;    // store highest frequency

    // loop through each element
    for (size_t i = 0; i < data.size(); i++) {
        int count = 1; // count occurrences of current number

        // compare with next elements
        for (size_t j = i + 1; j < data.size(); j++) {
            if (data[i] == data[j])
                count++; // increase count if same value found
            else
                break; // stop when different value encountered
        }

        // if new highest frequency found
        if (count > maxCount) {
            maxCount = count; // update max frequency
            mode.clear();     // clear previous mode values
            mode.push_back(data[i]); // store new mode
        }
        // if same frequency as max and more than 1 occurrence
        else if (count == maxCount && count > 1) {
            mode.push_back(data[i]); // add additional mode value
        }
    }

    // if all values occur only once, no mode exists
    if (maxCount == 1)
        mode.clear();

    return mode;
}

// ======================= MAIN PROGRAM =======================
int main() {
    char choice;       // for try again option (y/n)
    int startChoice;   // for start menu choice

    // ================= WELCOME MENU =================
    cout << "============================================================\n";
    cout << "|         WELCOME TO MEASURES OF CENTRAL TENDENCY          |\n";
    cout << "|                 (Mean, Median, and Mode)                 |\n";
    cout << "============================================================\n\n";

    // display menu options
    cout << "\t\t\t[1] Start\n";
    cout << "\t\t\t[2] Exit\n\n";

    cout << "\t\t   Enter your choice: ";
    cin >> startChoice;

    // validate input (must be 1 or 2 only)
    while (cin.fail() || (startChoice != 1 && startChoice != 2)) {
        cin.clear(); // clear error state
        cin.ignore(1000, '\n'); // remove invalid input
        cout << "\nInvalid input. Please enter 1 or 2: ";
        cin >> startChoice;
    }

    // if user chooses exit
    if (startChoice == 2) {
        cout << "\nThank you. Program terminated.\n";
        return 0;
    }

    // ================= MAIN LOOP =================
    do {
        system("cls"); // clear screen for clean output

        cout << "============================================================\n";
        cout << "|            MEASURE OF CENTRAL TENDENCY SYSTEM            |\n";
        cout << "============================================================\n";

        int n; // number of data values

        // ask user for number of inputs
        cout << "Enter the number of data values: ";

        while (true) {
            cin >> n;

            // validation: no letters, decimals, or negative numbers
            if (cin.fail() || cin.peek() == '.' || n <= 0) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Please enter a positive whole number only: ";
            } else {
                cin.ignore(1000, '\n');
                break;
            }
        }

        vector<double> data(n); // store user inputs

        // ================= INPUT DATA =================
        cout << "\nEnter the data values:\n";

        for (size_t i = 0; i < data.size(); i++) {
            cout << "\n Value no." << i + 1 << ": ";

            // validate each input
            while (!(cin >> data[i])) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input. Please enter a number: ";
            }
        }

        // ================= MENU =================
        int operation;

        cout << "\n------------------------------------------------------------\n";
        cout << "|             What would you like to calculate?            |\n";
        cout << "------------------------------------------------------------\n\n";

        cout << "[1] Mean\n";
        cout << "[2] Median\n";
        cout << "[3] Mode\n";
        cout << "[4] All of the above\n";

        cout << "\nEnter your choice (1-4): ";

        // validate operation input
        while (true) {
            cin >> operation;

            if (cin.fail() || operation < 1 || operation > 4) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input. Please enter 1 to 4: ";
            } else {
                break;
            }
        }

        // ================= COMPUTATION =================
        double mean = calculateMean(data);     // compute mean
        double median = calculateMedian(data); // compute median
        vector<double> mode = calculateMode(data); // compute mode

        cout << fixed << setprecision(2); // 2 decimal places

        // ================= OUTPUT =================
        cout << "\n============================================================\n";
        cout << "|                          RESULTS                         |\n";
        cout << "============================================================\n\n";

        switch (operation) {
            case 1:
                cout << "Mean   : " << mean << endl;
                break;

            case 2:
                cout << "Median : " << median << endl;
                break;

            case 3:
                if (mode.empty()) {
                    cout << "Mode   : (No mode)\n";
                } else {
                    cout << "Mode   : ";
                    for (size_t i = 0; i < mode.size(); i++) {
                        cout << mode[i];
                        if (i != mode.size() - 1)
                            cout << ", ";
                    }
                    cout << endl;
                }
                break;

            case 4:
                cout << "Mean   : " << mean << endl;
                cout << "Median : " << median << endl;

                if (mode.empty()) {
                    cout << "Mode   : (No mode)\n";
                } else {
                    cout << "Mode   : ";
                    for (size_t i = 0; i < mode.size(); i++) {
                        cout << mode[i];
                        if (i != mode.size() - 1)
                            cout << ", ";
                    }
                    cout << endl;
                }
                break;
        }

        cout << "\n============================================================\n";

        // ================= TRY AGAIN =================
        do {
            cout << "\nDo you want to try again? (y/n): ";
            cin >> choice;

            // convert input to lowercase
            choice = static_cast<char>(tolower(static_cast<unsigned char>(choice)));

            if (choice != 'y' && choice != 'n') {
                cout << "Invalid input. Please enter only y or n.\n";
            }

        } while (choice != 'y' && choice != 'n');

    } while (choice == 'y'); // repeat program if user wants

    cout << "\nThank you for using the program.\n";

    return 0;
}
