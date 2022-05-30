#define PI 3.14159265
#include <iostream>
#include <fstream>

using namespace std;

class Point {
private:
    float x, y;
public:
    Point() {}
    ~Point() {}
    Point(float a, float b) : x(a), y(b) {}
    float getX() { return x; }
    float getY() { return y; }
    void setX(float a) { x = a; }
    void setY(float b) { y = b; }
    float Area() { return 0.0; }
};

class Geometry {
public:
    virtual float Area() = 0;
    virtual void Print();
    virtual bool PointInGeometry(Point* p);
};

class Triangle : public Geometry {
private:
    Point point1;
    Point point2;
    Point point3;
public:
    Triangle() {}
    ~Triangle() {}
    Triangle(Point p1, Point p2, Point p3) : point1(p1), point2(p2), point3(p3) { }
    Point getPoint1() { return point1; }
    Point getPoint2() { return point2; }
    Point getPoint3() { return point3; }
    void setPoint1(Point p1) { point1 = p1; }
    void setPoint2(Point p2) { point1 = p2; }
    void setPoint3(Point p3) { point1 = p3; }
    float Area() {
        float TArea = (point3.getX() * point2.getY() - point2.getX() * point3.getY() + point1.getX() * point3.getY() - point3.getX() * point1.getY() + point2.getX() * point1.getY() - point1.getX() * point2.getY()) / 2;
        if (TArea > 0) return TArea;
        else if (TArea < 0) return -TArea;
        else return 0.0;
    }
    void Print() {
        cout << "GeomID T " << point1.getX() << " " << point1.getY() << " " << point2.getX() << " " << point2.getY() << " " << point3.getX() << " " << point3.getY() << endl;
    }
    bool PointInGeometry(Point* p) {
        Point vecA;
        Point vecB;
        Point vecC;
        vecA.setX(point2.getX()-point1.getX());
        vecA.setY(point2.getY()-point1.getY());
        vecB.setX(point3.getX()-point1.getX());
        vecB.setY(point3.getY()-point1.getY());
        vecC.setX(p -> getX() - point1.getX());
        vecC.setY(p -> getY() - point1.getY());
        if ((vecA.getX()*vecB.getY() - vecA.getY()*vecB.getX()) * (vecA.getX()*vecC.getY() - vecA.getY()*vecC.getX()) < 0) {
            return false;
        } else return true;
    }
};

class Rectangle : public Geometry {
private:
    Point point1;
    Point point2;
public:
    Rectangle() {}
    ~Rectangle() {}
    Rectangle(Point p1, Point p2) : point1(p1), point2(p2) { }
    Point getPoint1() { return point1; }
    Point getPoint2() { return point2; }
    void setPoint1(Point p1) { point1 = p1; }
    void setPoint2(Point p2) { point2 = p2; }
    float Area() {
        float RArea = ( point2.getX() - point1.getY() ) * ( point2.getY() - point1.getY() );
        if(RArea > 0) return RArea;
        else if(RArea < 0) return -RArea;
        else return 0.0;
    }
    void Print() {
        cout << "GeomID R " <<  point1.getX() << " " << point1.getY() << " " << point2.getX() << " " << point2.getY() << endl;
    }
    bool PointInGeometry(Point* p) {
        float px = p -> getX();
        float py = p -> getY();
        float x1 = point1.getX();
        float y1 = point1.getY();
        float x2 = point2.getX();
        float y2 = point2.getY();
        if (px < x1 || px > x2 || py < y1 || py > y2) { return false; }
        else return true;
    }
};

class Square : public Geometry {
private:
    Point point;
    float side;
public:
    Square() {}
    ~Square() {}
    Square(Point p, float s) : point(p), side(s) { }
    Point getPoint() { return point; }
    float getSide() { return side; }
    void setPoint(Point p) { point = p; }
    void setSide(float s) { side = s; }
    float Area() { return side * side; }
    void Print() {
        cout << "GeomID S " << point.getX() << " " << point.getY() << " " << side << endl;
    }
    bool PointInGeometry(Point* p) {
        float px = p -> getX();
        float py = p -> getY();
        float x = point.getX();
        float y = point.getY();
        if (px < x || px > x+side || py < y || py > y+side) { return false; } 
        else return true;
    }
};

class Circle : public Geometry {
private:
    Point center;
    float radius;
public:
    Circle() {}
    ~Circle() {}
    Circle(Point c, float r) : center(c), radius(r) { }
    Point getCenter() { return center; }
    float getRadius() { return radius; }
    void setCenter(Point c) { center = c; }
    void setRadius(float r) { radius = r; }
    float Area() { return PI * radius * radius;}
    void Print() {
        cout << "GeomID C " << center.getX() << " " << center.getY() << " " << radius << endl;
    }
    bool PointInGeometry(Point* p) {
        float disdis = ((p -> getX()) - (center.getX())) * ((p -> getX()) - (center.getX())) + ((p -> getY()) - (center.getY())) * ((p -> getY()) - (center.getY()));
        float radrad = radius * radius;
        if (disdis < radrad) { return true; } 
        else return false;
    }
};

class GeomSet {
protected:
    int n;
    string GeomID;
    char geomType;
    Geometry* gm;
public:
    GeomSet() {}
    ~GeomSet() { delete gm; }
    int Insert() {
        cin >> n;
        gm = new Geometry[n];
        for (int i=0; i<n; i++) {
            cin >> GeomID >> geomType;
            switch (geomType) {
                case 'T':
                    {
                    Triangle t;
                    Point p1, p2, p3;
                    float x1, y1, x2, y2, x3, y3;
                    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
                    p1.setX(x1); p1.setY(y1); p2.setX(x2); p2.setY(y2); p3.setX(x3); p3.setY(y3); t.setPoint1(p1); t.setPoint2(p2); t.setPoint3(p3);
                    gm[i] = t;
                    }
                    break;
                case 'R':
                    {
                    Rectangle r;
                    Point p1, p2;
                    float x1, y1, x2, y2;
                    cin >> x1 >> y1 >> x2 >> y2;
                    p1.setX(x1); p1.setY(y1); p2.setX(x2); p2.setY(y2); r.setPoint1(p1); r.setPoint2(p2);
                    gm[i] = r;
                    }
                    break;
                case 'S':
                    {
                    Square s;
                    Point p;
                    float x, y, side;
                    cin >> x >> y >> side;
                    p.setX(x); p.setY(y); s.setPoint(p); s.setSide(side);
                    gm[i] = s;
                    }
                    break;
                case 'C':
                    {
                    Circle c;
                    Point ct;
                    float cx, cy, rad;
                    cin >> cx >> cy >> rad;
                    ct.setX(cx); ct.setY(cy); c.setCenter(ct); c.setRadius(rad);
                    gm[i] = c;
                    }
                    break;
                default:
                    return 0;
                    break;
            }
        }
        return n;
    }
    Geometry* operator[] (Point* p) {
        int cnt = 0;
        int smallGeom = 0;
        for( int i = 1; i < n; i++) {
            if(gm[i].PointInGeometry(p)){
                cnt++;
                if(gm[smallGeom].Area() > gm[i].Area()) smallGeom = i;
            }
        }
        if(cnt==0) return NULL;
        return gm + smallGeom;
    };
};

int main() {
    GeomSet A;
    A.Insert();
    for (int i=1; i<10; i++) {
		Point* p = new Point (0.1*i+0.01, 0.1*i+0.01);
		Geometry* geom = A[p];
		geom -> Print();
		delete p;
	}
    return 0;
}