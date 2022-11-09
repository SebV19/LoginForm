#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <chrono>
#include <thread>
#include <stdio.h>



using namespace std;
using namespace std::literals::chrono_literals;

int answer = 0;
int login();

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


void displayUser_Page(string username, string age, string height){

    system("clear");
    cout << "\n Hello, " << username << endl
    << "Judging by the fact that you are " << age 
    << " years old and your height is " << height << endl;

    cout << '-' << std::flush;

    for (int i=0; i<1; i++) {

        this_thread::sleep_for(1s);
        cout << "\b\\" << std::flush;
        this_thread::sleep_for(1s);
        cout << "\b|" << std::flush;
        this_thread::sleep_for(1s);
        cout << "\b/" << std::flush;
        this_thread::sleep_for(1s);
        cout << "\b-" << std::flush;
        cout << "\b \n Your next lucky day will be in " << rand() %20 << " days. \n";


    }

    char random;
    cout << "Press any key + enter to exit \n"; cin >> random;
    exit(EXIT_SUCCESS);


    
}

void signUp(){

    ofstream UserList("users_list.csv", ios_base::app);
    string username, psswd, age, height, user2check; 

    cout << "Enter Your desired Username: \n "; cin >> username;

    checkUser("users_list.csv", username);
    vector <string> data = checkUser("users_list.csv", username);
    unsigned int dataSize = data.size();

    for(int i = 0; i < dataSize; i++)
        user2check = data[0];
    
     if(user2check != username){
                cout << "Enter your Password: \n"; cin >> psswd;
                cout << "Enter your age: \n"; cin >> age;
                cout << "Enter you height: \n"; cin >> height;
    
                UserList << username << "," << psswd << "," << age << "," << height << ". \n";
                UserList.close();
                cout << "Registration Complete \n \n";
                char loginnow;
                cout << "Do you want to login now? (y/n)"; cin >> loginnow;
                        if(loginnow == 'y')
                            login();

                        if(loginnow == 'n'){
                            cout << "Thank You\n ";
                            exit(EXIT_SUCCESS);

                        }

                        if(loginnow != 'y' || loginnow != 'n'){
                            cout << "Use only characters 'y for YES and 'n' for NO. \n \n";
                            signUp();        
                        }


     }

        else
        {
        system("clear");
        cout << "This username ( " << username << " ) is already taken, try again! \n";
        signUp(); 
        }

}



void ask2signUp(){

        cout << "Do you want to make an account? Y/N \n";
        char ans;
        cout << "Your answer: "; cin >> ans;

        if(ans == 'y')
            signUp();

        if(ans == 'n'){
            cout << "Thank You\n ";
            exit(EXIT_SUCCESS);

        }

        if(ans != 'y' || ans != 'n'){
            cout << "Use only characters 'y for YES and 'n' for NO. \n \n";
            ask2signUp();        
        }



}




int login(){

    string username, psswd, psswd2check;

    cout << "Enter your username: "; cin >> username; 
    cout << "Enter your password: "; cin >> psswd;

    vector <string> data = checkUser("users_list.csv", username);
    unsigned int dataSize = data.size();

    for(int i = 0; i < dataSize; i++)
        psswd2check = data[1];
    
     if(psswd2check == psswd)
            displayUser_Page(data[0], data[2], data[3]);
        else
        {
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
    cin.get();

    if(answer == 1 || answer == 2 || answer == 3)
            menu(); 
        else{
            cout<< "Use only 1, 2 or 3. \n";
            menu();
        }   

    } while (answer != 3);
    
    return 0;

}


