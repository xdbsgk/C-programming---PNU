#include <iostream>
#include <cstring>
using namespace std;

class Person {
private:
    char *name;
    int age;
public:
    Person(char *myname, int myage) {
        int len = strlen(myname) + 1;
        name = new char[len];
        strcpy(name, myname);
        age = myage;
    }
    Person() {
        name = NULL;
        age = 0;
        cout << "called Person()" << endl;
    }
    void SetPersonInfo(char *myname, int myage) {
        name = myname;
        age = myage;
    }
    void ShowPersonInfo() const {
        cout << "이름: " << name << endl;
        cout << "나이: " << age << endl;
    }
    ~Person() {
        delete []name;
        cout << "called destructor!" << endl;
    }
};

// 객체 배열
int main() {
    Person parr[3];
    char namestr[100];
    char *strptr;
    int age, len;

    for (int i=0; i<3; i++) {
        cout << "이름: ";
        cin >> namestr;
        cout << "나이: ";
        cin >> age;
        len = strlen(namestr) +1;
        strptr = new char[len];
        strcpy(strptr, namestr);
        parr[i].SetPersonInfo(strptr, age);
    }
    for (int j=0; j<3; j++) {
        parr[j].ShowPersonInfo();
    }
    return 0;
}