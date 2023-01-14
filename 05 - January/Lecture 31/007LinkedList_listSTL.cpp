/*

	List - STL implementation of doubly linked list	

	How to create a list ? 
		> use empty container constructor (default constructor)
		> use fill constructor
		> use range constructor
		> use copy constructor
		> use initialiser list (C++11)
	How to add elements to a list ?
	    > use list::push_front to add element at head (constant time operation)
	    > use list::push_back to add element at tail  (constant time operation)
	How to remove elements from a list ?
	    > use list::pop_front to remove element from the head (constant time operation)
	    > use list::pop_back to remove element from the tail (constant time operation)
	    > use list::clear to remove all the elements from a list
	How to check size of a list ?
	    > use list::size
	How to check if a list is empty ?
	    > use list::empty or check if list size is 0
	How to access element at the head node? 
	    > use list::front 
	How to access element at the tail node? 
	    > use list::back 
	How to iterate over elements in a list ?
	    > use an iterator

*/

#include<iostream>
#include<list>

using namespace std;

int main() {

	// create an empty list

	list<int> l1;

	cout << "size = " << l1.size() << endl;

	// insert data at the head 

	l1.push_front(30);
	l1.push_front(20);
	l1.push_front(10);

	// insert data at the tail 

	l1.push_back(40);
	l1.push_back(50);
	
	cout << "size = " << l1.size() << endl;

	// access the element at the head
	cout << "head = " << l1.front() << endl;

	// access the element at the tail
	cout << "tail = " << l1.back() << endl;

	// iterate over the list using iterator

	for(auto it = l1.begin(), end = l1.end(); it != end; it++) {
		cout << *it << " ";
	}

	cout << endl;

	// iterate over the list using for-each loop

	for(int x : l1) {
		cout << x << " ";
	}

	cout << endl;

	// remove data at the head 

	l1.pop_front();
	
	cout << "size = " << l1.size() << endl;

	// iterate over the foward_list using iterator

	for(auto it = l1.begin(), end = l1.end(); it != end; it++) {
		cout << *it << " ";
	}

	cout << endl;

	// remove data at the tail 

	l1.pop_back();
	
	cout << "size = " << l1.size() << endl;

	// iterate over the foward_list using iterator

	for(auto it = l1.begin(), end = l1.end(); it != end; it++) {
		cout << *it << " ";
	}

	cout << endl;

	// clear list
	
	l1.clear();
	cout << "size = " << l1.size() << endl;

	// check if list is empty
	cout << "is list empty ? " << l1.empty() << endl;

	// create a list using fill constructor

	list<int> l2(3, 100); // creates a list of size 3 all with values 100
	
	cout << "size = " << l2.size() << endl;

	// iterate over the list using iterator

	for(auto it = l2.begin(), end = l2.end(); it != end; it++) {
		cout << *it << " ";
	}

	cout << endl;

	list<int> l3(4); // creates a list of size 4

	cout << "size = " << l3.size() << endl;

	// iterate over the foward_list using iterator

	for(auto it = l3.begin(), end = l3.end(); it != end; it++) {
		cout << *it << " ";
	}

	cout << endl;

	// create a list using initializer list
	list<int> l4 = {1, 2, 3, 4, 5};
	cout << "size = " << l4.size() << endl;

	// iterate over the foward_list using iterator

	for(auto it = l4.begin(), end = l4.end(); it != end; it++) {
		cout << *it << " ";
	}

	cout << endl;

	return 0;
}