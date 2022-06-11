#include <iostream>
#include <set>
using namespace std;

int main() {

    set<int> mySet;
    set<int>::iterator it;

    for (int i=0; i<10; i++) {
        mySet.insert(i*10);
    } 

    for (it = mySet.begin(); it != mySet.end(); it++) {
        cout << *it << " ";
    } cout << endl;

    return 0;
}