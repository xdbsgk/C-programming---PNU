#include <iostream>

using namespace std;

float sumNonRecursive(int N, float values[]) {
    int i;
    float res=0;
    for (i=0; i<N; i++)
        res = res + values[i];
    return res;
}

int main() {

    float val[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 

    float result = sumNonRecursive(3, val);

    cout << "결과: " << result << endl;

    return 0;
}