// Name: Suraj Yeola
// Roll No: 75
// Class: TY B BTech
// Branch: Computer Engineering 
// Course: Design and Analysis of Algorithm

// Assignment 02

// Problem Statement:
/*Develop a program to design a class for concurrent quick sort using Divide and Conquer Strategies. Also compute its time complexity*/

#include <iostream>
using namespace std;

int v=1;

int partition (int array[], int l, int h, int n) {
	int pivot = array[l];
	int i = 0;
	int j = h;
	while (i < j) {
		while (array[i] <= pivot) {
			i++;
		}
		while(array[j] > pivot) {
			j--;
		} 
		if (i < j) {
			swap(array[i], array[j]);
		}
	}
	swap(array[j], array[l]);
	cout << "\nPass " << v <<": "<< endl;
	v++;
	for (int i=0; i<n; i++) {
		cout << " " << array[i];
	}
	cout << endl;
	return j;
}

void quickSort (int array[], int l, int h, int n) {
	if (l < h) {
		int p = partition (array, l, h, n);
		quickSort(array, l, p - 1, n);
		quickSort(array, p + 1, h, n);
	}
}

// Main function // Suraj Yeola Code
int main() {
	cout << "Enter total number of elements of array: ";
	int n;
	cin >> n;
	int array[n];
	cout << "Enter the elements of the array: ";
	for (int i=0; i<n; i++) {
		cin >> array[i];
	}
	quickSort(array, 0, n-1, n);
	cout << "\n\nSorted Array is: ";
	for (int i=0; i<n; i++) {
		cout << " " << array[i];
	}
	cout << endl;
	return 0;
}

// Output: // Suraj Yeola Code

/*unix@unix-HP-280-G4-MT-Business-PC:~/TYB75_DAA_SurajYeola$ g++ quick2.cpp
unix@unix-HP-280-G4-MT-Business-PC:~/TYB75_DAA_SurajYeola$ ./a.out
Enter total number of elements of array: 9
Enter the elements of the array: 65 70 75 80 85 60 55 50 45

Pass 1: 
 60 45 50 55 65 85 80 75 70

Pass 2: 
 55 45 50 60 65 85 80 75 70

Pass 3: 
 50 45 55 60 65 85 80 75 70

Pass 4: 
 45 50 55 60 65 85 80 75 70

Pass 5: 
 45 50 55 60 65 70 80 75 85

Pass 6: 
 45 50 55 60 65 70 80 75 85

Pass 7: 
 45 50 55 60 65 70 75 80 85


Sorted Array is:  45 50 55 60 65 70 75 80 85
unix@unix-HP-280-G4-MT-Business-PC:~/TYB75_DAA_SurajYeola$ */
