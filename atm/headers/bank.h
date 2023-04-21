#ifndef BANK_H
#define BANK_H
#include <string>
#include <fstream>
#include <vector>
#include "./costumers.h"


class Bank{
    private:
        Costumer* P_costumer;
    public:
        Costumer* get_ptr();

        bool WriteToCSVFile(string filename, vector<pair<string, int>> dataset);

        bool AuthenticateUser(string filename, string username, int pin);

        bool ReadCSVFile(string filename, string username, int correct_pin);
};

#endif