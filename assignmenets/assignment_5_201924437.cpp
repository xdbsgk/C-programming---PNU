#include <iostream>
using namespace std;

class MySet{
private:
    int n;                          // 집합 원소의 총 길이
    int index=0;                    // 현재 집합의 길이
    int *elementSet;                // 집합을 담을 배열
public:
    MySet(int num) {                // constructor
        n = num;
        elementSet = new int[n];
    }
    ~MySet() {                      // destructor
        delete [] elementSet;
    }
    int insertElement(int element) { // return the number of elements in the set after the insertion, and -1 if something wrong
        if (index >= n) return -1;
        elementSet[index] = element;
        index++;                    // 원소 추가 해줬으니 index 값 수정
    }
    int isThere(int num) {          // check whether given value is in the set and return 1 if exists, otherwise return 0.
        for(int i=0; i<index; i++) {
            if (elementSet[i] == num) { cout << "있어요\n"; return 1;}
        } return 0;
    }
    int deleteElement(int num) {    // delete the given value from the set and return the number of elements after deletion and -1 if not exists.  
        for (int i=0; i<index; i++) {
            if (elementSet[i] == num) {
                for (int j=i; j<index; j++) {
                    elementSet[j] = elementSet[j+1];
                } index--;          // 원소 제거 해줬으니 index 값 수정
            }
        } return -1;
    }
    int numberElement() {           // return the number of elements (modified)
        return index;
    }
    void printElements() {          // print the number of elements on the first line and the elements on the following lines (five elements for each line)
    cout << "Number of elements: " << index << endl;
        for (int i=0; i<index; i++) {
            if (i % 5 == 0) cout << endl;
            cout << elementSet[i] << " ";
        } cout << endl;
    }
};