/*

    Given k sorted linked list, merge them and print the sorted output.

    k = 3
    Input : 1->3->5
            2->4->6 
            0->8->7
        
    Output: 0->1->2->3->4->5->6->7->8

*/

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class ListNode {

    public :
        
        int val;
        ListNode* next;

        ListNode(int val) {
            this->val = val;
            this->next = NULL;
        }
};

void insertAtHead(ListNode*& head, int val) {
    
    ListNode* n = new ListNode(val);
    n->next = head;
    head = n;

}

void printLinkedList(ListNode* head) {

    while(head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    
    cout << endl;

}

class nodeComparator {
        
    public :

    /*
        return true when swap is needed else return false
        assume 'b' is the child of 'a'
    */

    bool operator()(ListNode* a, ListNode* b) {

        if(b->val < a->val) {
            // for a minHeap, you need a swap
            return true;
        } else {
            // for a minHeap, you don't need a swap
            return false;
        }
    }

};

ListNode* merge(vector<ListNode*> v) {

    priority_queue<ListNode*, vector<ListNode*>, nodeComparator> minHeap;

    for(ListNode* head : v) {
        if(head != NULL) {
            minHeap.push(head);
        }
    }

    ListNode* dummy = new ListNode(0);
    ListNode* temp  = dummy;

    while(!minHeap.empty()) {
        ListNode* minNode = minHeap.top();
        minHeap.pop();
        temp->next = minNode;
        temp = temp->next;
        if(minNode->next != NULL) {
            minHeap.push(minNode->next);
        } 
    }

    return dummy->next;

}

int main() {

    ListNode* head1 = NULL; 

    insertAtHead(head1, 7);
    insertAtHead(head1, 4);
    insertAtHead(head1, 1);

    printLinkedList(head1);

    ListNode* head2 = NULL; 

    insertAtHead(head2, 8);
    insertAtHead(head2, 5);
    insertAtHead(head2, 2);

    printLinkedList(head2);

    ListNode* head3 = NULL; 

    // insertAtHead(head3, 9);
    // insertAtHead(head3, 6);
    // insertAtHead(head3, 3);

    // printLinkedList(head3);

    vector<ListNode*> v = {head1, head2, head3};

    ListNode* head = merge(v);

    printLinkedList(head);

    return 0;
}
