#include <iostream>
#include <cstring>
using namespace std;

class Person {
private:
    int age;
    char name[50];
public:
    Person(int myage, char * myname) : age(myage) { 
        strcpy(name, myname);
    }
    void WhatYourName() const {
        cout << "My name is " << name << endl;
    }
    void HowOldAreYou() const {
        cout << "I'm " << age << " years old" << endl;
    }
};

class UnivStudent : public Person {
private:
    char major[50];
public:
    UnivStudent(char * myname, int myage, char * mynmajor) : Person(myage, myname) {
        strcpy(major, mynmajor);
    }
    void WhoareYou() const {
        WhatYourName();
        HowOldAreYou();
        cout << "My major is " << major << endl << endl;
    }
};

int main() {
    UnivStudent ustd1("Lee", 22, "Computer Eng.");
    ustd1.WhoareYou();

    UnivStudent ustd2("Yoon", 21, "Electronic Eng.");
    ustd2.WhoareYou();
    return 0;
}