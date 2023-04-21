#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "../headers/csvfilehandler.h"

using namespace std;

vector<string> CSVFileHandler::getCostumerInfo(string line){
    //this method receives as a parameter the line from which
    //to look up to all the propreties.
    vector<string> user;

    std::istringstream iss(line);

    std::string name;
    std::string pin_str;
    std::string balance;

    std::getline(iss, name, ',');
    std::getline(iss, pin_str, ',');
    std::getline(iss, balance, ',');

    user.push_back(name);
    user.push_back(pin_str);
    user.push_back(balance);

    return user;

}

void CSVFileHandler::addVectorToFile(string filename, vector<string> lines){
    std::ofstream outfile(filename);
    
    outfile << "username, pin, balance\n";

    for(const auto& line : lines){
        outfile << line << endl; //here, we're rewriting every line (stored in the vec) + the updated one.
    }

    outfile.close();
}
