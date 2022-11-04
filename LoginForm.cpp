#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>


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


void displayUser_Page(string username, string age, string height){

    cout << username << ", " << age << ", " << height;
}

vector <string> checkUser(string file_name, string search_username){

  
    vector <string> row;

    fstream file;
    file.open("users_list.csv", ios::in);

    bool found_user = false;
    string line, word_user, word_psswd, word_age, word_height;
    

    while(getline (file, word_user, ',') && !found_user){

            getline (file, word_psswd, ',');
            getline (file, word_age, ',');
            getline (file, word_height, '\n');

                 if(word_user == search_username)
                {        
                    found_user = true;
                    row.push_back(word_user);
                    row.push_back(word_psswd);
                    row.push_back(word_age);
                    row.push_back(word_height);
                }

            }

            return row;
         }


int login(){

    string username, psswd;

    cout << "Enter your username: "; cin >> username; 
    cout << "Enter your password: "; cin >> psswd;

    vector <string> data = checkUser("users_list.csv", username);

    

    // if(found_user == false){
            
    //     cout << "There is no user with this username and password \n";
    //     ask2signUp();
    //     }

    // displayUser_Page(username, age, height);

            
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

