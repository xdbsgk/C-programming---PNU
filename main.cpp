#include <iostream>
//#include <malloc.h>

using namespace std;

class Point {
private:
//	float x,y;
public:
	float x,y;
	Point* operator->() {return this;}

	Point();
	~Point();
	Point(const Point&);
	Point(float,float);
	Point(float);
	void    inputPoint(float a,float b) {x=a; y=b;}
	const   void printPoint() {cout<<"("<<x<<","<<y<<")\n"; }
	Point   operator+(const Point&);
	Point   operator=(const Point&);
	Point   operator++();
	Point   operator++(int);
	void*   operator new(size_t);
	void    operator delete(void *);
	friend  class   PointSet;
	friend  class   Location;
	void    setX(float a){x=a;}
	void    setY(float a){y=a;}
	float   getX() {return x;}
    float   getY() {return y;}
    friend  ostream& operator<<(ostream&, const Point&);
};

Point::Point() {
	x=y=0.0;
	cout << "A Point object created (no parameters)\n";
//	printPoint();
}

Point::Point(float a) {
	x=a;y=a;
	cout << "A Point object created (one parameters)\n";
//	printPoint();
}

Point::Point(const Point& a) {
	x=a.x; y=a.y;
	cout <<"A Point object copied\n";
//	printPoint();

}

Point::Point(float a, float b) {
	x=a; y=b;
	cout << "A Point object created (2 parameters)\n";
//	printPoint();
}

Point::~Point() {
	cout << "A Point object destroyed\n";

}

// 1
Point Point::operator+(const Point &b) { // p.operator+(q)
   	cout<<"overloading + operator\n";

	Point temp;
	temp.x=x+b.x;
	temp.y=y+b.y;
	return temp;
}

// 2
Point Point::operator++() { // ++p --> p.operator++();
    cout<<"overloading pre-increment\n";

	++x;++y;
	return *this;
}

Point Point::operator++(int nothing) { // p++ --> p.operator++();
    cout<<"overloading post-increment\n";

    Point temp=*this;
	x++; y++;
	return temp;
}

// 3
void*	Point::operator new(size_t size) {
	void*	p;
	cout<<"overloading new operator" << "size= "<< size << "bytes \n";
	p=malloc(size);
	if(!p) {bad_alloc ba; throw ba;}
	return p;
}

void    Point::operator delete(void *p) {
    cout<<"overloading delete operator\n";
    free(p);
}

// 4 --> April 6
class Location {
private:
	Point loc;
public:
	const Point& getLoc() {return loc;}
	Point  *operator->() {
        cout<<"overloading -> operator\n";
        return &loc;}
	void printLocation() {loc.printPoint();}
};

// 5
class PointSet {
private:
	Point *p;
	int n;
public:
	PointSet(int,int);
	Point operator[](int i) {return p[i];}
};

PointSet::PointSet(int size, int a) {
	n=size; p=new Point[n];
	for(int i=0;i<n; i++) {p[i].setX((float)a); p[i].setY((float)a);}

//	for(int i=0;i<n;i++) p[i].printPoint();
}

// 6
ostream& operator<<(ostream& ostreamPoint, const Point& p) {
    ostreamPoint <<"("<<p.x<<","<<p.y<<")\n";
    return ostreamPoint;
}


int main() {

	Point   p(5.5,4.4);
	Point   q(1.1, 2.2);

//  1-- operator +
//    (p+q).printPoint(); // p.operator+(q);

//	2-- operator ++, ++ and operator-
//    cout << "post-increment" << endl;
//	(p++).printPoint();
//	p.printPoint();

//	cout << "pre-increment" << endl;
//	(++q).printPoint(); q.printPoint();

//	3-- operator new and delete
//	Point *r;
//	try { r=new Point(10.0, 20.0); }
//	catch (bad_alloc xa) {
//		cout<<"Allocation error"<<endl;
//		return 1;
//	}
//	delete r;

//	4-- operator ->
    Location    s;
	s->x=10.1; s->y=20.4;  // initially Location has no -> operator and s is not a pointer
    s.printLocation();


//	5-- operator[]
//	PointSet ps(10,0);
//	Point r=ps[5];
//	r.printPoint();
//	ps[7].setX(10.0); ps[7].setY(20.0);		// what's wrong??
//	ps[7].printPoint();

//  6
//    Point s(10.10, 20.20);
//    cout<<s;
	return 0;
}
