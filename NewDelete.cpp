#include <iostream>
#include <string.h>
using namespace std;

// new 와 delete 를 이용해  malloc 과 free 함수 대신하기.

char *MakeStrAdr(int len) {
    // char *str = (char*)malloc(sizeof(char)*len);
    char *str = new char[len];
    return str;
}

int main() {
    char *str = MakeStrAdr(20);
    strcpy(str, "I am so happy~");
    cout << str << endl;
    // free(str);
    delete []str;
    return 0;
}