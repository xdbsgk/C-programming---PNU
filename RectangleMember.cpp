#include <iostream>
using namespace std;

class AAA {
public:
    AAA() { cout << "enpty object\n"; }
    void ShowYourName() { cout << "I'm class AAA\n"; }
};

class BBB {
private:
    AAA &ref;
    const int &num;
public:
    BBB(AAA &r, const int &n): ref(r), num(n) { }
    void ShowYourName() {
        ref.ShowYourName();
        cout << "and" << endl;
        cout << "I ref num "<< num << endl;
    }
};

int main() {
    AAA obj1;
    BBB obj2(obj1, 20);
    obj2.ShowYourName();

    return 0;
}