/*
Name: Gaurav Manohar Patil
Roll: 60
Class: TY-B

Assignment 10: Develop a program for Travelling Salesman Problem using Branch and Bound.
*/

#include <iostream>
#include <climits>
using namespace std;

int rowReduction(int matrix[][10], int n) {
    int rowCost = 0;
    for (int i = 0; i < n; i++) {
        int minRow = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] < minRow) {
                minRow = matrix[i][j];
            }
        }
        if (minRow != INT_MAX && minRow > 0) {
            rowCost += minRow;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] != INT_MAX) {
                    matrix[i][j] -= minRow;
                }
            }
        }
    }
    return rowCost;
}

int columnReduction(int matrix[][10], int n) {
    int colCost = 0;
    for (int j = 0; j < n; j++) {
        int minCol = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (matrix[i][j] < minCol) {
                minCol = matrix[i][j];
            }
        }
        if (minCol != INT_MAX && minCol > 0) {
            colCost += minCol;
            for (int i = 0; i < n; i++) {
                if (matrix[i][j] != INT_MAX) {
                    matrix[i][j] -= minCol;
                }
            }
        }
    }
    return colCost;
}

int calculateBound(int matrix[][10], int n, int currentCost) {
    int reducedMatrix[10][10];
    memcpy(reducedMatrix, matrix, sizeof(reducedMatrix));

    int rowCost = rowReduction(reducedMatrix, n);
    int colCost = columnReduction(reducedMatrix, n);

    return currentCost + rowCost + colCost;
}

void tspBranchAndBound(int graph[][10], bool visited[], int matrix[][10], int currPos, int n, int count, int cost, int& minCost) {
    if (count == n && graph[currPos][0] > 0) {
        minCost = min(minCost, cost + graph[currPos][0]);
        return;
    }

    int bound = calculateBound(matrix, n, cost);

    if (bound >= minCost) {
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[currPos][i] > 0) {
            int tempMatrix[10][10];
            memcpy(tempMatrix, matrix, sizeof(tempMatrix));

            for (int j = 0; j < n; j++) {
                tempMatrix[currPos][j] = INT_MAX;
                tempMatrix[j][i] = INT_MAX;
            }
            tempMatrix[i][0] = INT_MAX; 

            visited[i] = true;
            tspBranchAndBound(graph, visited, tempMatrix, i, n, count + 1, cost + graph[currPos][i], minCost);
            visited[i] = false;
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    int graph[10][10];
    cout << "Enter the distance matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    bool visited[10] = {false};
    visited[0] = true;

    int matrix[10][10];
    memcpy(matrix, graph, sizeof(matrix));

    int initialCost = rowReduction(matrix, n) + columnReduction(matrix, n);

    int minCost = INT_MAX;
    tspBranchAndBound(graph, visited, matrix, 0, n, 1, initialCost, minCost);

    cout << "The minimum cost of the tour is: " << minCost << endl;

    return 0;
}

/* 0 20 30 10 11
15 0 16 4 2
3 5 0 2 4
19 6 18 0 3
16 4 7 16 0
*/

/*PS C:\Users\gp850\OneDrive\Desktop\TY_B_60> g++ Assignment10.cpp
PS C:\Users\gp850\OneDrive\Desktop\TY_B_60> ./a.exe
Enter the number of cities: 5
Enter the distance matrix:
0 20 30 10 11
15 0 16 4 2
3 5 0 2 4
19 6 18 0 3
16 4 7 16 0
The minimum cost of the tour is: 28
PS C:\Users\gp850\OneDrive\Desktop\TY_B_60>*/