/*Name : Sanchit Manik Shelke
Div : TY_B3_70
*/

#include <iostream>
using namespace std;


int knapsack(int W, int wt[], int pt[], int n) {
    int tb[n+1][W+1];

    
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                tb[i][w] = 0; 
            }
            else if (wt[i-1] <= w) {
                tb[i][w] = max(pt[i-1] + tb[i-1][w-wt[i-1]], tb[i-1][w]);
            }
            else {
                tb[i][w] = tb[i-1][w];
            }
        }
    }

     
    cout << "\nTable:\n";
    cout << "\ti\\W\t"; 
    for (int w = 0; w <= W; w++) {
        cout << w << "\t";
    }
    cout << "\n";
    
    for (int i = 0; i <= n; i++) {
        cout << "\t" << i << "\t";  
        for (int w = 0; w <= W; w++) {
            cout << tb[i][w] << "\t";
        }
        cout << "\n";
    }

    return tb[n][W];
}

int main() {
    int n, W;

    
    cout << "Enter the number of object: ";
    cin >> n;

    int pt[n], wt[n];

    
    cout << "Enter the values of the objecvt:\n";
    for (int i = 0; i < n; i++) {
        cout << "Profit of object " << i+1 << ": ";
        cin >> pt[i];
    }

    cout << "Enter the weights of the object:\n";
    for (int i = 0; i < n; i++) {
        cout << "Weight of object " << i+1 << ": ";
        cin >> wt[i];
    }

    
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    
    int maxVal = knapsack(W, wt, pt, n);
    
    
    cout << "\nMaximum value in Knapsack: " << maxVal << endl;

    return 0;
}
/*unix@unix-HP-280-G4-MT-Business-PC:~/TYb3_70$ g++ 01Knapsack.cpp
unix@unix-HP-280-G4-MT-Business-PC:~/TYb3_70$ ./a.out
Enter the number of object: 3
Enter the values of the objecvt:
Profit of object 1: 10
Profit of object 2: 12
Profit of object 3: 28
Enter the weights of the object:
Weight of object 1: 1
Weight of object 2: 2
Weight of object 3: 4
Enter the capacity of the knapsack: 6

Table:
	i\W	0	1	2	3	4	5	6	
	0	0	0	0	0	0	0	0	
	1	0	10	10	10	10	10	10	
	2	0	10	12	22	22	22	22	
	3	0	10	12	22	28	38	40	

Maximum value in Knapsack: 40
unix@unix-HP-280-G4-MT-Business-PC:~/TYb3_70$ 

*/
	

