#include <iostream>

namespace BestComImpl {
    void SimpleFunc();
}

namespace BestComImpl {
    void PrettyFunc();
}

namespace ProgComImpl {
    void SimpleFunc();
}

int main() {
    BestComImpl::SimpleFunc();

    return 0;
}

void BestComImpl::SimpleFunc() {
    std::cout << "BestCom이 정의한 함수" << std::endl;
    PrettyFunc();
    ProgComImpl::SimpleFunc();
}

void BestComImpl::PrettyFunc() {
    std::cout << "So Pretty!" << std::endl;
}

void ProgComImpl::SimpleFunc() {
    std::cout << "ProgCom이 정의한 함수" << std::endl;
}