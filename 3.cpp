#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*  
[0.0] [0.1] [0.2]
[1.0] [1.1] [1.2]
[2.0] [2.1] [2.2]
*/

// this function was for debugging purposes to see if it was using the correct values
void displayList(int list[][3]) {
    for (int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            cout << list[i][j] << '\t';
        }
        cout << endl;
    }
}

int timesAdjacentDiagonals(int list[][3]) {
    int res = 1;

    int i = 0;
    int j = 2;
    while(i <3 && j > -1) {

        res *= list[i][j];

        i++;
        j--;
    }
    // go down by each level(i) and go left (j)

    return res;
}

void userFilledList(int list[][3]) {
    int userInput = 0;
    for (int i =0;i<3;i++) {
        for (int j=0;j<3;j++) {
            cout << "Type in a number: ";
            cin >> userInput;
            if (cin.fail()) {
                cout << "Please type in a number :)";
                return;
            }
            list[i][j] = userInput;
        }
    }
}

void randomlyFilledList(int list[][3]) {
    for (int i=0; i<3; i++) {
        for (int j=0;j<3; j++) {
            list[i][j] = rand() % 201 - 100; // -100... 100
        }
    }
}


int main() {
    srand(time(0)); // seed the time
    int list[3][3] = {}; // make two dimensional list
    int userInput = 0;
    // get user choices 
    cout << "How do you want to fill the two dimensional static array?" << endl;
    cout << "Input 1 for user inputted list or input 2 for randomly generated list: ";
    cin >> userInput;

    // if user types something that isnt a number
    if (cin.fail()) {
        cout << "Please type in 1 or 2!";
        return 1;
    }

    if (userInput == 1) {
        userFilledList(list);
    }
    else if (userInput == 2) {
        randomlyFilledList(list);
    }
    else { // if user doesnt type in 1 or 2
        cout << "Please type in 1 or 2!";
        return 1;
    }

    // display list, uncomment for debugging purposes
    displayList(list);

    cout << "result: " << timesAdjacentDiagonals(list);

    // system("pause"); // commented out due to being windows only command and giving an error to g++ linux compiler
    return 0;
}