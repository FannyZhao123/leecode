/*
1038. Binary Search Tree to Greater Sum Tree

Given the root of a binary search tree with distinct values, modify it so that every node has a new value equal to the sum of the values of the original tree that are greater than or equal to node.val.

As a reminder, a binary search tree is a tree that satisfies these constraints:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:
Input: [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
 

Constraints:
The number of nodes in the tree is between 1 and 100.
Each node will have value between 0 and 100.
The given tree is a binary search tree.
Note: This question is the same as 538: https://leetcode.com/problems/convert-bst-to-greater-tree/
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
//Runtime: 4 ms, faster than 46.82% of C++ online submissions for Binary Search Tree to Greater Sum Tree.
//Memory Usage: 7.5 MB, less than 100.00% of C++ online submissions for Binary Search Tree to Greater Sum Tree.
class Solution {
public:
    void bstToGstUtil(TreeNode* root, int &ans){
        if(!root) return;
        
        bstToGstUtil(root->right, ans);
        ans += root->val;
        root->val = ans;
        bstToGstUtil(root->left, ans);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        int ans = 0;
        bstToGstUtil(root, ans);
        return root;
    }
};


//best solution
//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Search Tree to Greater Sum Tree.
//Memory Usage: 7.9 MB, less than 100.00% of C++ online submissions for Binary Search Tree to Greater Sum Tree.
class Solution {
public:
    vector<int>v;
    void order(TreeNode* root)
    {
        if(root == NULL) return;
        order(root->right);
        v.push_back(v.back()+root->val);
        order(root->left);
    }
    TreeNode* change(TreeNode* root)
    {
        if(root == NULL)return NULL;
        change(root->right);
        root->val=v.back();
        v.pop_back();
        change(root->left);
        return root;
    }
    TreeNode* bstToGst(TreeNode* root) {
        v.clear();
        v.push_back(0);
        order(root);
        v.erase(v.begin(),v.begin()+1);
        reverse(v.begin(),v.end());
        return change(root);
    }
};

//mine, after correction 
//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Search Tree to Greater Sum Tree.
//Memory Usage: 7.4 MB, less than 100.00% of C++ online submissions for Binary Search Tree to Greater Sum Tree.
class Solution {
public:
	/*
    int sumTree (TreeNode* root){
        int sum = 0;
        if (!root) return sum;
        sum += root->val;
        sum += sumTree(root->right);
        sum += sumTree(root->left);
        return sum;
    }
    */
    void helper (TreeNode* root, int &pre_sum){
        if (!root) return;
        helper(root->right, pre_sum);
        pre_sum += root->val;
        root->val = pre_sum;
        helper(root->left, pre_sum);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        int pre_sum = 0;
        helper(root, pre_sum);
        return root;
    }
};