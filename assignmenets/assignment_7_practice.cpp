#include <stdio.h>
#include <fstream>

using namespace std;


#define PI				3.14159265

class Point{
private:
	float x,y;
public:
	Point() {}
	Point(float a, float b): x(a), y(b) {}
	float getX() { return x;}
	float getY() { return y;}
	void setX(float a) {x = a;}
	void setY(float b) {y = b;}
};

ostream& operator<<(ostream& os, Point p){
	os <<"("<< p.getX()<<", "<<p.getY()<<")";
	return os;
}

class Geom {
protected:
	char	geomType;
public:
    Geom() { cout<<"A geometry is created"<<endl; };
	virtual float Area()=0;
};

class Circle : public Geom {
private:
	Point center;
	float radius;
public:
	Circle() { cout<<"A circle is created"<<endl;};
	Circle(Point c, float r):center(c), radius(r) { cout<<"A circle is created with radius and center point"<<endl; }
	Point getCenter() {return center;}
	void setCenter(Point c){center = c;}
	float getRadius() {return radius;}
	void setRadius(float r){radius = r;}

	float Area() { return PI*radius*radius;}
};

ostream& operator<<(ostream& os, Circle& c) {
	Point a=c.getCenter();
    os<< "Circle: radius="<<c.getRadius() <<", center=" <<a<<endl;
    return os;
}

ifstream& operator>>(ifstream& ifs, Circle& c){
	float x, y, radius;
	ifs >> x >> y >> radius ;
	c.setCenter(Point(x,y));
	c.setRadius(radius);
	return ifs;
}

class Rectangle : public Geom {
private:
	Point rightUpper;
	Point leftLower;
public:
	Rectangle(){ cout<<"A rectangle is created"<<endl;};
	Rectangle(Point r, Point l): rightUpper(r), leftLower(l) {
		if(r.getX()<=l.getX()) cout<<"wrong corner data X\n";
		if(r.getY()<=l.getY()) cout<<"wrong corner data Y\n";
		cout<<"A rectangle is created with two points"<<endl;
	};

	float Area();

	Point getRightUpper() {return rightUpper;};
	Point getLeftLower()  {return leftLower;};
	void setRightUpper(Point p){rightUpper = p;};
	void setLeftLower(Point p){leftLower = p;};
};

float Rectangle::Area(){
	float x1,y1,x2,y2;
	x1 = leftLower.getX(); 	y1 = leftLower.getY();
	x2 = rightUpper.getX();	y2 = rightUpper.getY();
	return (float)(x2-x1)*(y2-y1) ;
}

ostream& operator<<(ostream& os, Rectangle& r) {
	Point p1,p2;
	p1=r.getLeftLower(); p2=r.getRightUpper();
    os<< "Rectangle: "<< p1 <<", "<< p2 <<endl;
    return os;
}

ifstream& operator>>(ifstream& ifile, Rectangle& r){
	float x1, y1, x2, y2;
	ifile >>x1>>y1>>x2>>y2;
	r.setLeftLower(Point(x1,y1));
	r.setRightUpper(Point(x2,y2));
	return ifile;
}

int main(){

    GeomSet A;
	A.Insert();
	
	for(int i=1; i<10; i++) {
		Point* p=new Point(0.1*i+0.01, 0.1*i+0.01);
		Geometry* geom=A[p];
		geom->Print();
		delete p;
	}

	return 0;
}