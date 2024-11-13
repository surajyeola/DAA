// Name: Suraj Yeola
// Roll No: 75
// Class: TY B BTech
// Branch: Computer Engineering 
// Course: Design and Analysis of Algorithm

// Assignment 07

// Problem Statement:

/*8 Queen matrix is stored having first queen placed; use backtracking to place remaining queens to generate the final 8-queen matrix using C++*/

#include <iostream>
#include <cmath>

using namespace std;

const int MAX_N = 20; 
int x[MAX_N]; 
int count = 0; 

bool place(int k, int i) {
    
    for (int j = 1; j < k; ++j) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k)) {
            return false;
        }
    }
    return true;
}

void NQueen(int k, int n) {
    for (int i = 1; i <= n; ++i) {
        if (place(k, i)) {
            x[k] = i; 
            if (k == n) {
                
                cout << "Solution " << ++count << ": ";
                for (int j = 1; j <= n; ++j) {
                    cout << x[j] << " ";
                }
                cout << endl;
            } 
            else {
                NQueen(k + 1, n); 
            }
        }
    }
}

// Main Function // Suraj Yeola Code
int main() {
    int n;
    cout << "Enter total number of queens: ";
    cin >> n;

    NQueen(1, n); 
    cout << "Total possibilities: " << count << endl;

    return 0;
}

// Output 01: // Suraj Yeola Code

/* unix@unix-HP-280-G4-MT-Business-PC:~/TYB75_DAA_SurajYeola$ g++ nqueen.cpp
unix@unix-HP-280-G4-MT-Business-PC:~/TYB75_DAA_SurajYeola$ ./a.out
Enter the number of queens: 4
Solution 1: 2 4 1 3 
Solution 2: 3 1 4 2 
Total possibilities: 2
unix@unix-HP-280-G4-MT-Business-PC:~/TYB75_DAA_SurajYeola$ */

// Output 02: // Suraj Yeola Code

/*unix@unix-HP-280-G4-MT-Business-PC:~/TYB75_DAA_SurajYeola$ g++ nqueen.cpp
unix@unix-HP-280-G4-MT-Business-PC:~/TYB75_DAA_SurajYeola$ ./a.out
Enter the number of queens: 8
Solution 1: 1 5 8 6 3 7 2 4 
Solution 2: 1 6 8 3 7 4 2 5 
Solution 3: 1 7 4 6 8 2 5 3 
Solution 4: 1 7 5 8 2 4 6 3 
Solution 5: 2 4 6 8 3 1 7 5 
Solution 6: 2 5 7 1 3 8 6 4 
Solution 7: 2 5 7 4 1 8 6 3 
Solution 8: 2 6 1 7 4 8 3 5 
Solution 9: 2 6 8 3 1 4 7 5 
Solution 10: 2 7 3 6 8 5 1 4 
Solution 11: 2 7 5 8 1 4 6 3 
Solution 12: 2 8 6 1 3 5 7 4 
Solution 13: 3 1 7 5 8 2 4 6 
Solution 14: 3 5 2 8 1 7 4 6 
Solution 15: 3 5 2 8 6 4 7 1 
Solution 16: 3 5 7 1 4 2 8 6 
Solution 17: 3 5 8 4 1 7 2 6 
Solution 18: 3 6 2 5 8 1 7 4 
Solution 19: 3 6 2 7 1 4 8 5 
Solution 20: 3 6 2 7 5 1 8 4 
Solution 21: 3 6 4 1 8 5 7 2 
Solution 22: 3 6 4 2 8 5 7 1 
Solution 23: 3 6 8 1 4 7 5 2 
Solution 24: 3 6 8 1 5 7 2 4 
Solution 25: 3 6 8 2 4 1 7 5 
Solution 26: 3 7 2 8 5 1 4 6 
Solution 27: 3 7 2 8 6 4 1 5 
Solution 28: 3 8 4 7 1 6 2 5 
Solution 29: 4 1 5 8 2 7 3 6 
Solution 30: 4 1 5 8 6 3 7 2 
Solution 31: 4 2 5 8 6 1 3 7 
Solution 32: 4 2 7 3 6 8 1 5 
Solution 33: 4 2 7 3 6 8 5 1 
Solution 34: 4 2 7 5 1 8 6 3 
Solution 35: 4 2 8 5 7 1 3 6 
Solution 36: 4 2 8 6 1 3 5 7 
Solution 37: 4 6 1 5 2 8 3 7 
Solution 38: 4 6 8 2 7 1 3 5 
Solution 39: 4 6 8 3 1 7 5 2 
Solution 40: 4 7 1 8 5 2 6 3 
Solution 41: 4 7 3 8 2 5 1 6 
Solution 42: 4 7 5 2 6 1 3 8 
Solution 43: 4 7 5 3 1 6 8 2 
Solution 44: 4 8 1 3 6 2 7 5 
Solution 45: 4 8 1 5 7 2 6 3 
Solution 46: 4 8 5 3 1 7 2 6 
Solution 47: 5 1 4 6 8 2 7 3 
Solution 48: 5 1 8 4 2 7 3 6 
Solution 49: 5 1 8 6 3 7 2 4 
Solution 50: 5 2 4 6 8 3 1 7 
Solution 51: 5 2 4 7 3 8 6 1 
Solution 52: 5 2 6 1 7 4 8 3 
Solution 53: 5 2 8 1 4 7 3 6 
Solution 54: 5 3 1 6 8 2 4 7 
Solution 55: 5 3 1 7 2 8 6 4 
Solution 56: 5 3 8 4 7 1 6 2 
Solution 57: 5 7 1 3 8 6 4 2 
Solution 58: 5 7 1 4 2 8 6 3 
Solution 59: 5 7 2 4 8 1 3 6 
Solution 60: 5 7 2 6 3 1 4 8 
Solution 61: 5 7 2 6 3 1 8 4 
Solution 62: 5 7 4 1 3 8 6 2 
Solution 63: 5 8 4 1 3 6 2 7 
Solution 64: 5 8 4 1 7 2 6 3 
Solution 65: 6 1 5 2 8 3 7 4 
Solution 66: 6 2 7 1 3 5 8 4 
Solution 67: 6 2 7 1 4 8 5 3 
Solution 68: 6 3 1 7 5 8 2 4 
Solution 69: 6 3 1 8 4 2 7 5 
Solution 70: 6 3 1 8 5 2 4 7 
Solution 71: 6 3 5 7 1 4 2 8 
Solution 72: 6 3 5 8 1 4 2 7 
Solution 73: 6 3 7 2 4 8 1 5 
Solution 74: 6 3 7 2 8 5 1 4 
Solution 75: 6 3 7 4 1 8 2 5 
Solution 76: 6 4 1 5 8 2 7 3 
Solution 77: 6 4 2 8 5 7 1 3 
Solution 78: 6 4 7 1 3 5 2 8 
Solution 79: 6 4 7 1 8 2 5 3 
Solution 80: 6 8 2 4 1 7 5 3 
Solution 81: 7 1 3 8 6 4 2 5 
Solution 82: 7 2 4 1 8 5 3 6 
Solution 83: 7 2 6 3 1 4 8 5 
Solution 84: 7 3 1 6 8 5 2 4 
Solution 85: 7 3 8 2 5 1 6 4 
Solution 86: 7 4 2 5 8 1 3 6 
Solution 87: 7 4 2 8 6 1 3 5 
Solution 88: 7 5 3 1 6 8 2 4 
Solution 89: 8 2 4 1 7 5 3 6 
Solution 90: 8 2 5 3 1 7 4 6 
Solution 91: 8 3 1 6 2 5 7 4 
Solution 92: 8 4 1 3 6 2 7 5 
Total possibilities: 92
unix@unix-HP-280-G4-MT-Business-PC:~/TYB75_DAA_SurajYeola$ */

// Algorithm

/* 

algorithm place (k, i) {
    
    // Return true if a queen can be placed in kth row and ith column.
    // Otherwise it returns false.
    
    // x[] is a global array whose first k = 1 values have been set to absolute Abs(r)
    // Returns the Abs(r)
    
    for j:=1 to k-1 do
        if ((x[j] == i) || (Abs(x[j]-i) == Abs(j-k))) 
            returns false;
    return true;
}

Algorithm NQueen (k, n) {
    
    // Using backtracking, this procedure prints all possible placements of N Queen 
    // on an N*N chessboard so that they are non-attacking
    
    for i:=1 to n {
        if place(k, i) {
            x[k] = i;
            if (k == n) {
                write(x[1:n]);
            }
            else 
                NQueen(k+1, n);
        }
    }
}
*/