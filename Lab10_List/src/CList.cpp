#include "CList.h"

CList::CList() {}

OperatorHandler CList::operator[](int index) {
    return OperatorHandler(data[index].value, data[index].typeName);
}

void CList::printRaw() {
    cout << "[";
    for (size_t i = 0; i < data.size(); i++) {
        cout << "'" << data[i].value << "'(" << data[i].typeName << ")";
        if (i < data.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int CList::size() {
    return data.size();
}
