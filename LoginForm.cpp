#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>


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

    cout << "Registration Complete \n \n";


}



void ask2signUp(){

        cout << "Do you want to make an account? Y/N \n";
        char ans;
        cout << "Your answer: "; cin >> ans;

        if(ans == 'y')
            signUp();

        if(ans == 'n'){
            cout << "Thank You/n ";
            exit(EXIT_SUCCESS);

        }

        if(ans != 'y' || ans != 'n'){
            cout << "Use only characters 'y for YES and 'n' for NO. \n \n";
            ask2signUp();        
        }



}


void displayUser_Page(string username){
    cout << "Aici afisezi";
    cout << username;
}

int login(){

    fstream file;

    file.open("users_list.csv", ios::in);
    string username;
    string psswd;
    int count = 0;

    cout << "Enter your username: "; cin >> username; 
    cout << "Enter your password: "; cin >> psswd;

    vector<string> row;
    string line, word, temp;

    while(!file.eof()){

        row.clear();
        getline(file, line);
        stringstream s(line);
    
        while(getline (s, word, ',' ) ){
            row.push_back(word);

        }
        if(username.compare(row[0]) == 0 && psswd.compare(row[1]) == 0){
            count = 1;
            username = row[0];
            displayUser_Page(username);
            break;
        }

        }

        if(count == 0){
            cout << "There is no user with this username and password \n";
            ask2signUp();
        }

    
    return 0;
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

