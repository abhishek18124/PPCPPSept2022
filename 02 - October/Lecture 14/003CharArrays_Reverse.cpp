#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

void reverseString(char* str) { // char str[]
	int i = 0;
	int j = strlen(str)-1;
	while(i < j) {
		swap(str[i], str[j]);
		i++;
		j--;
	}
}


int main() {

	char str[] = "hello";

	cout << "Original string : " << str << endl;

	// reverseString(str);

	// strrev(str); // present in <cstring>

	reverse(str, str+strlen(str));

	cout << "Reversed  string after 1st reverse : " << str << endl; 


	return 0;
}