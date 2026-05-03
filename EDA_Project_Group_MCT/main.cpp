// Group 5: Measures of Central Tendency (Mean, Median, and Mode)
// Group Members: Baraero, Dimasangal, Gelotin, Sarte, Servidad, Tangilon

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cctype>
using namespace std;

// ======================= MEAN FUNCTION =======================
// This function calculates the average of all numbers

double calculateMean(const vector<double>& data) {
    double sum = 0;

    // add all values in the dataset
    for (int i = 0; i < data.size(); i++) {
        sum += data[i];
    }

    // divide total by number of values
    return sum / data.size();
}

// ======================= MEDIAN FUNCTION =======================
// This function finds the middle value after sorting

double calculateMedian(vector<double> data) {
    sort(data.begin(), data.end()); // sort values first
    int n = data.size();

    // if even number of values
    if (n % 2 == 0)
        return (data[n/2 - 1] + data[n/2]) / 2.0;
    // if odd number of values
    else
        return data[n/2];
}

// ======================= MODE FUNCTION =======================
// This function finds the most repeated number(s)

vector<double> calculateMode(vector<double> data) {
    sort(data.begin(), data.end()); // sort first

    vector<double> mode;
    int maxCount = 0;

    for (int i = 0; i < data.size(); i++) {
        int count = 1;

        // count repeated values
        for (int j = i + 1; j < data.size(); j++) {
            if (data[i] == data[j])
                count++;
            else
                break;
        }
        // update mode if higher frequency is found
        if (count > maxCount) {
            maxCount = count;
            mode.clear();
            mode.push_back(data[i]);
        }
        // add if same highest frequency
        else if (count == maxCount && count > 1) {
            mode.push_back(data[i]);
        }
    }

    // if all values appear only once, there is no mode
    if (maxCount == 1)
        mode.clear();

    return mode;
}

// ======================= MAIN PROGRAM =======================
int main() {
    char choice;

    do {
        system("cls"); // clear screen for clean output
        cout << "============================================================\n";
        cout << "|            MEASURE OF CENTRAL TENDENCY SYSTEM            |\n";
        cout << "============================================================\n";

        int n;

        // input number of data values
        cout << "Enter the number of data values: ";

        while (true) {
            cin >> n;

            // check invalid input (letters, decimals, negative numbers)
            if (cin.fail() || cin.peek() == '.' || n <= 0) {
                cin.clear();
                cin.ignore(1000, '\n');

                cout << "Please enter a positive whole number only: ";
            } else {
                cin.ignore(1000, '\n');
                break;
            }
        }

        vector<double> data(n);

        // input data values
        cout << "\nEnter the data values:\n";

        for (int i = 0; i < n; i++) {
            cout << "\n Value no." << i + 1 << ": ";

            // check if input is valid number
            while (!(cin >> data[i])) {
                cin.clear();
                cin.ignore(1000, '\n');

                cout << "Invalid input. Please enter a number: ";
            }
        }

        // compute mean, median, mode
        double mean = calculateMean(data);
        double median = calculateMedian(data);
        vector<double> mode = calculateMode(data);

        // output results with 2 decimal places
        cout << fixed << setprecision(2);

        cout << "\n";
        cout << "============================================================\n";
        cout << "|                          RESULTS                         |\n";
        cout << "============================================================\n";

        cout << "Mean   : " << mean << endl;
        cout << "Median : " << median << endl;

        // display mode result
        if (mode.empty()) {
            cout << "Mode   : (No mode)\n";
        } else {
            cout << "Mode   : ";
            for (int i = 0; i < mode.size(); i++) {
                cout << mode[i] << " ";
            }
            cout << endl;
        }

        cout << "\n============================================================\n";

        // ask user if they want to try again
        do {
            cout << "\nDo you want to try again? (y/n): ";
            cin >> choice;

            choice = tolower(choice);

            if (choice != 'y' && choice != 'n') {
                cout << "Invalid input. Please enter only y or n.\n";
            }

        } while (choice != 'y' && choice != 'n');

    } while (choice == 'y');

    cout << "\nThank you for using the program.\n";

    return 0;
}
