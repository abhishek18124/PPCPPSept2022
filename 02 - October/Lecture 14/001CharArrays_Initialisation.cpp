#include<iostream>

using namespace std;

int main() {

	char str[6] = {'a', 'b', 'c', 'd', 'e', '\0'};

	cout << str << endl;

	char str2[] = "hello"; // '\0' is added automatically

	cout << str2 << endl;

	return 0;

}