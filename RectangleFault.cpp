#include <iostream>
using namespace std;

class Point {
public:
    int x;  // x 좌표의 범위는 0 이상 100 이하
    int y;  // y 좌표의 범위는 0 이상 100 이하
};

class Rectangle {
public:
    Point upLeft;
    Point lowRight;
public:
    void ShowRecInfo() {
        cout << "좌 상단: " << '[' << upLeft.x << ", " << upLeft.y << ']' << endl;
        cout << "우 하단: " << '[' << lowRight.x << ", " << lowRight.y << ']' << endl;        
    }
};

int main() {
    Point pos1 = {-2, 4};
    Point pos2 = {5, 9};
    Rectangle rec = {pos2, pos1};   // Retangle 객체 rec 생성 및 초기화
    rec.ShowRecInfo();
    return 0;
}