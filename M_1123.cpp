/*
1123. Lowest Common Ancestor of Deepest Leaves
Given a rooted binary tree, return the lowest common ancestor of its deepest leaves.

Recall that:
The node of a binary tree is a leaf if and only if it has no children
The depth of the root of the tree is 0, and if the depth of a node is d, the depth of each of its children is d+1.
The lowest common ancestor of a set S of nodes is the node A with the largest depth such that every node in S is in the subtree with root A.
 
Example 1
Input: root = [1,2,3]
Output: [1,2,3]
Explanation: 
The deepest leaves are the nodes with values 2 and 3.
The lowest common ancestor of these leaves is the node with value 1.
The answer returned is a TreeNode object (not an array) with serialization "[1,2,3]".

Example 2:
Input: root = [1,2,3,4]
Output: [4]

Example 3:
Input: root = [1,2,3,4,5]
Output: [2,4,5]
 
Constraints:
The given tree will have between 1 and 1000 nodes.
Each node of the tree will have a distinct value between 1 and 1000.
*/
//Runtime: 24 ms, faster than 25.14% of C++ online submissions for Lowest Common Ancestor of Deepest Leaves.
//Memory Usage: 20.6 MB, less than 100.00% of C++ online submissions for Lowest Common Ancestor of Deepest Leaves.
class Solution {
public:
    int height(TreeNode *root){
        if(!root)
            return 0;
        return 1+max(height(root->left),height(root->right));
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root->left&&!root->right)
            return root;
        if(root->left && root->right){
            int a=height(root->left),
            b=height(root->right);
            if(a==b)
                return root;
            else if(a>b)
                return lcaDeepestLeaves(root->left);
            else
                return lcaDeepestLeaves(root->right);
        }
        if(!root->left)
            return lcaDeepestLeaves(root->right);
        else
            return lcaDeepestLeaves(root->left);
    }
};

