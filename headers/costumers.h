#ifndef COSTUMER_H
#define COSTUMER_H

#include <string>

using namespace std;

class Costumer {
public:
    Costumer(string username, int pin);

    string getName();
    int getPin();
    int getCurrentBalance();

private:
    string Username;
    int Pin;
    int Balance;
};

#endif
