#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;

class MySet{
private:
    int n; 
    int index=0;                         
    float *elements;                  
public:
    MySet() {
        n = 10;
        elements = new float[n];
    }
    MySet(int num) {
        n = num;
        elements = new float[n];
    }
    MySet(const MySet& set) {
        n = set.n;
        index =  set.index;
        elements = set.elements;
    }
    ~MySet() {
        delete[] elements;
    }
    MySet operator+(const MySet& set) const {
        MySet newSet(n);
        int i, j;
        for (i=0; i<n; i++) 
            newSet.add(elements[i]);
        for (i=0; i<n; i++) {
            for (j=0; j<n; j++){
                if (elements[j] == set.elements[i]) break;
            }
            if (j == n-1)
                newSet.add(set.elements[i]);
        }
        return newSet;
    }
    MySet operator+(float x) const {
		    MySet newSet(n);

			for (int i = 0; i < n; i++) {
                float y = elements[i] + x;
                newSet.add(y);
			} return newSet;
	}
    MySet operator*(const MySet& set) const {
        MySet newSet(n);
        int i,j;
        for (i=0; i<n; i++) {
            for (j=0; j<n; j++) {
                if (elements[j] == set.elements[i])
                    newSet.add(set.elements[i]);
            }
        } return newSet;
    }
    MySet operator-(const MySet& set) const {
        MySet newSet(n);
        int i,j;
        for (i=0; i<n; i++) {
            for (j=0; j<n; j++) {
                if (elements[i] == set.elements[j]) break;
            }
            if (j == n-1)
                newSet.add(elements[i]);
        } 
        return newSet;
    }
    int operator[](float element) {
        int status=1;
        for (int i=0; i<n; i++) {
            if (elements[i] > element) status++;
        } 
        return status;
    }
    int add(float element) {
        elements[index] = element;
        index++;
        return index;
    }
    friend ostream& operator<<(ostream& os, MySet set);
};

ostream& operator<<(ostream& os, MySet set) {
    for (int i = 0; i < set.n; i++) {
		for (int j = 0; j < set.n - 1; j++) {
			if (set.elements[j] > set.elements[j + 1]) {
				float x = set.elements[j + 1];
                set.elements[j + 1] = set.elements[j];
                set.elements[j] = x;
			}
		}
	}
    os << "{";
    for (int i=0; i<set.n; i++) {
        os << set.elements[i];
        if(set.n>1 && i<set.n-1)
            os << ",";
    }
    os << "}\n";
    return os;
}

int inputSet(MySet& set){

    string numLines;
    string bufFloat;

    for (int i = 0; i < 1; i++) 
        getline(cin, numLines);
    for(int i = 1; i < stod(numLines) + 1; i++) {
        getline(cin, bufFloat);
        set.add(stod(bufFloat));
    }
    return 1;
}

int inputSet(string name, MySet& set) {
    string numLines;
    string bufFloat;
    ifstream file(name);

    if(file.is_open()) {
        getline(file, numLines);
        while(getline(file, bufFloat)) {
            set.add(stod(bufFloat));
        }
        file.close();
    }
    return 1;
}

int main() {

    MySet A, B, C, D;

    if(inputSet(A) < 0)
    {
        cerr << "Input  Error" <<endl;
        return -1;
    }

    B = A;
    for(int i = 1; i <= 10; i++)  B = B + 0.1 * i;

    C = A * B;
    D = B - C;

    cout << std::fixed << std::setprecision(1);
    cout << D;
    cout << B[50.5] << endl;

    return 0;
}