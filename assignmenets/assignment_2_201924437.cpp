#include <iostream>
#include <string>
#include <cstring>
using namespace std;


char* StrangeMultiplication(char* s1, char* s2){
    cout << "입력: \n"<< s1 << " / " << s2 << "\n";
    
    //첫번째 문장 숫자화
    string v1("");

    for(int i = 0; i < (int)strlen(s1); i++){
        v1 += to_string((int)s1[i]-97);
    }
    
    //두번째 문장 숫자화
    string v2("");
    
    for(int i = 0; i < (int)strlen(s2); i++){
        v2 += to_string((int)s2[i]-97);
    }
    
    cout << "입력값 숫자화: \n"<< v1 << " / " << v2 << "\n";
    
    //두 수 곱하기
    string v3(to_string(stoi(v1) * stoi(v2)));
    
    cout << "두수의곱: \n"<<  v3 << "\n";
    
    

    char* result= new char[v3.length()]; 
   
    //곱한수 문자화
    for(int i = 0; i < v3.length(); i++){
        char aChar = (v3[i] - '0') + 97;
        result[i] = aChar;
    } 
    
    return result;
    
}

int main() {
    
    int num = 0;
    
    char* str1 = (char*)"gga";
    char* str2 = (char*)"bc";
    
    char* result = StrangeMultiplication(str1, str2);
    
    cout << "출력: \n" << result;
}