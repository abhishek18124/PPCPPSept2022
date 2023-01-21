#include<iostream>
#include<list>

using namespace std;

template <typename T>
class queue {
	list<T> dll;

public:

	void push(T data) {
		dll.push_back(data);
	}

	void pop() {
		if(empty()) {
			return;
		}
		dll.pop_front();
	}

	T front() {
		return dll.front();
	}

	int size() {
		return dll.size();
	}

	bool empty() {
		return dll.empty();		
	}

};

int main() {

	queue<int> q;

	cout << "size : " << q.size() << endl;
	cout << "empty : " << q.empty() << endl;

	q.push(10);
	q.push(20);
	q.push(30);

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;

	q.pop();

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;

	q.pop();

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;

	q.pop();
	q.empty() ? cout << "Queue is empty!" << endl:
	            cout << "Queue is not empty!" << endl;

	return 0;
}