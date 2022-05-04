#include <cmath>
#include <cstdio>
#include <cstring>
// 가급적 c++ 헤더를 기반으로 작성하는 것이 좋음.
// 헤더파일에서 .h --> 앞에 c 붙이기.
using namespace std;    // c 표준에 정의된 함수들이 이름공간 std안에 선언 되어있기 때문에, 이 문장 삽입되어야 한다.

int main() {
    char str1[] = "Result";
    char str2[30];

    strcpy(str2, str1);
    printf("%s: %f \n", str1, sin(0.14));
    printf("%s: %f \n", str2, abs(-1.25)); // abs: 절댓값 반환 함수

    return 0;
}