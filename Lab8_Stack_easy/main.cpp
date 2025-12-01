#include <iostream>
#include "Stack.h"

using namespace std;



int main()
{

    Stack s1(10);
    s1.push(10);
    s1.push(10);
    s1.push(23);
    s1.push(24);
    cout << s1 << endl;

    cout << "The top is " << s1.top() << endl;;

    cout << "Is it Empty?! " << s1.empty() << endl;

    cout << "Sack size = " << s1.size() << endl;

    Stack s2 = s1; // call Copy Constructor
    cout << s2 << endl;

    Stack s3(5);
    s3 = s2; // call Assigment Copy Constructor
    cout << s3 << endl;




    return 0;
}
