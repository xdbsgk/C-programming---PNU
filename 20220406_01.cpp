#include <iostream>
#include <string>
using namespace std;

int main() {
  string s1(“abcd”);
  string s2=“bcde”;
  string *s3=new string(s1);
  string s4=s1+”, “+s2;
  string s5,s6,s7;
  getline(cin,s5) >> s6; // return type of getline is reference of the first parameter
  getline(cin,s7, ‘+’); // ‘+’ is used as a delimiter
  cout << s4.length();
  cout << s1[3] << s1.at(3);
  cout << s1.find(“cd”);
}