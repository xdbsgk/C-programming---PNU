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
};
