#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int answer = 0;

void signUp(){

    ofstream UserList("users_list.csv", ios_base::app);
    char username[20]; 
    char psswd[20];
    int age;
    char height[20];

    cout << "Enter Your Username: \n "; cin >> username;
    cout << "Enter your Password: \n"; cin >> psswd;
    cout << "Enter your age: \n"; cin >> age;
    cout << "Enter you height: \n"; cin >> height;
    
    UserList << username << ", " << psswd << ", " << age << ", " << height << ". \n";
    UserList.close();

    cout << "Registration Complete \n";


}

int login(){

    fstream file;

    file.open("user_list.csv", ios::in);
    char username[20];
    char psswd[20];

    cout << "Enter your username: "; cin >> username; 
    cout << "Enter your password: "; cin >> psswd;

    vector<string> row;
    string line, word, temp;

    while(file >> temp){
        row.clear();
        getline(file, line);
        stringstream s(line);

        while(getline (s, word, ',') ){

            row.push_back(word);

        }

        username = stoi(row[0]);


            

    }



    return 0;
}

void displayUser_Page(){
    cout << "Aici afisezi";
}



void menu(){
    switch (answer)
    {
    case 1: 
        login();
        break;
        
    case 2:
        signUp();
        break;

    case 3:
        cout<< "Good bye! \n";
        answer = 3;
        break;

    default:
        cout << "Please use 1,2 or 3!";
        break;
    } 

}


int main() {


   do{

    cout << "Hello, User! Choose an option from below!" << endl << "1. Login" << endl<< "2. Sign Up" << endl << "3. Exit" << endl;
    cout << "Your answer : "; cin >> answer; cout << endl;
  
        menu();    

    } while (answer != 3);
    
    return 0;

}

