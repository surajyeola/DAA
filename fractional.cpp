// Name: Suraj Yeola
// Roll No: 75
// Class: TY B BTech
// Branch: Computer Engineering 
// Course: Design and Analysis of Algorithm

// Assignment 04

// Problem Statement:

/*Develop a program to solve a fractional Knapsack problem using a greedy method.*/

#include <iostream>
using namespace std;
int main () {
    int n;
    cout << "Enter total number of objects: ";
    cin >> n;
    double p[n], w[n];
    cout << "Enter profits of objects:\n";
    for (int i=0; i<n; i++) {
        cin >> p[i];
    }
    cout << "Enter weights of objects:\n";
    for (int i=0; i<n; i++) {
        cin >> w[i];
    }
    int m;
    cout << "Enter total capacity of knapsack: ";
    cin >> m;

    cout << "\nStep 01: Calculating Pi / Wi values\nObject\tProfit\tWeight\tPi/Wi\n";
    double piwi[n];
    for (int i=0; i<n; i++) {
        piwi[i] = p[i] / w[i];
        cout << (i+1) << "\t" << p[i] << "\t" << w[i] << "\t" << piwi[i] << endl;
    }

    cout << "\nStep 02: Arranging in decreasing order of pi/wi values:\n";
    for (int i=0; i<n; i++) {
        for (int j=(i+1); j<n; j++) {
            if (piwi[i] < piwi[j]) {
                swap(piwi[i], piwi[j]);
                swap(p[i], p[j]);
                swap(w[i], w[j]);
            } 
        }
    }
    cout << "Object\tProfit\tWeight\tpi/wi\n";
    for (int i=0; i<n; i++) {
        cout << (i+1) << "\t" << p[i] << "\t" << w[i] << "\t" << piwi[i] << endl;
    }

    cout << "\nStep 03: Calculating total profit\n";
    cout << "Object\tProfit\tWeight\tXi\tM\tpixi\n";
    double totalprofit = 0;
    double x[n] = {0};
    int i=0;
    for (i=0; i<n; i++) {
        if (w[i] > m) {
            break;
        }
        x[i] = 1;
        m = m - w[i];
        totalprofit += p[i];
        cout << (i+1) << "\t" << p[i] << "\t" << w[i] << "\t" << x[i] << "\t" << m << "\t" << (p[i] * x[i]) << endl;
    }
    if (i < n) {
        x[i] = m / w[i];
        totalprofit += (p[i] * x[i]);
        cout << (i+1) << "\t" << p[i] << "\t" << w[i] << "\t" << x[i] << "\t" << 0 << "\t" << (p[i] * x[i]) << endl;
    }
    cout << "\nTotal profit is: " << totalprofit << endl;
    return 0;
}

// Output:

// Test Case 01:

/*PS C:\Users\suraj\desktop\DAA\practice> g++ fractional.cpp
PS C:\Users\suraj\desktop\DAA\practice> ./a.exe
Enter total number of objects: 3
Enter profits of objects:
25 24 15
Enter weights of objects:
18 15 10
Enter total capacity of knapsack: 20

Step 01: Calculating Pi / Wi values
Object  Profit  Weight  Pi/Wi
1       25      18      1.38889
2       24      15      1.6
3       15      10      1.5

Step 02: Arranging in decreasing order of pi/wi values:
Object  Profit  Weight  pi/wi
1       24      15      1.6
2       15      10      1.5
3       25      18      1.38889

Step 03: Calculating total profit
Object  Profit  Weight  Xi      M       pixi
1       24      15      1       5       24
2       15      10      0.5     0       7.5

Total profit is: 31.5
PS C:\Users\suraj\desktop\DAA\practice> */

// Test Case 02:

/*PS C:\Users\suraj\desktop\DAA\practice> g++ fractional.cpp
PS C:\Users\suraj\desktop\DAA\practice> ./a.exe
Enter total number of objects: 3
Enter profits of objects:
30 21 18
Enter weights of objects:
18 15 10
Enter total capacity of knapsack: 20

Step 01: Calculating Pi / Wi values
Object  Profit  Weight  Pi/Wi
1       30      18      1.66667
2       21      15      1.4
3       18      10      1.8

Step 02: Arranging in decreasing order of pi/wi values:
Object  Profit  Weight  pi/wi
1       18      10      1.8
2       30      18      1.66667
3       21      15      1.4

Step 03: Calculating total profit
Object  Profit  Weight  Xi          M       pixi
1       18      10      1           10      18
2       30      18      0.555556    0       16.6667

Total profit is: 34.6667
PS C:\Users\suraj\desktop\DAA\practice>*/