#include <iostream>
using namespace std;

class Point {
private:
    int xpos, ypos;
public:
    void Init(int x, int y){
        xpos = x;
        ypos = y;
    }
    void ShowPointInfo() const {
        cout << "[" << xpos << ", " << ypos << "]" << endl;
    }
};

int main() {
    return 0;
}