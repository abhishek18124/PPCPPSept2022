/*

	Implementation of HashMap/HashTable

*/

#include<iostream>

using namespace std;

class node {

	public :

		string K;
		int V;
		node* next;

		node(string K, int V) {
			this->K = V;
			this->V = V;
			this->next = NULL;
		}

};

class HashMap {
	int N; //  to store the hash table capacity
	int M; //  to store the hash table size
	double L; // to store the load factor threshold

	node** T; // to store the pointer to the  dynamic
	          // array that represents the hash table

	int hashFn(string K) {
		// transform K into a hash index
	}

	void transfer(node* head) {
		// 1. rehash (K, V) pairs present in the linkedList represented 
		//    by "head" pointer to the updated hashMap
		
		// 2. release memory allocated for the linkedList represented
		//    by "head" pointer
	}

	void rehash() {

		// 1. save pointer to the current hashMap and its capacity
		
		// 2. create a hashMap with double capacity

		// 3. transfer (K, V) pairs from old hashMap to the updated hashMap
		
		// 4. release the memory allocated to the old hashMap

	}

	public :

		HashMap(int N=7, double L=0.7) {
			this->N = N;
			this->M = 0;
			this->L = L;

			T = new node*[N];
			for(int i=0; i<N; i++) {
				T[i] = NULL:
			}
		}

		void insert(string K, int V) {

			// 1. transform the key into hash index using the hash function

			// 2. create a node with the given (K, V) pair and insert it at
			//    head of the linkedList stored at the hash index

			// 3. update the pointer to the head of the linkedList stored at 
			//    the hash index such that it holds the address of the newly
			//    created node

			// 4. rehash, if loadFactor exceeds the loadFactor Threshold

		}

		node* find(string K) {

			// 1. transform the key into hash index using the hash function

			// 2. search for the node with the given key in the  linkedList 
			//    stored at the hash index


		}

		void erase(string K) {

			// 1. transform the key into hash index using the hash function

			// 2. delete the node with the given key from the linkedList 
			//    stored at the hash index

		}

		void printLinkedList(node* head) {
			while(head) { // head != NULL
				cout << "(" << head->K << ", " << head->V << ") ";
				head = head->next;
			}
			cout << endl;
		}

		void printHashMap() {
			// iterate over buckets in the hashMap
			for(int i=0; i<N; i++) {
				// print the linkedList stored ith bucket of the hashMap
				cout << i << " : ";
				printLinkedList(T[i]);
			}
			cout << endl;
		}
};

int main() {
	
	HashMap<int, int> hashMap;

	return 0;	
}