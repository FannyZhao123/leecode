/*
21. Merge Two Sorted Lists
Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.
Example:
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode header(INT_MIN);
        ListNode *res = &header;
        
        while ( l1 && l2){
            if (l1->val < l2->val){
                res->next = l1;
                l1 = l1->next;
            }
            else{
                res->next = l2;
                l2 = l2->next;
            }
            res = res->next;
        }
        
        if(l1 == NULL){
            res->next = l2;
        }
        else res->next = l1;
        return header.next;
    }
};