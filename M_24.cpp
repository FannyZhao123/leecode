/*
24. Swap Nodes in Pairs
Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.

 
Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void printt (ListNode* head){
        while (head->next != NULL){
            cout << head->val << ", ";
            head = head->next;
        }
        cout << head->val << endl;
    }
    
    ListNode* swapPairs(ListNode* head) {
        ListNode* root = head;
        ListNode* nextN = NULL;
        ListNode* prev = NULL;
        
        while (root != NULL && root->next != NULL) {
            nextN = root->next;
            cout << "nextN1: " << endl;
            printt(nextN);
            cout << "head1: " << endl;
            printt(head);
            
            root->next = nextN->next;
            cout << "root2: " << endl;
            printt(root);
            cout << "head2: " << endl;
            printt(head);
            
            nextN->next = root; 
            cout << "nextN3: " << endl;
            printt(nextN);
            cout << "head3: " << endl;
            printt(head);
            
            if (prev != NULL) {
                prev->next = nextN;
                cout << "nextN4: " << endl;
                printt(nextN);
                cout << "prev4: " << endl;
                printt(prev);
                cout << "head4: " << endl;
                printt(head);
            } else {
                head = nextN;
                cout << "nextN5: " << endl;
                printt(nextN);
                cout << "head5: " << endl;
                printt(head);
            }
            
            prev = root;
            cout << "nextN6: " << endl;
            printt(nextN);
            cout << "prev6: " << endl;
            printt(prev);
            cout << "head6: " << endl;
            printt(head);
        
            if (root->next != NULL) root = root->next;            
        }
        
        return head;
    }
};

/*
nextN1: 
2, 3, 4
head1: 
1, 2, 3, 4
root2: 
1, 3, 4
head2: 
1, 3, 4
nextN3: 
2, 1, 3, 4
head3: 
1, 3, 4
nextN5: 
2, 1, 3, 4
head5: 
2, 1, 3, 4
nextN6: 
2, 1, 3, 4
prev6: 
1, 3, 4
head6: 
2, 1, 3, 4
nextN1: 
4
head1: 
2, 1, 3, 4
root2: 
3
head2: 
2, 1, 3
nextN3: 
4, 3
head3: 
2, 1, 3
nextN4: 
4, 3
prev4: 
1, 4, 3
head4: 
2, 1, 4, 3
nextN6: 
4, 3
prev6: 
3
head6: 
2, 1, 4, 3
*/