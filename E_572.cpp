/*
572. Subtree of Another Tree
Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

Example 1:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4 
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.
 

Example 2:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
Return false.
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
    bool sameTree (TreeNode* s, TreeNode* t){
        if (!s && !t) return true;
        if (!s || !t) return false;
        if(s->val != t->val) return false;
        else return sameTree(s->left, t->left)&&sameTree(s->right, t->right);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (!s || !t) return false;
        
        if(sameTree(s, t)) return true;
        return (isSubtree(s->left, t) || isSubtree(s->right, t));
    }
};


class Solution {
    vector<TreeNode*> nodes;
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (!s || !t) return false;
        getDepth(s, getDepth(t, -1));
        for (TreeNode* n: nodes)
            if (identical(n, t))
                return true;
        return false;
    }
    int getDepth(TreeNode* r, int d) {
        if (!r)
            return -1;
        int depth = max(getDepth(r->left, d), getDepth(r->right, d)) + 1;
        if (depth == d)
            nodes.push_back(r);
        return depth;
    }
    bool identical(TreeNode* a, TreeNode* b) {
        if (!a && !b) return true;
        if (!a || !b || a->val != b->val) return false;
        return identical(a->left, b->left) && identical(a->right, b->right);
    }
};