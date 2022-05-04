#include <iostream>
using namespace std;

// (매크로 상수) 구조체 Car 와 관련된 각종 정보를 상수화함. --> enum 으로 구조체 내부에 선언 가능
// #define ID_LEN 20
// #define MAX_SPD 200
// #define FUEL_STEP 2
// #define ACC_STEP 10
// #define BRK_STEP 10

namespace CAR_CONST {
    // 구조체 내에서만 유효한 상수를 enum으로 선언하기. 이름공간 사용하여 가독성 좋게 만듦.
    enum { ID_LEN = 20, MAX_SPD = 200, FUEL_STEP = 2, ACC_STEP = 10, BRK_STEP = 10 };
}
// 구주체 -> 클래스
class Car {
private: // 클래스 내에서만 접근 가능
    char gamerID[CAR_CONST::ID_LEN];   // 소유자 아이디
    int fuelGauge;          // 연료량
    int curSpeed;           // 현재 속도
public: // 어디서든 접근 가능
    void InitMembers(char *ID, int fuel);
    void ShowCarState();
    void Accel();
    void Break();

};

void Car :: InitMembers(char *ID, int fuel) {
    strcpy(gamerID, ID);
    fuelGauge=fuel;
    curSpeed=0;
}

void Car :: ShowCarState() { // 차의 정보 출력용 함수. 단순한 정보 출력 -> const 참조자를 매개변수로 선언.
    cout << "소유자 ID: " << gamerID << endl;
    cout << "연료량: " << fuelGauge << endl;
    cout << "현재 속도: " << curSpeed << "km/s" << endl << endl;
}

void Car :: Accel() {
    if (fuelGauge <= 0) return;
    else fuelGauge -= CAR_CONST::FUEL_STEP;

    if (curSpeed+CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD) {
        curSpeed=CAR_CONST::MAX_SPD;
        return;
    }
    curSpeed += CAR_CONST::ACC_STEP;
}

void Car :: Break() {
    if (curSpeed < CAR_CONST::BRK_STEP) {
        curSpeed = 0;
        return;
    }
    curSpeed -= CAR_CONST::BRK_STEP;
}

int main() {
    Car run99;
    run99.InitMembers("run99", 100);
    run99.Accel(); run99.Accel(); run99.Accel();
    run99.ShowCarState();
    run99.Break();
    run99.ShowCarState();
    return 0;
}
