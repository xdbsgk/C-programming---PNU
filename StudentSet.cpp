#include	<iostream>
#include	<string>
#include	<set>
#include	<iterator>
#include	<ctime>

using namespace std;

typedef	string	Name;
typedef	int		ID;
typedef	int		IDX;

class Student {
	ID		id;
	Name	name;
	bool	isUsed;
public:
	Student() {}
	Student(ID i,Name n):id(i),name(n) {isUsed=false;}
	void	setID(ID i) {id=i;}
	void	setName(Name n) {name=n;}
	void	setIsUsed(bool u) {isUsed=u;}
	ID		getID() { return id;}
	Name	getName() { return name;}
	bool	getIsUsed() { return isUsed;}
	
	// a simple way to define STL set with user-defined class
	// instead of using compare function
	bool	operator<(const Student& stud) const { return (this->id<stud.id);	}
	friend ostream& operator<<(ostream&, const Student&);
};

ostream&	operator<<(ostream& os, Student& s) {
	os<<s.getID()<<" "<<s.getName() <<endl;
	return os;
}

class StudentSet {
	int			maxStudents;
	int			numStudents;
	Student*	students;
public:
	StudentSet() {}
	StudentSet(int	maxStud) {
		maxStudents=maxStud;
		numStudents=0;
		students=(Student*) new Student[maxStud];
		for(int i=0;i<maxStud;i++) students[i].setIsUsed(false);
	}
	~StudentSet() { delete[] students;}
	int			getMaxStudents() {return maxStudents;}
	int			getNumStudents() {return numStudents;}
	
	IDX			insertElement(Student*);
	Student*	operator[](ID);
	IDX			deleteElement(Name);
};

ostream&	operator<<(ostream& os, StudentSet& ss) {
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

Student*	StudentSet::operator[](IDX	idx){ 
	for(int i=0;i<maxStudents;i++) 
		if(students[i].getID()==idx && students[i].getIsUsed()==true) 
			return &students[i];
	return NULL;
}

IDX	StudentSet::deleteElement(Name keyName){
	Student* sp;
	for(int i=0;i<maxStudents;i++) {
		sp=&students[i];
		if(sp->getIsUsed()==true && sp->getName()==keyName) {
			sp->setIsUsed(false);
			--numStudents;
			return i;
		}		
	}
	return -1;
}

IDX	StudentSet::insertElement(Student* s) {
	for(int i=0;i<maxStudents;i++) {
		Student* sp;
		sp=&students[i];
		if(sp->getIsUsed()==false) {
			sp->setID(s->getID());
			sp->setName(s->getName());
			sp->setIsUsed(true);
			++numStudents;
			return i;
		}
	}
	return -1;
}

int	main() {

	int 		numTrials=100000;
	time_t		t1, t2;

	// test for my set class
	StudentSet	aSet(numTrials);
	Student*	aStud;

	t1=time(NULL);
	for(int i=0;i<numTrials;i++) {
		aStud=(Student*) new Student(i+100,"aaaa"); 
		aSet.insertElement(aStud);
	}
	t2=time(NULL);
	cout << "Elapsed time for inserting students with my set class = " << t2-t1 << endl;


	// searching 
	t1=time(NULL);
	for(int i=0;i<numTrials;i++) {
		aStud=aSet[i+100]; 
	}
	t2=time(NULL);
	cout << "Elapsed time for searching students with my set class = " << t2-t1 << endl;
	
	

	// test for StL set
	set<Student> 	bStud;
	Student*		sp;
	t1=time(NULL);
	for (int i=0; i<numTrials; i++) {
		sp=(Student*) new Student(i+100, "aaaa");
		bStud.insert(*sp);
	}
	t2=time(NULL);
	cout << "Elapsed time for inserting students with STL = " << t2-t1 << endl;

	return 0;
}

/*
 --------------------------------------------------------------------------------

						STL 사용하는 것이 실행 시간을 훨씬 줄일 수 있음.

 --------------------------------------------------------------------------------
 */