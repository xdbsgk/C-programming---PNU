#include <iostream>
#include <cstring>
using namespace std;

class SoSimple {
private:
    int num;
public:
    SoSimple(int n) : num(n) {
        cout << "num: " << num << ", " << "address= " << this << endl;
    }
    void ShowSimpleData() {
        cout << num << endl;
    }
    // this는 객체 자신의 주소값을 의미함 !!
    SoSimple *GetThisPointer() { return this; }
};

int main() {
    SoSimple sim1(100);
    SoSimple *ptr1 = sim1.GetThisPointer();
    cout << ptr1 << ", ";
    ptr1 -> ShowSimpleData();

    SoSimple sim2(200);
    SoSimple *ptr2 = sim2.GetThisPointer();
    cout << ptr2 << ", ";
    ptr2 -> ShowSimpleData();

    return 0;
}