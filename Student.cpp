#include <iostream>
#include <cstring>
using namespace std;

typedef string  Name;
typedef int     ID;
typedef int     IDX;
typedef int     RowNumber;

class Student {
private:
    Name    name;
    ID      id;
    bool    isUsed;
public:
    Student() { }
    Student(ID i, Name n) : id(i), name(n) { }
    ~Student() { }
    void    SetID(ID i) { id = i; }
    void    SetName(Name n) { name = n; }
    void    SetIsUsed(bool u) { isUsed = u; }
    ID      GetID() { return id; }
    Name    GetName() { return name; }
    bool    GetIsUsed() { return isUsed; }
};

// 매개변수가 무거워지니까 참조자로 매개변수 선언 !
ostream& operator<<(ostream& os, Student& s) {
    os << s.GetID() << "    " << s.GetName() << endl;
}


class StudentSet {
private:
    int         maxStudents;
    int         numStudent;
    Student*    students;
public:
    StudentSet() { }
    StudentSet(int maxStu) : maxStudents(maxStu) {
        numStudent = 0;     // 현재까지 들어간 학생의 수
        students = (Student*)new(maxStu);
        for(int i=0; i<maxStu; i++) { students[i].SetIsUsed(false); }
    }
    ~StudentSet() { delete[] students; }
    void        insert(Student*);
    Student*    operator[](ID);
    Student*    operator[](Name);
    RowNumber   operator[](ID);
    RowNumber   deleteElement(Name);
    RowNumber   deleteElement(ID);
    RowNumber   deleteElement(IDX);
};
StudentSet* StudentSet::operator[](ID keyID) {
    Student* sp;
    for (int i=0; i<maxStudents; i++) {
        sp = &students[i];
        if (sp->GetIsUsed()==true && sp->GetID()==keyID) return sp;
    }
    return NULL;
}
RowNumber StudentSet::operator[](ID keyID) {
    Student* sp;
    for (int i=0; i<maxStudents; i++) {
        sp = &students[i];
        if (sp->GetIsUsed()==true && sp->GetID()==keyID) return i;
    }
    return -1;
}

RowNumber StudentSet::deleteElement(Name keyName) {
    Student* sp;
    for (int i=0; i<maxStudents; i++) {
        sp = &students[i];
        if (sp->GetIsUsed()==true && sp->GetName()==keyName ) {
            sp->SetIsUsed(false);
            return i;
        }
    }
    return -1;
}

RowNumber StudentSet::deleteElement(ID keyID) {
    Student* sp;
    for (int i=0; i<maxStudents; i++) {
        sp = &students[i];
        if (sp->GetIsUsed()==true && sp->GetID==keyID ) {
            sp->SetIsUsed(false);
            return i;
        }
    }
    return -1;
}
RowNumber StudentSet::deleteElement(IDX keyIDX) {

}

// isUsed가 false인 것 찾아서 insert 해주기.
IDX     StudentSet::insert(Student* s) {
    for(int i=0; i<maxStudents; i++) {
        Student* sp;
        sp = &students[i]
        if (sp -> GetIsUsed() == false) {
            sp -> SetIsUsed(true);
            sp -> SetID(s -> GetID());
            sp -> SetName(s -> GetName());
            return i;
        }
    }
    return -1;
}