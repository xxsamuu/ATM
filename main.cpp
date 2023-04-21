#include <iostream>
#include <vector>
#include <utility>
#include <bits/stdc++.h> 

#include "./headers/bank.h"
#include "./headers/csvfilehandler.h"
#include "./headers/costumers.h"
#include "./headers/transactions.h"


using namespace std;


int display_options(string action);
void LoginMenu(Bank* b);
bool isPinFormatGood(string& pin_string, int& pin, string name,  Bank* b);
bool signupMenu(string filename, Bank* b, string& name, int& pin);
void MainMenu(Transactions clientHandler);

int main(){
    
    Bank bank;
    Bank* b;
    b = &bank;

    LoginMenu(b);

    return 0;
}



int display_login(){
    int choice;

    std::cout 
    << "========================================\n"
    << "|             Login Menu                |\n"
    << "========================================\n"
    << "|  Options: \n"
    << "|      1. Login           |\n"
    << "|      2. Signup          |\n"
    << "===========================\n"
    << "Enter your choice: ";


    std::cin >> choice;

    return choice;

}

int display_menu(){
    int choice; 

    std::cout 
    << "========================================\n"
    << "|            Main Menu                  |\n"
    << "========================================\n"
    << "|  Options: \n"
    << "|      1. Deposit           |\n"
    << "|      2. Withdraw          |\n"
    << "|      3. Balance Inquiry   |\n"
    << "|      4. Exit              |\n"
    << "=============================\n"
    << "Enter your choice: ";

    std::cin >> choice;

    return choice;
};

int display_options(string action){
    int choice {action == "login" ? display_login() : display_menu()};

    return choice;
};

bool isPinFormatGood(string& pin_string, int& pin){
    std::stringstream pin_ss(pin_string);
    pin_ss >> pin;

    if(pin_string.size() != 4 || (!pin || !pin_ss.eof())){
        cout << "Invalid Pin format. PIN must be a size of 4 and only digits. " << "\n";
        return false;
    }
    else{
        return true;
    }
}

bool signupMenu(string filename, Bank* b, string& name, int& pin){
    string pin_string;

    std::cout
    << "\n\n========================================\n"
    << "|             Signup Menu               |\n"
    << "========================================\n"
    << "| Please enter your desired username: ";

    cin >> name;

    std::cout
    << "| Now for the PIN (only 4 digits): ";
    
    cin >> pin_string;

    bool isPinFormatCorrect = isPinFormatGood(pin_string, pin);
    bool isUserAlreadyInSystem = b->ReadCSVFile("costumers.csv", name, pin);

    if(isUserAlreadyInSystem){
        cout << "user is already registered." << endl;
    }

    if(isPinFormatCorrect == true  && isUserAlreadyInSystem == false){
        vector<pair<string, int>> dataset;
        dataset.emplace_back(name, pin);
        cout << "| Adding user to system..." << "\n";
        return b->WriteToCSVFile("costumers.csv", dataset);
    }else{
        return false;
    }
    
};

void LoginMenu(Bank* b){
    int choice = display_options("login");
    string username;
    int pin;

    bool isUserAuthenticated;

    switch (choice)
    {
        case 1:

            std::cout << "Please enter the username: ";
            std::cin >> username;

            std::cout << "Now, enter the PIN (4 digits): ";
            std::cin >> pin;


            isUserAuthenticated = b->AuthenticateUser("costumers.csv", username, pin);
            //need to retrieve already initialized class.

            break;
        case 2:
            //check if user is already initiialized
            isUserAuthenticated = signupMenu("costumers.csv", b, username, pin);
            //need to create new costumer class
            break;

        default:
            cout << "invalid choice" << endl;
            break;
    }

    if(isUserAuthenticated){
        Costumer* p_client;

        Costumer client(username, pin);
        p_client = &client;

        Transactions clientHandler(p_client);
        MainMenu(clientHandler);
    }

};

bool isNumFormatGood(string input){
    return std::all_of(input.begin(), input.end(), ::isdigit); // C++11
};


void transaction_handler(Transactions clientHandler, string action){
    /*
    this function takes as input the desired amount to deposit
    and checks if that input is a number.
    */
    string amount;
    cout 
    << "enter the amount (only digits) you'd like to "
    << action
    << ": ";

    cin >> amount;

    if(amount != ""){
        bool isInputANum = isNumFormatGood(amount);

        if(isInputANum){
            action == "deposit" ? clientHandler.deposit(stoi(amount)) : clientHandler.withdraw(stoi(amount));
        }
    }else{
        cout << "please enter a valid value." << endl;
        MainMenu(clientHandler);
    }

}

void MainMenu(Transactions clientHandler) {
    int choice = display_options("menu") ;

    switch (choice)
    {
    case 1:
        transaction_handler(clientHandler, "deposit");
        MainMenu(clientHandler);
        break;
    case 2:
        transaction_handler(clientHandler, "withdraw");
        MainMenu(clientHandler);
        break;
    case 3:
        cout << "current balance: " 
        << clientHandler.getBalance() 
        << endl;
        MainMenu(clientHandler);
        break;
    case 4:
        break;

    default:
        cout << "invalid choice " << endl;
        break;
    };


};