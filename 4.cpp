#include <cstdlib>
#include <iostream>

using namespace std;

// print the list
void printList(int** list, int r, int c) {
    // i feel like \n is more natural than << endl
    cout << "\nlist:\n";
    for (int i = 0; i < r; i++) { // i = rows
        for (int j = 0; j < c ; j++) { // j = columns
            cout << list[i][j] << "\t"; // print with a tab space inbetween
        }
        cout << endl; // okay but is '\n' and endl not the same character count
    }
}
// fill the list with random elements
void fillList(int** list, int r, int c) { 
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c ; j++) {
            list[i][j] = rand() % 135 - 67; // -67 ... 67
        }
    }
}

// save the collumn that holds the max value
void getMaxVal(int** list, int r, int c, int maxColVals[], int maxColPos) {
    for (int i = 0; i<r;i++) {
        for (int j =0; j<c;j++) {
            if (j == maxColPos) {
                maxColVals[i] = list[i][j];
            }
        }
    }
}
// find which item in the list has the highest value and save it columns
void findMax(int** list, int r, int c, int& maxColPos) {
    int maxVal = -68; // smaller than the entire array possible values

    for (int i = 0; i<r;i++) {
        for (int j = 0; j<c;j++) {
            if (maxVal < list[i][j]) {
                maxVal = list[i][j];
                maxColPos = j;
            }
        }
    }
}    
// same as getMaxVal but for minimum value
void getMinVal(int** list, int r, int c, int minColVals[], int minColPos) {
    for (int i = 0; i<r;i++) {
        for (int j =0; j<c;j++) {
            if (j == minColPos) {
                minColVals[i] = list[i][j];
            }
        }
    }
}

// same as FindMax but min
void findMin(int** list, int r, int c, int& minColPos) {
    int minVal = 68; // bigger than the entire array possible values

    for (int i = 0; i<r;i++) {
        for (int j = 0; j<c;j++) {
            if (minVal > list[i][j]) {
                minVal = list[i][j];
                minColPos = j;
            }
        }
    }
}

// sawp the two columns
void swapMaxMin(int** list, int r, int c) {

    int maxColPos, minColPos; // the positions are just a single int

    int minColVals[c]; // the values of the columns are arrays of just the collumn
    int maxColVals[r];

    // all 4 of the functions
    findMax(list, r, c, maxColPos);
    findMin(list, r, c, minColPos);
    getMinVal(list, r, c, minColVals, minColPos);
    getMaxVal(list, r, c, maxColVals, maxColPos);



    // swap the positions of the columns by just rewriting the list
    for (int i = 0; i<r;i++) {
        for (int j =0; j<c;j++) {
            if (j == minColPos) {
                list[i][j] = maxColVals[i];
            }
            if (j == maxColPos) {
                list[i][j] = minColVals[i];
            }
        }
    }

    printList(list, r, c);
}



int main() {
    srand(time(0));
    int row = 0;
    int col = 0;

    cout << "How many rows: ";
    cin >> row;
    cout << "How many columns: ";
    cin >> col;

    // check for errors
    if (cin.fail() || row < 1 || col < 1) {
        cerr << "Please input a whole number that isnt below 1!" << endl;
        return 1;
    }
    // two dimensional dynamic array
    int **list = new int*[row];
    for (int i = 0; i < row; i++) {
        list[i] = new int[col];
    }
    fillList(list, row, col);
    printList(list, row, col);
    swapMaxMin(list, row, col);

    // delete each sub array
    for (int i = 0; i < row; i++) {
        delete[]list[i];
        list[i] = NULL;
    }

    delete[]list;
    list = NULL;
    // system("pause"); // commented out due to being windows only command and giving an error to g++ linux compiler
    return 0;
}