#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

typedef struct {
  int size;
  int **element;
} MyMatrix;


MyMatrix* DPMatrixMultiply(MyMatrix A, MyMatrix B) {
    int n = 0;
    n = A.size;
    MyMatrix* Res = (MyMatrix*)malloc(sizeof(MyMatrix));
    (*Res).size = n;
    (*Res).element = (int**)malloc(sizeof(int*)*n);
    for (int i=0; i<n; i++)    *((*Res).element+i) = (int*)malloc(4*A.size);

    // 매트릭스 곱
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            *(*((*Res).element+i)+j) = 0;
            for (int k=0; k<n; k++)
                *(*((*Res).element+i)+j) = *(*((*Res).element+i)+j) + (*(*(A.element+i)+k)) * (*(*(B.element+k)+j));
        }
    }

    return Res;
}


int main() {

    int n = 0;

    MyMatrix A;
    MyMatrix B;

    cout << "몇 개의 열/행을 입력하시겠습니까?(정방행렬만 가능)" << endl;
    cin >> n;

    A.size = n;
    B.size = n;

    A.element = (int**)malloc(sizeof(int*)*n);
    B.element = (int**)malloc(sizeof(int*)*n);

    for (int i=0; i<n; i++)  *(A.element+i) = (int*)malloc(4*n);
    for (int i=0; i<n; i++)  *(B.element+i) = (int*)malloc(4*n);

    cout << "첫 번째 매트릭스 입력" << endl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d",(*(A.element+i)+j));
        }
    }

    cout << "두 번째 매트릭스 입력" << endl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d",(*(B.element+i)+j));
        }
    }


    MyMatrix* Res = DPMatrixMultiply(A, B);

    cout << "두 매트릭스를 곱한 결과는 아래와 같습니다." << endl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++)
            cout << *(*((*Res).element+i)+j) << " ";
        cout << endl;
    }



    return 0;
}