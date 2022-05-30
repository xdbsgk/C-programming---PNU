#include <iostream>
using namespace std;

class Point {
private:
    int x, y;
public:
    Point(const int &xpos, const int &ypos) : x(xpos), y(ypos) { }
    int GetX() const { return x; }
    int GetY() const { return y; }
    bool SetX(int xpos) {
        if (0>xpos || xpos >100) {
            cout << "벗어난 범위의 값 전달" << endl;
            return false;
        }
        x=xpos;
        return true;
    }
    bool SetY(int ypos) {
        if (0>ypos || ypos >100) {
            cout << "벗어난 범위의 값 전달" << endl;
            return false;
        }
        y=ypos;
        return true;
    }
};

class Rectangle {
private:
    Point upLeft;
    Point lowRight;
public:
    Rectangle(const int &x1, const int &y1, const int &x2, const int &y2) : upLeft(x1, y1), lowRight(x2, y2) { }
    void SHowRecInfo() const {
        cout << "좌 상단: " << "[" << upLeft.GetX() << ", " << upLeft.GetY() << "]\n";
        cout << "우 하단: " << "[" << lowRight.GetX() << ", " << lowRight.GetY() << "]\n";
    }
};

int main() {
    Rectangle rec(1, 1, 5, 5);
    rec.SHowRecInfo();
    return 0;
}