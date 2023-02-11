/*

What are unordered maps ? 

Unordered maps are associative containers that store elements formed by the combination of a 
key value and a mapped value, and which allows for fast retrieval of individual elements based 
on their keys. 

No two elements in the container can have equivalent keys.

What is the meaning of associative container ? 

Elements in associative containers are referenced by their key and not by their absolute 
position in the container.

How to create an unordered_map ? 
	> use empty container constructor (default constructor)
	> use initialiser list (C++11)
	> use copy constructor
	> use range constructor
How to insert (K, V) pair into an unordered_map ?
	> use unordered_map::insert (C++11)
    > use []
How to update a (K, V) pair in an unordered_map ?
    > use [] 
How to lookup/search for the value corresponding to a key in an unordered_map ? 
    > use unordered_map::find
    > use unordered_map::count
    > use []
How to delete a (K, V) pair from an unordered_map ?
	> use unordered_map::erase
	  > by key
	  > by position
	  > by range
    > use unordered_map::clear to remove all the elements from an unordered_map
How to check size of an unordered_map ?
	> use unordered_map::size to know number of (K, V) pairs present in an unordered_map
How to check number of buckets in an unordered_map ?
	> use unordered_map::bucket_count to know number of buckets present in an unordered_map
How to check if a unordered_map is empty ?
    > use unordered_map::empty or check if size of unordered_map is 0
How to iterate over elements in an unordered_map ?
    > use an iterator

*/

#include<iostream>
#include<unordered_map>

using namespace std;

int main() {

	// build an unordered_map using the default constructor
	
	unordered_map<string, string> capitalMap;
	
	// inserting into a map
	
	// using unordered_map::insert
	
	capitalMap.insert(make_pair("India", "New Delhi"));
	capitalMap.insert({"France", "Paris"});

	cout << "size : " << capitalMap.size() << endl;

	// using []

	capitalMap["Japan"] = "Tokyo";
	capitalMap["USA"] = "Washington";
	capitalMap["Russia"] = "Moscow";
	cout << "size : " << capitalMap.size() << endl;
 	
	// print map size using unordered_map::size
	
	// iterating over the map

	// using an iterator
	
	for(auto it=capitalMap.begin(), end=capitalMap.end(); it != end; it++) {
		// pair<string, string> p = *it;
		// cout << "(" << p.first << ", " << p.second << ")" << endl;
		cout << "(" << it->first << ", " << it->second << ")" << endl;
	}

	cout << endl;
	
	// using for-each loop
	
	for(pair<string, string> p : capitalMap) {
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}

	cout << endl;

	// using an iterator to iterate over buckets
	
	for(int i=0; i<capitalMap.bucket_count(); i++) {
		cout << i << " : ";
		for(auto it=capitalMap.begin(i), end=capitalMap.end(i); it != end; it++) {
			cout << "(" << it->first << ", " << it->second << ") ";
		}
		cout << endl;
	}

	cout << endl;

	// updating a value corresponding to a key in a map using []
	
	capitalMap["India"] = "NewDelhi";
	for(int i=0; i<capitalMap.bucket_count(); i++) {
		cout << i << " : ";
		for(auto it=capitalMap.begin(i), end=capitalMap.end(i); it != end; it++) {
			cout << "(" << it->first << ", " << it->second << ") ";
		}
		cout << endl;
	}

	cout << endl;

	// lookups

	// using unordered_map::find
	
	string key = "France";
	if(capitalMap.find(key) != capitalMap.end()) {
		cout << "(" << key << ", " << capitalMap[key] << ")" << endl;
	} else {
		cout << key << " is not found!" << endl;
	}

	// using unordered_map::count
	if(capitalMap.count(key)) {
		cout << "(" << key << ", " << capitalMap[key] << ")" << endl;
	} else {
		cout << key << " is not found!" << endl;
	}
	
	// deletion using unordered_map::erase

	// by key
	
	capitalMap.erase("France");
	cout << "size : " << capitalMap.size() << endl;
	if(capitalMap.find(key) != capitalMap.end()) {
		cout << "(" << key << ", " << capitalMap[key] << ")" << endl;
	} else {
		cout << key << " is not found!" << endl;
	}

	// clear using unordered_map::clear
	
	capitalMap.clear();
	cout << "size : " << capitalMap.size() << endl;

	// build an unordered_map using the initialiser list

	unordered_map<int, int> squareMap = {
											{1, 1},
											{2, 4},
											{3, 9},
											make_pair(4, 16),
											make_pair(5, 25)
										};

	cout << "size : " << squareMap.size() << endl;

	for(auto p : squareMap) {
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}

	return 0;
}