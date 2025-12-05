#ifndef CLIST_H
#define CLIST_H

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <typeinfo> // Needed to get type names
#include "OperatorHandler.h"

using namespace std;

// Internal storage structure
struct Node {
    string value;
    string typeName;
};

class CList {
private:
    vector<Node> data;

public:
    CList();

    // Append
    template <typename T>
    void append(const T& value) {
        stringstream ss;
        ss << value;

        Node newNode;
        newNode.value = ss.str();
        newNode.typeName = typeid(T).name();

        data.push_back(newNode);
    }

    OperatorHandler operator[](int index);

    void printRaw();
    int size();
};

#endif
