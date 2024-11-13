// Name: Suraj Yeola
// Roll No: 75
// Class: TY B BTech
// Branch: Computer Engineering 
// Course: Design and Analysis of Algorithm

// Assignment 01

// Problem Statement:
/*Develop a program to design a function for Binary Search using Divide and Conquer Strategies. Also compute its time complexity.*/

#include <iostream>
#include <stdlib.h>
using namespace std;

bool found = false;

// Non recursive binary search // Suraj Yeola Code
int nonRecursive (int array[], int n, int target) {
    int high=(n-1), low=0;
    int mid = (high+low)/2;
    cout << "Low\tHigh\tMid\n";
    if (n == 1) {
        if (target == array[0]) {
            cout << low << "\t" << high << "\t" << mid << endl;
            cout << "Element found in array\n";
            found = true;
        }
        else {
            found = false;
        }
    }
    else {
        while (low <= high) {
            if (target == array[mid]) {
                cout << low << "\t" << high << "\t" << mid << endl;
                cout << "Element found in array\n";
            	found = true;
            	break;
            }
            else if (array[mid] > target) {
                cout << low << "\t" << high << "\t" << mid << endl;
            	high = mid - 1;
            	mid = (low + high)/2;
            }
            else {
                cout << low << "\t" << high << "\t" << mid << endl;
                low = mid + 1;
            	mid = (low + high)/2;
            }
        }
    }
    if (!found) {
        cout << "Element not found!";
    }
    return 0;
}

// Recursive binary search // Suraj Yeola Code
void recursive (int array[], int low, int high, int target) {
    if (low <= high) {
        int mid = (low + high)/2;
        if (target == array[mid]) {
            cout << low << "\t" << high << "\t" << mid << endl;
            cout << "Element found in array\n";
            found = true;
        }
        else if (array[mid] > target) {
            cout << low << "\t" << high << "\t" << mid << endl;
            recursive(array, low, (mid-1), target);
        }
        else {
            cout << low << "\t" << high << "\t" << mid << endl;
            recursive(array, (mid+1), high, target);
        }
    }
}

// Main function // Suraj Yeola Code
int main () {
    int n;
    cout << "Enter total number of elements: ";
    cin >> n;
    int array[n];
    cout << "Enter elements of array: ";
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    cout << "\nSorted elements are:\n";
    for (int i=0; i<n; i++) {
        cout << array[i] << " ";
    }
    int target;
    cout << "\nEnter element to search: ";
    cin >> target;
    int op, ch;
    do {
        cout << "\nSelect operation to perform:\n1. Non recursive binary search\n2. Recursive binary search\n3. Exit     ";
        cin >> op;
        switch (op) {
            case 1: {
                found = false;
                nonRecursive (array, n, target);
                break;
            }
            case 2: {
                found = false;
                int high=(n-1), low=0;
    			int mid = (high+low)/2;
    			cout << "Low\tHigh\tMid\n";
    			if (n == 1) {
        			if (target == array[0]) {
            			cout << low << "\t" << high << "\t" << mid << endl;
            			cout << "Element found in array\n";
            			found = true;
        			}
        			else {
            			found = false;
        			}
    			}
    			else {
        			recursive(array, 0, (n-1), target);
   				}
    			if (!found) {
        			cout << "Element not found!";
    			}
            	break;
            }
            case 3: {
            	exit(0);
            	break;
            }
            default: {
            	cout << "\nEnter valid operation\n";
            	break;
            }
        }
        cout << "Do you want to continue? \n1. Yes 2. No     ";
        cin >> ch;
    }
    while (ch == 1);
    return 0;
}

          
// Output:

/*unix@unix-HP-280-G4-MT-Business-PC:~/TYB75_DAA_SurajYeola$ g++ assign01.cpp
unix@unix-HP-280-G4-MT-Business-PC:~/TYB75_DAA_SurajYeola$ ./a.out
Enter total number of elements: 5
Enter elements of array: 23 54 1 25 98

Sorted elements are:
1 23 25 54 98 
Enter element to search: 54

Select operation to perform:
1. Non recursive binary search
2. Recursive binary search
3. Exit     1
Low	High	Mid
0	4	2
3	4	3
Element found in array
Do you want to continue? 
1. Yes 2. No     1

Select operation to perform:
1. Non recursive binary search
2. Recursive binary search
3. Exit     2
Low	High	Mid
0	4	2
3	4	3
Element found in array
Do you want to continue? 
1. Yes 2. No     2
unix@unix-HP-280-G4-MT-Business-PC:~/TYB75_DAA_SurajYeola$ */           