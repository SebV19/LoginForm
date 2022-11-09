#ifndef functions
#define functions

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


void ask2signUp();
void signUp();
void displayUser_Page(string username, string age, string height);
vector <string> checkUser(string file_name, string search_username);
int login();
void menu(int answer); 
    

#endif





