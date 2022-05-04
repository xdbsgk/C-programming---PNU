#include <iostream>
using namespace std;

class Point {
private:    // x 와 y 의 정보 은닉
    int x;
    int y;
public:
    bool InitMembers(int xpos, int ypos);
    int GetX() const;
    int GetY() const;
    bool SetX(int xpos);
    bool SetY(int ypos);
};

bool Point::InitMembers(int xpos, int ypos) {
    if(xpos<0 || ypos<0) {
        cout << "벗어난 범위의 값 전달\n";
        return false;
    }
    x=xpos;
    y=ypos;
    return true;
}

int Point::GetX() const { return x; }   // const 함수 : 이 함수 내에서는 멤버변수에 저장된 값을 변경하지 않겠다.
int Point::GetY() const { return y; }

bool Point::SetX(int xpos) {
    if (0>xpos || xpos>100) {
        cout << "벗어난 범위의 값 전달 \n";
        return false;
    }
    x=xpos;
    return true;
}

bool Point::SetY(int ypos) {
    if (0>ypos || ypos >100) {
        cout << "벗어난 범위의 값 전달 \n";
        return false;
    }
    y=ypos;
    return true;
}

class Rectangle {
private:
    Point upLeft;
    Point lowRight;
public:
    bool InitMembers(const Point &ul, const Point &lr);
    void ShowRecInfo() const;
};

bool Rectangle::InitMembers(const Point &ul, const Point &lr) {
    if (ul.GetX()>lr.GetX() || ul.GetY()>lr.GetY()) {
        cout << "잘못된 위치정보 전달\n";
        return false; 
    }
    upLeft=ul;
    lowRight=lr;
    return true;
}

void Rectangle::ShowRecInfo() const {   // const 함수
    cout << "좌 상단: [" << upLeft.GetX() << ", " << upLeft.GetY() << "]\n";
    cout << "우 하단: [" << lowRight.GetX() << ", " << lowRight.GetY() << "]\n";
}

int main() {
    Point pos1;
    if (!pos1.InitMembers(-2, 4)) cout << "초기화 실패\n";
    if (!pos1.InitMembers(2, 4)) cout << "초기화 실패\n";
    Point pos2;
    if (!pos2.InitMembers(5, 9)) cout << "초기화 실패\n";
    Rectangle rec;
    if (!rec.InitMembers(pos2, pos1)) cout << "직사각형 초기화 실패\n";
    if (!rec.InitMembers(pos1, pos2)) cout << "직사각형 초기화 실패\n";
    rec.ShowRecInfo();
    return 0;
}