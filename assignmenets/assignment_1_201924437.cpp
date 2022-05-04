#include <iostream>
using namespace std;

float sumRecursive(int N, float *value) {               // N 번째 -> N-1 번째 -> N-2 번째 -> ... -> 첫 번째 요소의 순서로(거꾸로) 합해야 함.
    if(N < 0)                                           // 첫 번째 요소까지 더했는지 확인하기
        return 0;
    else                                        
        return value[N-1] + sumRecursive(N-1, value);   // 더할 요소가 있을 경우 해당 요소 값 + 그 앞의 요소 다시 돌려 구하기
}

int main() {
    
    // 임의의 배열로 코드 동작 확인해보기
    float value[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9}; 
    cout << "결과: " << sumRecursive(4, value) << endl;

    return 0;
}
