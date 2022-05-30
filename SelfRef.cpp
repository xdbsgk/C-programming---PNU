#include <iostream>
using namespace std;

class SelfRef {
private:
    int num;
public:
    SelfRef(int num) : num(num) { cout << "객체 생성\n"; }
    SelfRef& Adder(int n) {
        num += n;
        return *this;
    }
    SelfRef& ShowTwoNumbers() {
        cout << num << endl;
        return *this;
    }
};
int main() {
    SelfRef obj(3);
    SelfRef &ref = obj.Adder(2);

    obj.ShowTwoNumbers();
    ref.ShowTwoNumbers();

    ref.Adder(1).ShowTwoNumbers().Adder(2).ShowTwoNumbers();

    return 0;
}