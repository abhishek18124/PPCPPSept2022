/*
	Given N cartesian points in a 2D plane, count the number of axis parallel rectangles that
	can be formed. 
	
	Example
	
	Input : {(0, 0), (0, 1), (1, 1), (1, 0), (2, 1), (2, 0), (3, 1), (3, 0)}
	Output: 6

*/

#include<iostream>
#include<vector>
#include<set>

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

class PointCompare {
	public :

		bool operator()(Point p1, Point p2) const {
			if(p1.x == p2.x) {
				return p1.y < p2.y;
			}
			return p1.x < p2.x;
		}

};

int main() {

	vector<Point> points{Point(1, 1), 
						 Point(1, 2), 
						 Point(2, 1),
						 Point(2, 2), 
						 Point(3, 1), 
						 Point(3, 2)};

	// time : O(n^2logn) space : O(n)

	set<Point, PointCompare> s(points.begin(), points.end());

	int count = 0;
	for(int i=0; i<points.size()-1; i++) {
		Point p1 = points[i];
		for(int j=i+1; j<points.size(); j++) {
			Point p2 = points[j];
			if(p1.x != p2.x && p1.y != p2.y) {
				Point p3 = Point(p1.x, p2.y);
				Point p4 = Point(p2.x, p1.y);				
				// check whether points 'p3' and 'p4' are present in the 
				// 2D plane or not
				if(s.find(p3) != s.end() && s.find(p4) != s.end()) {
					count++;
				}
			}
		}
	}
	
	cout << "count : " << count/2 << endl;

	return 0;
}