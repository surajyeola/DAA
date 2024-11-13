// Name: Suraj Yeola
// Roll No: 75
// Class: TY B BTech
// Branch: Computer Engineering 
// Course: Design and Analysis of Algorithm

// Assignment 09

// Problem Statement:

/*Develop a program to implement 0/1 Knapsack Problem using Branch and Bound.*/

#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int level;    
    int profit;
    int weight;
    float bound;
};

struct CompareBound {
    bool operator()(Node const& n1, Node const& n2) {
        return n1.bound < n2.bound;
    }
};

float calculateBound(Node u, int n, int m, int W[], int P[]) {
    if (u.weight >= m) return 0;

    float profitBound = u.profit;
    int totalWeight = u.weight;
    int j = u.level + 1;

    while (j < n && totalWeight + W[j] <= m) {
        totalWeight += W[j];
        profitBound += P[j];
        j++;
    }

    if (j < n) {
        profitBound += (m - totalWeight) * ((float)P[j] / W[j]);
    }

    return profitBound;
}

int knapsackBranchAndBound(int n, int W[], int P[], int m) {
    priority_queue<Node, vector<Node>, CompareBound> pq;

    Node u, v;
    u.level = -1;
    u.profit = 0;
    u.weight = 0;
    u.bound = calculateBound(u, n, m, W, P);

    pq.push(u);
    int maxProfit = 0;

    while (!pq.empty()) {
        u = pq.top();
        pq.pop();

        if (u.bound <= maxProfit) continue;

        v.level = u.level + 1;

        v.weight = u.weight + W[v.level];
        v.profit = u.profit + P[v.level];

        if (v.weight <= m && v.profit > maxProfit) {
            maxProfit = v.profit;
        }

        v.bound = calculateBound(v, n, m, W, P);

        if (v.bound > maxProfit) {
            pq.push(v);
        }

        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = calculateBound(v, n, m, W, P);

        if (v.bound > maxProfit) {
            pq.push(v);
        }
    }

    return maxProfit;
}

// Main Function // Suraj Yeola Code
int main() {
    int P[10], W[10], n, m;

    cout << "Enter No. of elements: ";
    cin >> n;

    cout << "Enter the capacity of knapsack: ";
    cin >> m;

    for (int i = 0; i < n; i++) {
        cout << "Enter the Profit and Weight of Object " << i + 1 << ": ";
        cin >> P[i] >> W[i];
    }

    cout << "\nMaximum Profit using Branch and Bound: " << knapsackBranchAndBound(n, W, P, m) << endl;

    return 0;
}

// Output: // Suraj Yeola Code

/* PS D:\TYB75_DAA_SurajYeola> g++ Ass9.cpp
PS D:\TYB75_DAA_SurajYeola> ./a.exe
Enter No. of elements: 4
Enter the capacity of knapsack: 15
Enter the Profit and Weight of Object 1: 10 2 
Enter the Profit and Weight of Object 2: 10 4 
Enter the Profit and Weight of Object 3: 12 6
Enter the Profit and Weight of Object 4: 18 9

Maximum Profit using Branch and Bound: 38
PS D:\TYB75_DAA_SurajYeola> */