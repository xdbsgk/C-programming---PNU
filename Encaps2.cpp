#include <iostream>
using namespace std;

class SinivelCap    // 콧물 처치용 캡슐
{
public:
    void Take() const { cout << "콧물이 싹~ 납니다." << endl; }
};

class SneezeCap     // 재채기 처치용 캡슐
{
public:
    void Take() const {}
};

