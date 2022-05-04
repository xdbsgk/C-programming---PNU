#include <iostream>
#include <cstdlib>
using namespace std;

class myMatrix {
    unsigned int size;
    float **elements;
    public:
        myMatrix(unsigned int n) {   // size of the matrix is given. Use malloc for element memory allocation.
            size=n;
            elements=(float**)malloc(sizeof(float*)*n);
            for (int i=0; i<n; i++)
                elements[i]=(float*)malloc(4*n);
        } 
        myMatrix() {    // error when no size is given
            cout << "Error: Matrix의 Size가 주어지지 않았습니다.\n";
        }    
        ~myMatrix() {   // destructor – free all allocated memory
            free(elements);
            cout << "Matrix가 소멸되었습니다.\n";
        }   
        int setElement(int x, int y, float v) { // set A(x,y) as v -- added function, return 1 if OK and -1 if error
            if (0<=x && x<size && 0<=y && y<size) {
                elements[x][y]=v;
                return 1;
            } else return -1;
        }  
        myMatrix *matrixMultiplication(myMatrix *A, myMatrix *B) {
            for (int i=0; i<A->size; i++) {
                for (int j=0; j<A->size; j++) {
                    for (int k=0; k<A->size; k++)
                        elements[i][j] += A->elements[i][k] * B->elements[k][j];
                }
            } return this;
        }
        myMatrix *matrixSum(myMatrix *A, myMatrix *B) {
            for (int i=0; i<A->size; i++) {
                for (int j=0; j<A->size; j++)
                    elements[i][j] += A->elements[i][j] + B->elements[i][j];
            } return this;
        }
        float getElements(int x, int y) {
            return elements[x][y];
        }
};

int main() {
    
    myMatrix a(2);
    a.setElement(0, 0, 1);
    a.setElement(0, 1, 2);
    a.setElement(1, 0, 3);
    a.setElement(1, 1, 4);

    myMatrix b(2);
    b.setElement(0, 0, 1);
    b.setElement(0, 1, 2);
    b.setElement(1, 0, 3);
    b.setElement(1, 1, 4);

    myMatrix mul(2);
    mul.matrixMultiplication(&a, &b);
    for (int i=0; i<2; i++){
        for (int j=0; j<2; j++) {
            cout << mul.getElements(i, j) << " ";
        }
    }cout << endl;
    

    myMatrix sum(2);
    sum.matrixSum(&a, &b);
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            cout << sum.getElements(i, j) << " ";
        }
    } cout << endl;
    
    return 0;
}