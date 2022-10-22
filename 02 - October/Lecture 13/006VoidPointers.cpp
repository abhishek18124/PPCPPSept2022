#include<iostream>

using namespace std;

void increment(void* pvoid, int size) {
  if(size == sizeof(int)) {
    // pvoid points to an integer
    int* pint = (int*)pvoid;
    (*pint)++; // precedence(*) < precedence(++)
  } else if(size == sizeof(char)) {
    // pvoid points to a character
    char* pchar = (char*)pvoid;
    (*pchar)++;
  }
 }

int main() {
  
  int  x = 0;
  char y = 'a';
 
  increment(&x, sizeof(x));
  increment(&y, sizeof(y));
  
  cout << x << '\n' << y << endl;

  return 0;
}