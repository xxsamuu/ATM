#include <iostream>
#include <fstream>
#include <sstream>
#include "../headers/transactions.h"
#include "../headers/costumers.h"
#include "../headers/csvfilehandler.h"

using namespace std;


Transactions::Transactions(Costumer* p_client){
    P_client = p_client;
}

void Transactions::deposit(int amount){
    if(amount){
        updateBalance("costumers.csv", amount);
        cout << amount << " deposited, Current balance: " << P_client->getCurrentBalance() << endl;
    }else{
        cout << "Cannot deposit " << amount << " , invalid format." << endl;
    }
};

void Transactions::withdraw(int amount){
    int currentBalance = P_client->getCurrentBalance();

    if((currentBalance - amount) >= 0){
        updateBalance("costumers.csv", -amount);
    }else{
        cout << "insufficient funds." << endl;
    };
};

void Transactions::updateBalance(string filename, int amount){
    cout << "inside function, adding to balance value of: " << amount << endl;

    CSVFileHandler handler;

    vector<string> lines; //this is where we'll store users and make changes, for then to add it to file.
    std::fstream file(filename);

    bool found = false;

    string line; //this is the var where the line of file will be stored.
    std::getline(file, line); //this is to skip the first line which are the name of attributes.


    while(std::getline(file, line)){
        lines.push_back(line); //here, we're adding every line in the file in the vector.
    };

    for(auto& line : lines){ //acting on the vector.
        vector<string> vec = handler.getCostumerInfo(line);

        if(vec.at(0) == P_client->getName() && stoi(vec.at(1)) == P_client->getPin()){
            int new_balance = stoi(vec.at(2)) + amount;

            std::ostringstream oss;
            oss << vec.at(0) << "," << vec.at(1) << ", " << std::to_string(new_balance); //here, we're changing only the vector
            line = oss.str();

            found = true;

            break;
        }
    };

    if(found){
        handler.addVectorToFile(filename, lines);
    }

    file.close();
}

int Transactions::getBalance(){
    return P_client->getCurrentBalance();
};