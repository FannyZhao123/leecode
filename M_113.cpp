/*
113. Path Sum II
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]
*/

//Runtime: 32 ms, faster than 11.85% of C++ online submissions for Path Sum II.
//Memory Usage: 39.6 MB, less than 5.26% of C++ online submissions for Path Sum II.
class Solution {
public:
    int target;
    vector<vector<int>> out;
    void dfs(TreeNode* node, vector<int> v, int sum)
    {
        if(node == NULL) return;
        v.push_back(node->val);
        sum += node->val;
        if(sum == target && node->left == NULL && node->right == NULL) out.push_back(v);
        dfs(node->left, v, sum);
        dfs(node->right, v, sum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        target = sum;
        vector<int> v;
        dfs(root, v, 0);
        return out;
    }
};

//better solution 

//Runtime: 28 ms, faster than 22.20% of C++ online submissions for Path Sum II.
//Memory Usage: 19.8 MB, less than 84.21% of C++ online submissions for Path Sum II.
class Solution {
public:
    void dfs (TreeNode* root, int sum, vector<vector<int>>& res, vector<int>& path){
        if (!root) return;
        if(sum-root->val == 0 && !root->left && !root->right){
            path.push_back(root->val);
            res.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(root->val);
        dfs(root->left, sum-root->val, res, path);
        dfs(root->right, sum-root->val, res, path);
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        dfs (root , sum, res, path);
        return res;
    }
};
