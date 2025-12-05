#include <iostream>
#include <vector>
#include "CList.h"

using namespace std;

int main() {
    CList list;

    list.append(100);
    list.append(3.14);
    list.append("Hello");


    int myInt = list[0];

    auto item0 = list[0];
    auto item1 = list[1];

    cout << "Item 0 Value: " << item0 << " | Original Type: " << item0.type() << endl;
    cout << "Item 1 Value: " << item1 << " | Original Type: " << item1.type() << endl;


    return 0;
}
