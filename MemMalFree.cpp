#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

// 길이 정보를 인자로 받아, 해당 길이의 문자열 저장이 가능한 배열을 생성 -> 배열의 주소값 반환.
char *MakeStrAdr(int len)
{
    char *str = (char*)malloc(sizeof(char)*len); // 문자열 저장을 위한 배열을 힙 영역에 할당함.
    return str;
}

int main() {
    char *str = MakeStrAdr(20);
    strcpy(str, "I am so happy~");
    cout << str << endl;
    free(str);  // 힙에 할당된 메모리 공간을 소멸함.
    return 0;
}