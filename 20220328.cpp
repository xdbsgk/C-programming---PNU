// 코드 체크해야 함 ..

#include <iostream>

using namespace std;

class Point {
private:
    int x, y, z;
public:
    Point();
    ~Point();
    Point(int, int, int);
    Point(const Point &a); // copy constructor
    PrintPoint()  { cout << "(" << x << ", " << y << ", " << z << ")\n"; return 0; }
    // friend 선언 후 class명을 써 주면 private 객체도 접근 가능함.
    // 일일이 get함수 새로 짜면 너무 복잡함. 제한된 경우에 접근 가능하도록 설정하기.
    friend Point operatorSum(const Point, const Point);
    friend Point operator+(const Point&, const Point&);
};

Point :: Point() {
    // 디폴트 값을 0으로 지정하기
    cout << "default constructor\n";
}

Point :: Point(int a, int b, int c): x(a), y(b), z(c) {
    cout << "Constructor with three parameters\n";
}

Point :: Point(const Point &a) {
    x = a.x; y = a.y; z = a.z;
    cout << "copy constructor\n";
}

Point :: ~Point() {
    cout << "destructor\n";
}

Point operatorSum(const Point a, const Point b) {
    Point c;
    c.x = a.x + b.x; c.y = a.y + b.y; c.z = a.z + b.z;
    return c;
}

Point operator+(const Point &a, const Point &b) {
    Point c;
    c.x = a.x + b.x; c.y = a.y + b.y; c.z = a.z + b.z;
    return c;
}

void functionA(Point &m) {
    cout << "functionA\n";  m.PrintPoint();
}

int main() {
    Point firstPoint(1, 2, 3);
    functionA(firstPoint);
    Point *secondPoint = new Point (4, 5, 6);
    functionA(*secondPoint);
//    Point *thirdPoint = new Point[10];
//    functionA(*secondPoint);    
//    Point fourthPoint;
//    fourthPoint.PrintPoint();
//    Point thirdPoint = operatorSum(firstPoint, fourthPoint);
//    fourthPoint = firstPoint + fourthPoint ;
//    fourthPoint.PrintPoint();
//    functionA(thirdPoint);
//    delete[] thirdPoint;
//    (1+firstPoint).PrintPoint();
//    delete[] thirdPoint;
    return 0;
}