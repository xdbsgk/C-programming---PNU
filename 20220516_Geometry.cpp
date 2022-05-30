#define PI 3.14159265
#include <iostream>
#include <new>

using namespace std;

enum GeomType { POINT, LINE, POLYGON, CIRCLE };

class Geometry {
private:
    int geomtype;
public:
    Geometry() { };
    ~Geometry() { };
    Geometry(GeomType gt): geomtype(gt) { };
    virtual float perimeter() = 0;
};

class Polygon : public Geometry {
private:
    Point* vertices;
    int numVertices;
public:
    Polygon() { };
    Polygon(int n) { 
        numVertices = n; 
        Point* vertices = new Point[n];
    }
    ~Polygon() { delete[] vertices; }
    Polygon(Point* v, int nv) : vertices(v), numVertices(nv) { };
    float perimeter() { return 0.0; }
};

class Point : public Geometry {
private:
    float x, y;
public:
    Point() { };
    ~Point() { };
    Point(float a, float b) : x(a), y(b) { };
    float perimeter() { return 0.0; }
};

class Line : public Geometry {
private:
    Point p1,p2;
public:
    Line() { };
    ~Line() { };
    Line(Point a, Point b) : p1(a), p2(b) { };
    float perimeter() { return 0.0; }
};

class Circle : public Geometry {
private:
    Point center;
    float radius;
public:
    Circle() { };
    ~Circle() { };
    Circle(Point c, float r) : center(c), radius(r) { };
    float perimeter() { return 0.0; }
};

class Node {
private:
    Geometry *geom;
    Node *next;
public:
    Node(Geometry* g) : geom(g), next(NULL) { };    // next 값은 알지 못하니 null로 집어넣기
    ~Node() { };
    void setGeom(Geometry g) { geom = g; }
    void setNext(Node n) { next = n; }
    Node getNext() { return next; }
    Geometry* getGeometry() { return geom; }
    Node* getNext() { return next; }
};

// Linked List
class GeomLL {
private:
    Node *head; // 제일 첫 번째 노트에 대한 포인터
public:
    GeomLL() : head(NULL) { };
    ~GeomLL() { };
    // Linked List에 새로운 객체의 입력
    void insertFront(Node* h, Geometry* g) { };
    void insertFront(Geometry* g) {
        Node *newNode;
        try {
            newNode = (Node*)new Node;
        } catch (bad_allocation ba) {
            cout << "Memort  Allocation Error" << endl;
        }
        newNode -> setGeom(g);      // Boundary Condition, Exception
        newNode -> setNext(head);
        head = newNode;
        if (head == NULL) {
            newNode -> setNext(NULL);
            head = newNode;
        }
    }
    // Linked List의 i 번째 객체 검색
    Node* operator[](int n) {
        int count = 0;
        while(head != NULL) {
            for (int i=0; i<n; i++) {
                if (count = i) {
                    return head;
                } else {
                    head = head -> getNext();
                    ++count;
                }
            }
        }
    }
    // Linked List 내 객체의 길이 합
    float sumPerimeter() { };
    // 현재 Linked List 의 객체 수 count
    int countNode() { };
};

int main() {

    return 0;
}