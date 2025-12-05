#include "OperatorHandler.h"

OperatorHandler::OperatorHandler(string& data, string& type)
    : refData(data), refType(type) {
}

string OperatorHandler::type() {
    return refType;
}

ostream& operator<<(ostream& os, const OperatorHandler& handler) {
    os << handler.refData;
    return os;
}
