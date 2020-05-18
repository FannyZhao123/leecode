/*
106. Construct Binary Tree from Inorder and Postorder Traversal
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
*/
/*
Explanation/Discussion:

Consider this input:

preorder: [1, 2, 4, 5, 3, 6]
inorder: [4, 2, 5, 1, 6, 3]
The obvious way to build the tree is:

Use the first element of preorder, the 1, as root.
Search it in inorder.
Split inorder by it, here into [4, 2, 5] and [6, 3].
Split the rest of preorder into two parts as large as the inorder parts, here into [2, 4, 5] and [3, 6].
Use preorder = [2, 4, 5] and inorder = [4, 2, 5] to add the left subtree.
Use preorder =[3, 6]andinorder = [6, 3] to add the right subtree.
*/

class Solution {
public:
    
    TreeNode* helper (vector<int>&inorder, int b1, int e1, vector<int>&postorder, int b2, int e2){
        if (b1 > e1) return NULL;
        int found;
        for (int i=b1; i<e1; i++){
            if (inorder[i] == postorder[e2]){
                found = i;
                break;
            }
        }
        int right_len = found-b1;
        TreeNode* res = new TreeNode(postorder[e2]);
        res->left = helper (inorder, b1, found-1, postorder, b2, b2+right_len-1);
        res->right = helper (inorder, found+1, e1, postorder, b2+right_len, e2-1);
        return res;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int i = inorder.size();
        int p = postorder.size();
        if (i == 0) return NULL;
        return helper(inorder, 0, i-1, postorder, 0, p-1);
        
    }
};

