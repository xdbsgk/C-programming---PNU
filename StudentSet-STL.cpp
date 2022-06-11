#include	<iostream>
#include	<string>
#include	<set>
#include	<iterator>

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

ostream&	operator<<(ostream& os, const Student& s) {
	os<<s.id<<":"<<s.name <<endl;
	return os;
}

int	main() {

	set<Student> 	myStudents;
	string			names[5]={
		"abc","bcd","def","efg","abf"
	};
	
	for(int i=0;i<5;i++) {
		Student* sp=(Student*) new Student(i,names[i]);
		myStudents.insert(*sp);
	}

	set<Student>::iterator it;
	for(it=myStudents.begin();it!=myStudents.end();it++) {
		cout<<"student: "<<*it;
	}
	
	return 0;
}
