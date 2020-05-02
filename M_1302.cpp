/*
1302. Deepest Leaves Sum

Given a binary tree, return the sum of values of its deepest leaves.

Example 1:
Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15

Constraints:

The number of nodes in the tree is between 1 and 10^4.
The value of nodes is between 1 and 100.
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
class Solution {
public:
    int sum = 0;
    int height(TreeNode* root)
    {
        if(!root)
            return 0;
        return max(height(root->left),height(root->right))+1;
    }
   
    void DFS (TreeNode* root, int height, int counter){
        if (root == nullptr) return;
        counter += 1;
        if (height == counter){
            sum += root->val;
            return;
        } 
        DFS(root->left, height, counter);
        DFS(root->right, height, counter);
    }
    int deepestLeavesSum(TreeNode* root) {
        int h = height(root);
        int counter = 0;
        DFS(root, h, counter);
        return sum;
    }
};