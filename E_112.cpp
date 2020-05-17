/*
112. Path Sum
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*/
//fast
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        return root && (root->val == sum && !root->left && !root->right || hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val));
    }
};

//recursively -- slow
class Solution {
int flag = false;
    void hasPathSumUtil(TreeNode* root, int sum) {
        if (!root) return;
        
        if (!root->left && !root->right)
            if (sum == root->val)
                flag = true;
        
        hasPathSumUtil(root->left, sum-root->val);
        hasPathSumUtil(root->right, sum-root->val);
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        
        hasPathSumUtil(root, sum);
        return flag;
    }
};