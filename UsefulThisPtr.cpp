#include <iostream>
using namespace std;

class TwoNumbers {
private:
    int num1, num2;
public:
// 둘 다 사용이 가능함 !! 변수 이름 지을 때 고민할 필요 없음. this 를 잘 활용해보자.
    /*
    TwoNumbers(int num1, int num2) {
        this -> num1 = num1;
        this -> num2 = num2;
    } */
    TwoNumbers(int num1, int num2) : num1(num1), num2(num2) { }
    void ShowTwoNumbers() {
        cout << this -> num1 << endl;
        cout << this -> num2 << endl;
    }
};

int main() {
    TwoNumbers two(2, 4);
    two.ShowTwoNumbers();
    return 0;
}