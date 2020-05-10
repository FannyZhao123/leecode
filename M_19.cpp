/*
19. Remove Nth Node From End of List
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:
Could you do this in one pass?
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
//Runtime: 4 ms, faster than 89.92% of C++ online submissions for Remove Nth Node From End of List.
//Memory Usage: 10.6 MB, less than 5.26% of C++ online submissions for Remove Nth Node From End of List.
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int s = 0;
        ListNode* temp = head;
        ListNode* temp2 = head;
        while(temp != nullptr){
            s++;
            temp = temp->next;
        }
        if ( s == n ) return head->next;
        while (s-n-1 > 0 ){
            temp2 = temp2->next;
            s--;
        }
        temp2->next = temp2->next->next;
        return head;
    }
};

//In one pass
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        ListNode* temp2 = head;
        while(n > 0){
            temp = temp->next;
            n--;
        }
        if (temp == nullptr) return head->next;
        while (temp->next != nullptr){
            temp2 = temp2->next;
            temp = temp->next;
        }
        temp2->next = temp2->next->next;
        return head;
    }
};
