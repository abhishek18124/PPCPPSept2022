#include<iostream>

using namespace std;

int main() {
  
	int arr[][4] = {{10, 20, 30, 40},
                    {50, 60, 70, 80},
                    {90, 100, 110, 120}};

    int m = 3;
    int n = 4;

    for(int i=0; i<m; i++) {
    	for(int  j=0; j<n; j++) {
    		cout << arr[i][j] << " ";
    	}
    	cout << endl;
    }

	return 0;
}