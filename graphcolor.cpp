// Name: Suraj Yeola
// Roll No: 75
// Class: TY B BTech
// Branch: Computer Engineering 
// Course: Design and Analysis of Algorithm

// Assignment 08

// Problem Statement:

/*Develop a program to implement Graph Coloring using backtracking method.*/

#include <iostream>
using namespace std;

const int MAX_NODES = 50;

static int m, n;
static int c = 0;
static int count = 0;
int g[MAX_NODES][MAX_NODES];
int x[MAX_NODES];        

void nextValue(int k);
void GraphColoring(int k);
int maxDegree();

// Main Function // Suraj Yeola Code
int main() {
    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "\nEnter Adjacency Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }

    int maxDeg = maxDegree();
    cout << "The maximum degree among all vertices is: " << maxDeg << endl;

    m = maxDeg + 1;
    cout << "Total number of colors allowed: " << m << endl;

    cout << "\nPossible Solutions are:\n";
    for (int i = 1; i <= m; i++) {
        if (c == 1) {
            break;
        }
        GraphColoring(0); 
    }

    cout << "The total number of solutions is " << count << endl;
    return 0;
}

void GraphColoring(int k) {
    while (true) {
        nextValue(k);
        if (x[k] == 0) {
            return;
        }

        if (k == n - 1) {
            c = 1;
            count++;
            cout << "Solution " << count << ": " << endl;
            for (int i = 0; i < n; i++) {
                cout << "Vertex " << i + 1 << " --->  Color " << x[i] << endl;
            }
            cout << endl;
        } 
        else {
            GraphColoring(k + 1);
        }
    }
}

void nextValue(int k) {
    while (true) {
        x[k] = (x[k] + 1) % (m + 1);
        if (x[k] == 0) {
            return;
        }
        bool conflict = false;
        for (int j = 0; j < n; j++) {
            if (g[k][j] == 1 && x[k] == x[j]) {
                conflict = true;
                break;
            }
        }
        if (!conflict) {
            return;
        }
    }
}


int maxDegree() {
    int maxDeg = 0;
    for (int i = 0; i < n; i++) {
        int degree = 0;
        for (int j = 0; j < n; j++) {
            if (g[i][j] == 1) {
                degree++;
            }
        }
        if (degree > maxDeg) {
            maxDeg = degree;
        }
    }
    return maxDeg;
}

// Output: // Suraj Yeola Code

/*PS C:\Users\suraj\desktop\TYB75_DAA_SurajYeola> g++ Assignment08.cpp
PS C:\Users\suraj\desktop\TYB75_DAA_SurajYeola> ./a.exe   
Enter the number of nodes: 4

Enter Adjacency Matrix:
0 1 0 1
1 0 1 0
0 1 0 1
1 0 1 0
The maximum degree among all vertices is: 2
Total number of colors allowed: 3

Possible Solutions are:
Solution 1: 
Vertex 1 --->  Color 1
Vertex 2 --->  Color 2
Vertex 3 --->  Color 1
Vertex 4 --->  Color 2

Solution 2:
Vertex 1 --->  Color 1
Vertex 2 --->  Color 2
Vertex 3 --->  Color 1
Vertex 4 --->  Color 3

Solution 3:
Vertex 1 --->  Color 1
Vertex 2 --->  Color 2
Vertex 3 --->  Color 3
Vertex 4 --->  Color 2

Solution 4:
Vertex 1 --->  Color 1
Vertex 2 --->  Color 3
Vertex 3 --->  Color 1
Vertex 4 --->  Color 2

Solution 5:
Vertex 1 --->  Color 1
Vertex 2 --->  Color 3
Vertex 3 --->  Color 1
Vertex 4 --->  Color 3

Solution 6:
Vertex 1 --->  Color 1
Vertex 2 --->  Color 3
Vertex 3 --->  Color 2
Vertex 4 --->  Color 3

Solution 7:
Vertex 1 --->  Color 2
Vertex 2 --->  Color 1
Vertex 3 --->  Color 2
Vertex 4 --->  Color 1

Solution 8:
Vertex 1 --->  Color 2
Vertex 2 --->  Color 1
Vertex 3 --->  Color 2
Vertex 4 --->  Color 3

Solution 9:
Vertex 1 --->  Color 2
Vertex 2 --->  Color 1
Vertex 3 --->  Color 3
Vertex 4 --->  Color 1

Solution 10:
Vertex 1 --->  Color 2
Vertex 2 --->  Color 3
Vertex 3 --->  Color 1
Vertex 4 --->  Color 3

Solution 11:
Vertex 1 --->  Color 2
Vertex 2 --->  Color 3
Vertex 3 --->  Color 2
Vertex 4 --->  Color 1

Solution 12:
Vertex 1 --->  Color 2
Vertex 2 --->  Color 3
Vertex 3 --->  Color 2
Vertex 4 --->  Color 3

Solution 13:
Vertex 1 --->  Color 3
Vertex 2 --->  Color 1
Vertex 3 --->  Color 2
Vertex 4 --->  Color 1

Solution 14:
Vertex 1 --->  Color 3
Vertex 2 --->  Color 1
Vertex 3 --->  Color 3
Vertex 4 --->  Color 1

Solution 15:
Vertex 1 --->  Color 3
Vertex 2 --->  Color 1
Vertex 3 --->  Color 3
Vertex 4 --->  Color 2

Solution 16:
Vertex 1 --->  Color 3
Vertex 2 --->  Color 2
Vertex 3 --->  Color 1
Vertex 4 --->  Color 2

Solution 17:
Vertex 1 --->  Color 3
Vertex 2 --->  Color 2
Vertex 3 --->  Color 3
Vertex 4 --->  Color 1

Solution 18:
Vertex 1 --->  Color 3
Vertex 2 --->  Color 2
Vertex 3 --->  Color 3
Vertex 4 --->  Color 2

The total number of solutions is 18
PS C:\Users\suraj\desktop\TYB75_DAA_SurajYeola>
*/