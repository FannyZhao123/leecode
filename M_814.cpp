/*
814. Binary Tree Pruning
We are given the head node root of a binary tree, where additionally every node's value is either a 0 or a 1.

Return the same tree where every subtree (of the given tree) not containing a 1 has been removed.

(Recall that the subtree of a node X is X, plus every node that is a descendant of X.)

Example 1:
Input: [1,null,0,0,1]
Output: [1,null,0,null,1]
 
Explanation: 
Only the red nodes satisfy the property "every subtree not containing a 1".
The diagram on the right represents the answer.

Example 2:
Input: [1,0,1,0,0,0,1]
Output: [1,null,1,null,1]

Example 3:
Input: [1,1,0,1,1,0,1,0]
Output: [1,1,0,1,1,null,1]

Note:
The binary tree will have at most 100 nodes.
The value of each node will only be 0 or 1.
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Pruning.
//Memory Usage: 7.9 MB, less than 100.00% of C++ online submissions for Binary Tree Pruning.
class Solution {
public:
    int cal(TreeNode* root){
        if(!root) return NULL;
        int ret=0;
        if(root->val) ret=1;
        
        int l=cal(root->left);
        int r=cal(root->right);
        
        ret=(l||ret||r);
        
        if(!l) root->left=NULL;
        if(!r) root->right=NULL;
        return ret;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        if(!root) return root;
        if(!cal(root)) return NULL;
        return root;
    }
};