/*
105. Construct Binary Tree from Preorder and Inorder Traversal
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
*/
   
//Runtime: 32 ms, faster than 52.93% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
//Memory Usage: 23.1 MB, less than 9.52% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.

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
    TreeNode* helper (vector<int>& preorder, int b1, int e1, vector<int>& inorder, int b2, int e2){
        if (b2>e2) return NULL;
        int found, size;
        for (int i = b2; i < e2; i++){
            if(preorder[b1] == inorder[i]){
                found = i;
                break;
            }
        }
        size = found-b2;
        TreeNode* res = new TreeNode(preorder[b1]);
        res->left = helper(preorder, b1+1, b1+size, inorder, b2, found-1);
        res->right = helper(preorder, b1+1+size, e1, inorder, found+1, e2);
        return res;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i = inorder.size();
        int p = preorder.size();
        if (i == 0) return NULL;
        return helper(preorder, 0, p-1, inorder, 0, i-1);
    }
};
