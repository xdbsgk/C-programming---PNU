#define PI 3.14159265
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

class Point{
private:
    float x,y;
public:
    Point() { }
    ~Point() { }
    Point(float a, float b): x(a), y(b) { }
    float getX() { return x; }
    float getY() { return y; }
    void setX(float a) { x = a; }
    void setY(float b) { y = b; }
};
ostream& operator<<(ostream& os, Point p){
    os << p.getX()<<" "<<p.getY();
    return os;
}

class Geometry {
    int id;
protected:
    char geomType;
public:
    void setId(int i){id = i;};
    int getId(){return id;};
    Geometry() {};
    virtual ~Geometry(){};
    virtual bool PointInGeometry(Point* p)=0;
    virtual float Area()=0;
    virtual void Print()=0;
};

class Circle : public Geometry {
private:
    Point center;
    float radius;
public:
    Circle() { };
    Circle(Point c, float r):center(c), radius(r) { };
    Point getCenter() {return center;}
    void setCenter(Point c){center = c;}
    float getRadius() {return radius;}
    void setRadius(float r){radius = r;}

    float Area() { return PI*radius*radius;}
    bool PointInGeometry(Point* p){
        float dist = sqrt(pow(p->getX() - center.getX(), 2) + pow(p->getY()-center.getY(), 2));
        if(dist<=radius)
        {
            return true;
        }
        return false;
    }
    void Print()
    {
        cout<<getId()<<" C "<<center<<" "<<radius<<endl;
        // cout<<*this;
    };
};

istream& operator>>(istream& ifs, Circle& c){
    float x, y, radius;
    ifs >> x >> y >> radius ;
    c.setCenter(Point(x,y));
    c.setRadius(radius);
    return ifs;
}

class Rectangle : public Geometry {
private:
    Point rightUpper;
    Point leftLower;
public:
    Rectangle(){};
    Rectangle(Point l, Point r): rightUpper(r), leftLower(l) {
        if(r.getX()<=l.getX()) cout<<"wrong X\n";
        if(r.getY()<=l.getY()) cout<<"wrong Y\n";
    };

    float Area();

    Point getRightUpper() {return rightUpper;};
    Point getLeftLower()  {return leftLower;};
    void setRightUpper(Point p){rightUpper = p;};
    void setLeftLower(Point p){leftLower = p;};

    bool PointInGeometry(Point* p){
        float x1,y1,x2,y2;
        x1 = leftLower.getX();     y1 = leftLower.getY();
        x2 = rightUpper.getX();    y2 = rightUpper.getY();
        if(((p->getX() >= x1) && (p->getX()<=x2)) && ((p->getY() >= y1) && (p->getY()<=y2)))
        {
            return true;
        }
        return false;
    }
    void Print()
    {
        cout<<getId()<<" R "<<leftLower<<" "<<rightUpper<<endl;
    };
};

float Rectangle::Area(){
    float x1,y1,x2,y2;
    x1 = leftLower.getX();     y1 = leftLower.getY();
    x2 = rightUpper.getX();    y2 = rightUpper.getY();
    return (x2-x1)*(y2-y1) ;
}

istream& operator>>(istream& ifile, Rectangle& r){
    float x1, y1, x2, y2;
    ifile >> x1 >> y1 >> x2 >> y2;
    r.setLeftLower(Point(x1,y1));
    r.setRightUpper(Point(x2,y2));
    return ifile;

}

class Triangle : public Geometry {
private:
    Point first;
    Point second;
    Point third;
public:
    Triangle() {};
    Triangle(Point a,Point b, Point c):first(a), second(b), third(c) { }
    Point getFirst() {return first;}
    Point getSecond() {return second;}
    Point getThird() {return third;}
    void setFirst(Point a){first = a;}
    void setSecond(Point b){second = b;}
    void setThird(Point c){third = c;}
    float Area() { return abs((first.getX()*second.getY()+second.getX()*third.getY()+
    third.getX()*first.getY() - first.getY()*second.getX()-second.getY()*third.getX()
                               -third.getY()*first.getX())/2);}
    
    float sign (Point p1, Point p2, Point p3)
    {
        return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
    }

    bool PointInGeometry(Point *p)
    {
        float d1, d2, d3;
        bool has_neg, has_pos;

        d1 = sign(*p, first, second);
        d2 = sign(*p, second, third);
        d3 = sign(*p, third, first);

        has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
        has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

        return !(has_neg && has_pos);
    };
    
    void Print(){
        cout<<getId()<<" T "<<first<<" "<<second<<" "<<third<<endl;
    };
};

istream& operator>>(istream& ifile, Triangle& t){
    float x1, y1, x2, y2, x3, y3;
    ifile >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    t.setFirst(Point(x1,y1));
    t.setSecond(Point(x2, y2));
    t.setThird(Point(x3, y3));
    return ifile;
}

class Square : public Geometry {
private:
    Point pnt;
    float side;
public:
    Square() {};
    Square(Point c, float s):pnt(c), side(s) {};
    Point getPnt() {return pnt;}
    void setPnt(Point c){pnt = c;}
    float getSide(){return side;}
    void setSide(float s){side = s;}
    float Area() { return side*side;}
    bool PointInGeometry(Point* p)
    {
        if((p->getX()>=pnt.getX() && (p->getX()<=(pnt.getX()+side))) && (p->getY()>=pnt.getY() && (p->getY()<=(pnt.getY()+side))))
            return true;
        return false;
    }
    void Print()
    {
        cout<<getId()<<" S "<<pnt<<" "<<side<<endl;
    };
};

istream& operator>>(istream& ifile, Square& s){
    float x, y, side;
    ifile >> x >> y >> side;
    s.setPnt(Point(x,y));
    s.setSide(side);
    return ifile;
}

template <class T>
class MySet {
private:
    int size;
    T** elements;
    int length;
public:
    MySet() {
        size = 1;
        length = 0;
        elements = new T*[size];
    };
    
	MySet(int s) {
        size = s;
    	length = 0;
        elements = new T*[size];
    }
    
	~MySet(){delete[] elements;};
    	
    T* operator[](Point *p) {
        for(int i = 0; i < length; i++) 
		    if(elements[i]->PointInGeometry(p)) return elements[i];
        return NULL;
    };
        
    void printElements() {
        for(int i=0; i<length;i++) elements[i]->Print();
    }
    
    void sortElements() {
        for(int i=0;i<length;i++) 
            for(int j=i+1;j<length;j++) 
                if(elements[i]->Area()>elements[j]->Area()) {
                    T* temp  =elements[i];
                    elements[i]=elements[j];
                    elements[j]=temp;
			    }
    }
    int Insert();
};

template <class T>
int	MySet<T>::Insert() {
    cin >> size;
    int id;
    char geomType;
    
    for(int i=0;i<size;i++){
        cin >> id >> geomType;
        switch(geomType){
            case 'C' :
            {
                Circle* c = new Circle;
                c->setId(id);
                cin>>*c;
                elements[length++] = c;
                break;
            }
            case 'T' :
            {
                Triangle* t = new Triangle;
                t->setId(id);
                cin>>*t;
                elements[length++] = t;
                break;
            }
            case 'R' :
            {
                Rectangle* r = new Rectangle;
                r->setId(id);
                cin>>*r;
                elements[length++] = r;
                break;
            }
            case 'S' :
            {
                Square* s = new Square;
                cin>>*s;
                        s->setId(id);
                        elements[length++] = s;
                        break;
            }
            default:
                return 0;
        }
    }
    sortElements();
    return size;
}

int main() {
	MySet<Geometry> A;
	A.Insert();
	
	for(int i=1; i<10; i++) {
		Point* p=new Point(0.1*i+0.01, 0.1*i+0.01);
		Geometry* geom=A[p];
		geom->Print();
		delete p;
	}
		
	return 0;
}