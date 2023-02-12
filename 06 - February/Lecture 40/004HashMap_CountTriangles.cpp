/*
	Given N cartesian points in a 2D plane, count the number of right-angled triangles that
	can be formed such that the base or perpendicular is parallel to the x-axis or y-axis.
	
	Examples
	
	Input : {(0, 0), 
	         (2, 0), 
	         (0, 1)}

	Output: 1
	
	Input : {(1, 2), 
			 (2, 0), 
			 (2, 2), 
			 (2, 3), 
			 (4, 2)}

	Output: 4
*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Point {
public:
	int x;
	int y;

	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

int main() {

	vector<Point> points = {Point(1, 2), 
							Point(2, 0), 
							Point(2, 2), 
							Point(2, 3), 
							Point(4, 2)};

	// time : O(n) space : O(n) when using xFreqMap and yFreqMap

	unordered_map<int, int> xFreqMap;
	unordered_map<int, int> yFreqMap;

	for(Point point : points) {
		xFreqMap[point.x]++;
		yFreqMap[point.y]++;
	}


	int count = 0;
	for(Point point : points)  {
		// consider the 'point' as pivot and compute the no. of
		// axis parallel rightAngledTriangles around it

		// int a = 0; // to store the no. of points in 2D plane that has same
		// 		   // x-coordinate as the given 'point'

		// int b = 0; // to store the no. of points in 2D plane that has same
		// 		   // y-coordinate as the given 'point'

		// for(Point p : points) {
		// 	if(p.x == point.x) {
		// 		a++;
		// 	} 

		// 	if(p.y == point.y) {
		// 		b++;
		// 	}
		// }

		int a = xFreqMap[point.x];
		int b = yFreqMap[point.y];

		count += (a-1)*(b-1);
	}

	cout << "count : " << count << endl;


	return 0;
}