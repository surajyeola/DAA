// Name: Suraj Yeola
// Roll No: 75
// Class: TY B BTech
// Branch: Computer Engineering 
// Course: Design and Analysis of Algorithm

// Assignment 06

// Problem Statement:
/*Develop a program to implement Optimal Binary Search Tree using Dynamic Programming.*/

#include <iostream>
#define max 20

using namespace std; 

// Main Function // Suraj Yeola Code
int main() {

    int i, j, k, n, min_cost, r[max][max];
	float p[max], q[max], w[max][max], c[max][max];
	
    cout << "Enter total number of nodes: ";
    cin >> n;

    cout << "\nEnter successful probabilities:\n";
    for (i = 1; i <= n; i++) {
        cin >> p[i];
    }
    
    cout << "\nEnter unsuccessful probabilities::\n";
    for (i = 0; i <= n; i++) {
        cin >> q[i];
    }

    for (i = 0; i <= n; i++) {
        c[i][i] = 0;  
        r[i][i] = 0;  
        w[i][i] = q[i];
    }

    for (i = 0; i < n; i++) {
        w[i][i + 1] = p[i + 1] + q[i] + q[i + 1];
        c[i][i + 1] = w[i][i + 1];
        r[i][i + 1] = i + 1;  
    }

    w[n][n] = q[n];
    c[n][n] = 0;
    r[n][n] = 0;

    for (int m = 2; m <= n; m++) {
        for (i = 0; i <= n - m; i++) {
            j = i + m;
            w[i][j] = w[i][j - 1] + p[j] + q[j];  
            c[i][j] = 99999;
            for (k = i + 1; k <= j; k++) {
                float cost = c[i][k - 1] + c[k][j] + w[i][j];
                if (cost < c[i][j]) {
                    c[i][j] = cost;  
                    r[i][j] = k;     
                }
            }
        }
    }
    cout << "\n\n";
    for (i = 0; i <= n; i++) {
        for (j = i; j <= n; j++) {
            cout << "w[" << i << "][" << j << "] = " << w[i][j] << "\n";
            cout << "c[" << i << "][" << j << "] = " << c[i][j] << "\n";
            cout << "r[" << i << "][" << j << "] = " << r[i][j] << "\n";
        }
        cout << "\n";
    }
    cout << "\nThe cost of OBST is: " << c[0][n] << "\n";

    return 0;
}

// Output: // Suraj Yeola Code

/*unix@unix-HP-280-G4-MT-Business-PC:~/TYB75_DAA_SurajYeola$ g++ newobst.cpp
unix@unix-HP-280-G4-MT-Business-PC:~/TYB75_DAA_SurajYeola$ ./a.out
Enter total number of nodes: 3

Enter successful probabilities:
0.5
0.1
0.05

Enter unsuccessful probabilities::
0.15
0.1
0.05
0.05


w[0][0] = 0.15
c[0][0] = 0
r[0][0] = 0
w[0][1] = 0.75
c[0][1] = 0.75
r[0][1] = 1
w[0][2] = 0.9
c[0][2] = 1.15
r[0][2] = 1
w[0][3] = 1
c[0][3] = 1.5
r[0][3] = 1

w[1][1] = 0.1
c[1][1] = 0
r[1][1] = 0
w[1][2] = 0.25
c[1][2] = 0.25
r[1][2] = 2
w[1][3] = 0.35
c[1][3] = 0.5
r[1][3] = 2

w[2][2] = 0.05
c[2][2] = 0
r[2][2] = 0
w[2][3] = 0.15
c[2][3] = 0.15
r[2][3] = 3

w[3][3] = 0.05
c[3][3] = 0
r[3][3] = 0


The cost of OBST is: 1.5
unix@unix-HP-280-G4-MT-Business-PC:~/TYB75_DAA_SurajYeola$ */