/*
1290. Convert Binary Number in a Linked List to Integer
Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

 

Example 1:

Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10
Example 2:

Input: head = [0]
Output: 0
Example 3:

Input: head = [1]
Output: 1
Example 4:

Input: head = [1,0,0,1,0,0,1,1,1,0,0,0,0,0,0]
Output: 18880
Example 5:

Input: head = [0,0]
Output: 0
 

Constraints:

The Linked List is not empty.
Number of nodes will not exceed 30.
Each node's value is either 0 or 1.
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

//Runtime: 4 ms, faster than 7.97% of C++ online submissions for Convert Binary Number in a Linked List to Integer.
//Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Convert Binary Number in a Linked List to Integer.
class Solution {
public:
    int count_len (ListNode* head){
        int l = 1;
        if (head->next == nullptr){
            return l;
        }
        else {
            l += count_len (head -> next);
        }
        return l;
    }
    int getDecimalValue(ListNode* head) {
        int l = count_len (head);
        int i = 0;
        for (int a = l-1; a >= 0; a--){
            i += (head->val * pow(2, a));
            head = head->next;
        }
        return i;
    }
};


// easer way, same running time

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* CurrNode = head;
        int res = 0;
        
        while(CurrNode != NULL){
            int BinaryDigit = CurrNode->val;
            res = 2*res + BinaryDigit;
            cout << " res = " << res << endl;
            CurrNode = CurrNode->next;
        }
        
        return res;
        
    }
};

/*
example : 18880
[1,0,0,1,0,0,1,1,1,0,0,0,0,0,0]
 res = 1
 res = 2
 res = 4
 res = 9
 res = 18
 res = 36
 res = 73
 res = 147
 res = 295
 res = 590
 res = 1180
 res = 2360
 res = 4720
 res = 9440
 res = 18880
*/