/*Name : Suraj Yogesh Yeola
Div : TY_B3_75 */

#include <iostream>

using namespace std;

const int MAX = 256;

void findTwoSmallest(int freq[], bool included[], int n, int &min1, int &min2) {
    min1 = min2 = -1;

    for (int i = 0; i < n; i++) {
        if (!included[i] && (min1 == -1 || freq[i] < freq[min1])) {
            min2 = min1;
            min1 = i;
        } else if (!included[i] && (min2 == -1 || freq[i] < freq[min2])) {
            min2 = i;
        }
    }
}

void generateCodes(int left[], int right[], int index, string code, char huffmanCodes[MAX][MAX], int codeLength[MAX], char characters[], int n, int ch[]) {
    if (index == -1) return;

    
    if (left[index] == -1 && right[index] == -1) {
        for (int i = 0; i < n; i++) {
            if (ch[index] == characters[i]) {
                int len = code.length();
                codeLength[i] = len;
                for (int j = 0; j < len; j++) {
                    huffmanCodes[i][j] = code[j];
                }
                huffmanCodes[i][len] = '\0'; 
                break;
            }
        }
        return;
    }

   
    generateCodes(left, right, left[index], code + "0", huffmanCodes, codeLength, characters, n, ch);
    generateCodes(left, right, right[index], code + "1", huffmanCodes, codeLength, characters, n, ch);
}

void huffmanEncoding(char characters[], int frequencies[], int n) {
    int ch[MAX];
    int freq[MAX];
    int left[MAX], right[MAX];
    bool included[MAX];
    int parent[MAX];
    
    
    for (int i = 0; i < MAX; i++) {
        included[i] = false;
        left[i] = -1;
        right[i] = -1;
        parent[i] = -1;
        freq[i] = 0; 
    }

   
    for (int i = 0; i < n; i++) {
        ch[i] = characters[i];
        freq[i] = frequencies[i];
    }

    int totalNodes = n;

   
    for (int i = 0; i < n - 1; i++) {
        int min1, min2;
        findTwoSmallest(freq, included, totalNodes, min1, min2);

        
        ch[totalNodes] = '\0'; 
        freq[totalNodes] = freq[min1] + freq[min2];
        left[totalNodes] = min1;
        right[totalNodes] = min2;

        
        included[min1] = true;
        included[min2] = true;

        
        included[totalNodes] = false;
        parent[min1] = parent[min2] = totalNodes;

        totalNodes++;
    }

    
    char huffmanCodes[MAX][MAX];
    int codeLength[MAX];
    int totalFreq = 0;
    float weightedCodeLengthSum = 0;

    
    for (int i = 0; i < MAX; i++) {
        codeLength[i] = 0;
    }

    generateCodes(left, right, totalNodes - 1, "", huffmanCodes, codeLength, characters, n, ch);

   
    cout << "\nCharacter | Frequency | Huffman Code | Code Size\n";
    cout << "-----------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << "    " << characters[i] << "     |     " << frequencies[i] << "     |     " << huffmanCodes[i] << "     |     " << codeLength[i] << "\n";
        weightedCodeLengthSum += frequencies[i] * codeLength[i];
        totalFreq += frequencies[i];
    }

    
    float averageCodeLength = weightedCodeLengthSum / totalFreq;
    cout << "\nAverage Code Length: " << averageCodeLength << endl;
}

int main() {
    int n;
    cout << "Enter the number of characters: ";
    cin >> n;

    char characters[MAX];
    int frequencies[MAX];

    cout << "Enter the characters:\n";
    for (int i = 0; i < n; i++) {
        cin >> characters[i];
    }

    cout << "Enter the frequencies:\n";
    for (int i = 0; i < n; i++) {
        cin >> frequencies[i];
    }

    huffmanEncoding(characters, frequencies, n);

    return 0;
}

/*unix@unix-HP-280-G4-MT-Business-PC:~/surajyeola$ g++ Assignment03.cpp
unix@unix-HP-280-G4-MT-Business-PC:~/surajyeola$ ./a.out
Enter the number of characters: 4             
Enter the characters:
a b c d
Enter the frequencies:
5 1 6 3

Character | Frequency | Huffman Code | Code Size
-----------------------------------------------
    a     |     5     |     11     |     2
    b     |     1     |     100     |     3
    c     |     6     |     0     |     1
    d     |     3     |     101     |     3

Average Code Length: 1.86667
unix@unix-HP-280-G4-MT-Business-PC:~/surajyeola$ */
	

