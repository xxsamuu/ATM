#include "../headers/costumers.h"
#include "../headers/csvfilehandler.h"
#include "../headers/bank.h"
#include <filesystem>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

Costumer* Bank::get_ptr(){
    return P_costumer;
}

bool Bank::WriteToCSVFile(string filename, vector<pair<string, int>> dataset){
    /*example of arguments:
        - filename: 'costumers.csv',
        - vector<pair<string, pair<vector<int>, int>>>: 'sam', 1221, 0 
    */
    try{
        std::ofstream f(filename, ios::app);

        //if file is blank (thus doesn't have columns) add columns name
        if(filesystem::is_empty(filename)){
            f << "username, pin, balance" << "\n";
        }
        
        f << "\n" <<  dataset.at(0).first << ", " << dataset.at(0).second << "," << 0 << "\n";
        cout << "user added successfully to file." << endl;

        cout << "Done." << endl;

        f.close();
        return true;

    }
    catch(const std::exception& e){
        cout << "error: " << e.what() << endl;
        return false;
    }
};

bool Bank::ReadCSVFile(string filename, string username, int correct_pin){
    /*here, check for a match in the username; if username is found, check if the PIN is valid. 
    If PIN is invalid, return unauthenticated msg. Otherwise, authenticate user and reference the 
    Costumer Class.
    */

    std::fstream f("costumers.csv");

    string search;
    bool isUserValid = false;

    std::getline(f, search); //this line is to get rid of the header row.

    while(std::getline(f, search)){
        CSVFileHandler handler;
        vector<string> vec = handler.getCostumerInfo(search);

        try{
            int pin = std::stoi(vec.at(1));
            if(vec.at(0) == username && stoi(vec.at(1)) == correct_pin){
                return true;
            }
        }catch(std::invalid_argument& e){
            cout << "pin is not a number" << endl;
            isUserValid = false;
        }
    }
    return isUserValid;
};

bool Bank::AuthenticateUser(string filename, string username, int pin) {
    std::fstream f(filename);
    if(!f){
        std::cout << "file not found, creating one..." << std::endl;
        std::ofstream file (filename); //it creates file if it's not there
        std::cout << "file created successfully, calling fn..." << "\n";
    }

    bool searchUser = ReadCSVFile("costumers.csv", username, pin);
    if(searchUser==true){
        cout << "user found." << endl;
        return true;
    }else{
        cout << "incorrect username/PIN" << endl;
        return false;
    }
};


