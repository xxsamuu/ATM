#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include "./costumers.h"
#include <iostream>

class Transactions {
    Costumer* P_client;
    public:
        Transactions(Costumer* p_client);

        void deposit(int amount);

        void withdraw(int amount);

        void updateBalance(string filename, int amount);

        int getBalance();
};

#endif 