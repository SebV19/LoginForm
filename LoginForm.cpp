#include "functions.h"

#include <iostream>
using namespace std;

int main() {

    int answer;
    cout << "Hello, User! Choose an option from below!" << endl << "1. Login" << endl<< "2. Sign Up" << endl << "3. Exit" << endl;
    cout << "Your answer : "; cin >> answer; cout << endl;

    if(answer == 1 || answer == 2 || answer == 3){
        menu(answer);
        }
        else{
            system("clear");
            cout<<"Use only specified values! \n";
            }
        return 0;

}


