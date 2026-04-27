#include <iostream>
#include <cstdlib>

using namespace std;



void printList(int list[], int listSize) {
    cout << endl;
    cout << "list: " << endl;
    for (int i=0; i< listSize; i++) {
        cout << list[i] << "  ";
        
    }
    cout << endl;
}
// i use pointers because you cant return 2 items
void findMin(int list[], int listSize, int& minVal, int& minPos) {
    minVal = 68; // bigger than the range so the first value always gets set to it
    for (int i=0;i<listSize;i++) {
        if (minVal > list[i]) {
            minPos = i;
            minVal = list[i];
        }
    }
}
void findMax(int list[], int listSize,int& maxVal, int& maxPos) {
    maxVal = -68; // smaller than the range so the first value always gets set to it
    for (int i=0;i<listSize;i++) {
        if (maxVal < list[i]) {
            maxPos = i;
            maxVal = list[i];
        }
    }
}

void swapMaxMin(int list[], int listSize) {
    int maxVal, minVal, minPos, maxPos;

    findMin(list, listSize, minVal, minPos);
    findMax(list, listSize, maxVal, maxPos);
    list[maxPos] = minVal;

    list[minPos] = maxVal;
    printList(list, listSize);
}


void fillList(int list[], int listSize) {
    for (int i=0; i<listSize;i++) {
        list[i] = rand() % 135 - 67; // -67... 67
    }

    printList(list, listSize);
}
int main() {

    int n = 0; // user inputted number definition

    cout << "Input how many numbers are going to be in the array: ";
    cin >> n;

    int *list = new int[n];// create a new dynamic array
    srand(time(0)); // set a seed for the random numbers

    fillList(list, n);
    
    swapMaxMin(list, n);


    // get rid of the dynamic array, i am on arch linux 
    delete[]list;
    list=NULL;

    // system("pause"); // commented out due to being windows only command and giving an error to g++ linux compiler
    return 0;
}