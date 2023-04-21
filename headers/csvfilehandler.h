#ifndef CSVFileHandler_H
#define CSVFileHandler_H

#include <iostream>
#include <vector>

using namespace std;

class CSVFileHandler {
    public:
        vector<string> getCostumerInfo(string line);

        void addVectorToFile(string filename, vector<string> lines);

        bool isUserInFile(string filename, string username, int pin);

};

#endif