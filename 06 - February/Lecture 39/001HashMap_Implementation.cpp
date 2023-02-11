/*

	Implementation of HashMap/HashTable

*/

#include<iostream>

using namespace std;

class ListNode {

	public :

		int K;
		int V;
		ListNode* next;

		ListNode(int K, int V) {
			this->K = K;
			this->V = V;
			this->next = NULL;
		}

};

class HashMap {
	int N; //  to store the hash table capacity
	int M; //  to store the hash table size
	double L; // to store the load factor threshold

	ListNode** T; // to store the pointer to the  dynamic
	          // array that represents the hash table

	int hashFn(int K) {
		// transform K into a hash index
		return K%N;
	}

	void transfer(ListNode* head) {
		// 1. rehash (K, V) pairs present in the linkedList represented 
		//    by "head" pointer to the updated hashMap
		ListNode* temp = head;
		while(temp != NULL) {
			insert(temp->K, temp->V);
			temp = temp->next;
		}
		
		// 2. release memory allocated for the linkedList represented
		//    by "head" pointer
		while(head != NULL) {
			temp = head;
			head = head->next;
			delete temp;
		}

	}

	void rehash() {

		// 1. save pointer to the current hashMap and its capacity
		ListNode** oldT = T;
		int oldN = N;
		
		// 2. create a hashMap with double capacity
		N *= 2;
		T = new ListNode*[N];
		for(int i=0; i<N; i++) {
			T[i] = NULL;
		}
		M = 0;

		// 3. transfer (K, V) pairs from old hashMap to the updated hashMap
		for(int i=0; i<oldN; i++) {
			// transfer the linkedList present at the ith index of the old hashMap
			transfer(oldT[i]);
		}
		
		// 4. release the memory allocated to the old hashMap
		delete [] oldT;

	}

	public :

		HashMap(int N=7, double L=0.7) {
			this->N = N;
			this->M = 0;
			this->L = L;

			T = new ListNode*[N];
			for(int i=0; i<N; i++) {
				T[i] = NULL;
			}
		}

		void insert(int K, int V) {

			// 1. transform the key into hash index using the hash function
			int hashIdx = hashFn(K);

			// 2. create a ListNode with the given (K, V) pair and insert it at
			//    head of the linkedList stored at the hash index
			ListNode* n = new ListNode(K, V);

			// 3. update the pointer to the head of the linkedList stored at 
			//    the hash index such that it holds the address of the newly
			//    created ListNode
			n->next = T[hashIdx];
			T[hashIdx] = n;

			M++;

			// 4. rehash, if loadFactor exceeds the loadFactor Threshold
			double LF = M*1.0/N;
			if(LF > L) {
				// rehashing ...
				cout << "rehashing...LF = " << LF << endl;
				rehash();
			}
		}

		ListNode* find(int K) {

			// 1. transform the key into hash index using the hash function
			int hashIdx = hashFn(K);

			// 2. search for the ListNode with the given key in the  linkedList 
			//    stored at the hash index
			ListNode* temp = T[hashIdx];
			while(temp != NULL) {
				if(temp->K == K) {
					break;
					// return temp;
				} 
				temp = temp->next;
			}

			return temp;

		}

		void erase(int K) {

			// 1. transform the key into hash index using the hash function
			int hashIdx = hashFn(K);

			// 2. delete the ListNode with the given key from the linkedList 
			//    stored at the hash index
			ListNode* temp = T[hashIdx];

			if(temp == NULL) {
				// K is not present in the hashTable
				return;
			}

			if(temp->K == K) {
				// delete the head node
				T[hashIdx] = temp->next;
				delete temp;
				M--;
			} else {
				ListNode* prev = NULL;
				while(temp != NULL) {
					if(temp->K == K) {
						// delete the temp node
						prev->next = temp->next;
						delete temp;
						M--;
						break;
					}
					prev = temp;
					temp = temp->next;
				}
			}

		}

		void printLinkedList(ListNode* head) {
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

		int& operator[](int K) {
			ListNode* temp = find(K);
			if(temp == NULL) {
				int garbage;
				insert(K, garbage);
				temp = find(K);
			}
			return temp->V;
		}
};

int main() {
	
	// HashMap hashMap(5);

	// hashMap.insert(0, 0);
	// hashMap.insert(1, 1);
	// hashMap.insert(2, 4);

	// hashMap.printHashMap();

	// hashMap.insert(12, 144);
	// hashMap.insert(6, 36);
	// hashMap.insert(7, 49);

	// hashMap.printHashMap();

	// int key = 6;
	// ListNode* temp = hashMap.find(key);
	// if(temp != NULL) {
	// 	cout << temp->V << endl;
	// } else {
	// 	cout << key << " is not found!" << endl;
	// }

	// hashMap.erase(6);

	// hashMap.printHashMap();

	// hashMap.erase(12);

	// hashMap.printHashMap();

	HashMap hashMap(5);

	hashMap.insert(0, 0);
	hashMap.insert(1, 1);
	hashMap.insert(7, 49);

	hashMap.printHashMap();

	hashMap.insert(3, 9);

	hashMap.printHashMap();

	cout << hashMap[3] << endl;
	cout << hashMap[12] << endl;

	hashMap[13] = 169;	

	// cout << hashMap[13] << endl;

	hashMap.printHashMap();

	hashMap[13] = 0;

	hashMap.printHashMap();

	// int x = hashMap[3] + 1;
	// cout << x << endl;

	return 0;	
}