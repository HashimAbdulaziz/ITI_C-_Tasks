#ifndef OPERATOR_HANDLER_H
#define OPERATOR_HANDLER_H

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class OperatorHandler {
private:
    string& refData;
    string& refType;

public:
    OperatorHandler(string& data, string& type);

    string type();

    // CONVERSION
    template <typename T>
    operator T() const {
        stringstream ss(refData);
        T convertedValue;
        ss >> convertedValue;
        return convertedValue;
    }

    // ASSIGNMENT
    template <typename T>
    OperatorHandler& operator=(const T& value) {
        stringstream ss;
        ss << value;
        refData = ss.str();
        return *this;
    }

    friend ostream& operator<<(ostream& os, const OperatorHandler& handler);
};

#endif
