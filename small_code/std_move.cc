#include <iostream>
#include <string>

using namespace std;

class BigObject {

public:

    BigObject() {

        cout << "constructor. " << endl;
    }   

    ~BigObject() {

        cout << "destructor."<< endl;
    }

    BigObject(const BigObject&) {

        cout << "copy constructor." << endl;
    }

    BigObject(BigObject&&) {

        cout << "move constructor"<< endl;
    }
};

BigObject foo() {

    BigObject localObj;

    return localObj;

}

BigObject foo1(int n) {

    BigObject localObj, anotherLocalObj;

    if (n > 2) {

       return localObj;

    } else {

       return anotherLocalObj;

    }
}

BigObject foo(int n) {

    BigObject localObj, anotherLocalObj;

    if (n > 2) {

       return std::move(localObj);

    } else {

       return std::move(anotherLocalObj);

    }
}

int main() {

    BigObject obj = foo(1);
}