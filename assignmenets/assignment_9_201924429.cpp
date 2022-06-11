#include <iostream>
#include <fstream>
#include <cstring>
#include <map>

using namespace std;

typedef string Name;
typedef int ID;
typedef int IDX;

class Student {
private:
    ID id;
    Name name;
    bool isUsed;
public:
    Student() { }
    Student(ID i, Name n) : id(i), name(n) { isUsed = false; }
    void setID(ID i) { id = i; }
    void setName(Name n) { name = n; }
    void setIsUsed(bool u) { isUsed = u; }
    ID getID() { return id; }
    Name getName() { return name; }
    bool getIsUsed() { return isUsed; }
    bool operator<(const Student& stud) const { return (this->id < stud.id); }
    friend ostream& operator<<(ostream&, const Student&);
};

ostream& operator<<(ostream& os, Student& s) {
    os << s.getID() << " " << s.getName() << endl;
    return os;
}

class StudentSet {
private:
    int maxStudents;
    int numStudents;
    Student* students;
public:
    StudentSet() { }
    StudentSet(int maxStud) {
        maxStudents = maxStud;
        numStudents = 0;
        students = (Student*) new Student[maxStud];
        for (int i=0; i<maxStud; i++)
            students[i].setIsUsed(false);
    }
    ~StudentSet() { delete[] students; }
    int getMaxStudents() { return maxStudents; }
    int getNumStudents() { return numStudents; }

    IDX insertElement(Student*);
    Student* operator[](ID);
    IDX deleteElement(Name);
};

ostream& operator<<(ostream& os, StudentSet& ss) {
	int	maxStud;
	maxStud=ss.getMaxStudents();
	os<<"--begining of set"<<endl;
	for(int i=0;i<maxStud;i++) {
		Student* sp;
		if((sp=ss[i])!=NULL && sp->getIsUsed()==true) os<<*sp;
	}
	os<<"--end of set\n";
	return os;
}

Student* StudentSet::operator[](IDX	id){
    map<IDX, Student> stumap;
    Student stunone = Student(0, "NONE");
	for(int i=0;i<maxStudents;i++) stumap[students[i].getID()] = students[i];
    stumap[0] = stunone;
    if (stumap.find(id) != stumap.end()) return &stumap[id];
    else return &stumap[0];
}

IDX StudentSet::deleteElement(Name keyName) {
    Student* sp;
    for(int i=0; maxStudents; i++) {
        sp = &students[i];
        if (sp->getIsUsed() == true && sp->getName() == keyName) {
            sp->setIsUsed(false);
            --numStudents;
            return i;
        }
    }
    return -1;
}

IDX StudentSet::insertElement(Student* s) {
    for (int i=0; i<maxStudents; i++) {
        Student* sp;
        sp = &students[i];
        if (sp->getIsUsed()==false) {
            sp->setID(s->getID());
            sp->setName(s->getName());
            sp->setIsUsed(true);
            ++numStudents;
            return i;
        }
    }
    return -1;
}


int main() {
	Student* aStud;
	int	numStudents;
	ID	id;
	Name name;
	Name deleteNames[]={"aaa", "xxx", "ddd", "asf", "bbb", "sdf", "dfs", "wwe", "dif", "prd"};
	ID queries[]={25, 45, 87, 21, 97, 55, 44, 65, 15, 22};

	cin>>numStudents;
	StudentSet	aSet(numStudents);
	
	for(int i=0;i<numStudents;i++) {
		cin>>id>>name;
		aStud=(Student*)new Student(id,name);
		aSet.insertElement(aStud);
	}
	
	for(int i=0;i<10;i++) aSet.deleteElement(deleteNames[i]);

	for(int i=0;i<10;i++) cout<<*aSet[queries[i]];

	return 0;
}