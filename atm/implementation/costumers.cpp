#include "../headers/costumers.h"
#include "../headers/csvfilehandler.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

Costumer::Costumer(string username, int pin){
    Username = username;
    Pin = pin;
}

string Costumer::getName()
{
    return Username;
}

int Costumer::getPin()
{
    return Pin;
}

int Costumer::getCurrentBalance()
{
    string search;
    std::fstream f("costumers.csv");

    std::getline(f, search);

    while(std::getline(f, search)){
        CSVFileHandler handler;
        vector<string> vec = handler.getCostumerInfo(search);
        try{
            int pin = std::stoi(vec.at(1));
            if(vec.at(0) == Username){
                if(pin == Pin){
                    Balance = stoi(vec.at(2));
                    return Balance;
                }
            }
        }catch(std::invalid_argument& e){
            cout << "pin is not a number" << endl;
        }
    }
}
