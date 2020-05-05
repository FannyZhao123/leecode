/*
538. Convert BST to Greater Tree
Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

Example:

Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13

Output: The root of a Greater Tree like this:
             18
            /   \
          20     13
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
//Runtime: 36 ms, faster than 97.69% of C++ online submissions for Convert BST to Greater Tree.
//Memory Usage: 27.2 MB, less than 14.29% of C++ online submissions for Convert BST to Greater Tree.
class Solution {
public:
    void helper (TreeNode* root, int &pre_sum){
        if (!root) return;
        helper(root->right, pre_sum);
        pre_sum += root->val;
        root->val = pre_sum;
        helper(root->left, pre_sum);
    }
    TreeNode* convertBST(TreeNode* root) {
        int pre_sum = 0;
        helper(root, pre_sum);
        return root;
    }
};


class Solution {
public:
    int sum=0;
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL)return NULL;
        convertBST(root->right);
        sum+=root->val;root->val=sum;
        convertBST(root->left);
        return root;
    }
};