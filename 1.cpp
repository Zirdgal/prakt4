#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#define ls 10 // i like global defines very cool

void printList(int list[], int listSize) {
    cout << endl;
    cout << "list: " << endl;
    for (int i=0; i< listSize; i++) {
        cout << list[i] << "  ";
    }
    cout << endl;
}

// sum all numbers in a list
void sumNumbers(int list[], int listSize) {
    int sum = 0; // the result we return
    for (int j=0;j<listSize;j++) { // go through each element, for some reason for each doesnt work in functions because the list isnt iterable through functions because it is a pointer
        if (j % 2 ==1) {
            sum += list[j]; // add all odd-indexed numbers in a list
        }
    }
    cout << "Result: " << sum << endl; // output list in the function because i am requried to
}
// generate numbers function
void generateNumbers(int list[], int listSize) {
    for(int i=0;i<listSize;i++) { // run 10 times
        list[i] = rand() % 15 - 7; // -7 to 7
        // -7 -6 -5 -4 -3 -2 -1 0 1 2 3 4 5 6 7 = 15 numbers total
    }
}

int main() {

    srand(time(0)); // seed for random numbers

    int list[ls] = {}; // 10 size list
    // generating numbers into list
    generateNumbers(list, ls);
    printList(list, ls);
    sumNumbers(list, ls);
    
    // system("pause"); // commented out due to being windows only command and giving an error to g++ linux compiler
    return 0;
}