// Name: Suraj Yeola
// Roll No: 75
// Class: TY B BTech
// Branch: Computer Engineering 
// Course: Design and Analysis of Algorithm

// Assignment 05

// Problem Statement:
/*Develop a program to implement 0/1 Knapsack problem using Dynamic Programming.*/

#include <iostream>
using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Main Function // Suraj Yeola Code
int main() {
    int W;  // Capacity of knapsack
    int n;  // Number of items

    cout << "Enter capacity (W): ";
    cin >> W;

    cout << "Enter number of items (n): ";
    cin >> n;

    int weights[n];
    int values[n];

    cout << "Enter the weights: ";
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    cout << "Enter the profits: ";
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    int arr[n + 1][W + 1];

    // Initialize table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                arr[i][w] = 0;
            }
        }
    }

    // Fill the table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w) {
                arr[i][w] = max(arr[i-1][w], values[i-1] + arr[i-1][w-weights[i-1]]);
            } else {
                arr[i][w] = arr[i-1][w];
            }
        }
    }

    int maxValue = arr[n][W];
    int x[n];  // Array to track selected items (0 or 1)

    // Backtracking to find items included in the knapsack
    int w = W;
    for (int i = n; i > 0; i--) {
        if (arr[i][w] != arr[i-1][w]) {  // Item i-1 is included
            x[i-1] = 1;
            w -= weights[i-1];  // Reduce remaining capacity
        } else {  // Item i-1 is not included
            x[i-1] = 0;
        }
    }

    // Print the table
    cout << "\nDP Table:\n";
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            cout << arr[i][w] << "\t";
        }
        cout << endl;
    }

    // Print selected items and intermediate steps of x[]
    cout << "\nSelected items (x):\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << ": " << (x[i] == 1 ? "Included" : "Not included") << " (x[" << i << "] = " << x[i] << ")\n";
    }

    // Calculate final profit by summing values of selected items
    int finalProfit = 0;
    for (int i = 0; i < n; i++) {
        finalProfit += values[i] * x[i];
    }

    cout << "\nMaximum Profit: " << maxValue << endl;
    cout << "Calculated Profit: " << finalProfit << endl;

    return 0;
}

// Output: // Suraj Yeola Code

/*PS C:\Users\suraj\desktop\TYB75_DAA_SurajYeola> g++ try01knapsackdynamic.cpp
PS C:\Users\suraj\desktop\TYB75_DAA_SurajYeola> ./a.exe
Enter capacity (W): 6
Enter number of items (n): 3
Enter the weights: 2 3 4
Enter the profits: 1 2 5

DP Table:
0       0       0       0       0       0       0
0       0       1       1       1       1       1
0       0       1       2       2       3       3
0       0       1       2       5       5       6

Selected items (x):
Item 1: Included (x[0] = 1)
Item 2: Not included (x[1] = 0)
Item 3: Included (x[2] = 1)

Maximum Profit: 6
Calculated Profit: 6
PS C:\Users\suraj\desktop\TYB75_DAA_SurajYeola> */