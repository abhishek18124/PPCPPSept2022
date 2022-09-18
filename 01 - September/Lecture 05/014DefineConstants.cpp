#include<iostream>

#define PI 3.14
#define PRINT cout << 
#define READ cin >>
#define SEMICOLON ;
#define F(n) for(int i=0; i<n; i++) {cout << i << " ";} cout << endl;

using namespace std;

int main() {
	
	int r SEMICOLON
	PRINT "enter the radius : " SEMICOLON
	READ r SEMICOLON

	PRINT 2*PI*r << endl SEMICOLON

	F(10)	

	return 0 SEMICOLON
}