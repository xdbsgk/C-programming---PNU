#include <iostream>

int main() {

    int val1;
    std::cout << "첫 번째 숫자 입력: ";
    std::cin >> val1;

    int val2;
    std::cout << "두 번째 숫자 입력: ";
    std::cin >> val2;

    int result = val1 + val2;
    std::cout << "덧셈 결과: " << result << std::endl;

//    char str[100];
//    std::cin>>str;

    return 0;
    
}