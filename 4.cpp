// to work on a two dimensional array we shall treat it as one long array
#include <cstdlib>
#include <iostream>

using namespace std;

void printList(int** list, int r, int c) {
    cout << "\nlist:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c ; j++) {
            cout << list[i][j] << "\t";
        }
        cout << endl;
    }
}
void fillList(int** list, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c ; j++) {
            list[i][j] = rand() % 135 - 67; // -67 ... 67
        }
    }
}

void getMaxVal(int** list, int r, int c, int maxColVals[], int maxColPos) {
    for (int i = 0; i<r;i++) {
        for (int j =0; j<c;j++) {
            if (j == maxColPos) {
                maxColVals[i] = list[i][j];
            }
        }
    }
}

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

void getMinVal(int** list, int r, int c, int minColVals[], int minColPos) {
    for (int i = 0; i<r;i++) {
        for (int j =0; j<c;j++) {
            if (j == minColPos) {
                minColVals[i] = list[i][j];
            }
        }
    }
}

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


void swapMaxMin(int** list, int r, int c) {

    int maxColPos, minColPos;

    int minColVals[c];
    int maxColVals[r];

    findMax(list, r, c, maxColPos);
    findMin(list, r, c, minColPos);
    getMinVal(list, r, c, minColVals, minColPos);
    getMaxVal(list, r, c, maxColVals, maxColPos);




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


    for (int i = 0; i < row; i++) {
        delete[]list[i];
        list[i] = NULL;
    }

    delete[]list;
    list = NULL;
    // system("pause"); // commented out due to being windows only command and giving an error to g++ linux compiler
    return 0;
}