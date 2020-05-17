/*
98. Validate Binary Search Tree
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

    2
   / \
  1   3

Input: [2,1,3]
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
*/

//Runtime: 44 ms, faster than 6.40% of C++ online submissions for Validate Binary Search Tree.
//Memory Usage: 21.5 MB, less than 6.25% of C++ online submissions for Validate Binary Search Tree.
class Solution {
public:
    bool isBSTutil(TreeNode* root, long long  l, long long r){
        if(!root) return true;
        if(root->val >= r || root->val <= l) return false;
        return isBSTutil(root->left,l,root->val) && isBSTutil(root->right,root->val,r);
    }
    bool isValidBST(TreeNode* root) {
	  return isBSTutil(root,(long long)INT_MIN-1,(long long)INT_MAX+1);
        
    }
};

//faster solution inordr DFS
//Runtime: 16 ms, faster than 65.56% of C++ online submissions for Validate Binary Search Tree.
//Memory Usage: 21.7 MB, less than 5.21% of C++ online submissions for Validate Binary Search Tree.
class Solution {
public:
    long long prev=LLONG_MIN; // prev variable to store previous node's value in inorder
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        if(!isValidBST(root->left)) return false; // if left subtree isn't valid, return false   
        if(prev<root->val) prev=root->val; 
        else return false; // if root's value is smaller that prev value in inorder, return false;
        return isValidBST(root->right); // return true if right subtree is valid, false otherwise.
    }
};