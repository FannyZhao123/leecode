/*
701. Insert into a Binary Search Tree
Given the root node of a binary search tree (BST) and a value to be inserted into the tree, insert the value into the BST. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Note that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

For example, 

Given the tree:
        4
       / \
      2   7
     / \
    1   3
And the value to insert: 5
You can return this binary search tree:

         4
       /   \
      2     7
     / \   /
    1   3 5
This tree is also valid:

         5
       /   \
      2     7
     / \   
    1   3
         \
          4
*/

//mine 
//Runtime: 112 ms, faster than 90.46% of C++ online submissions for Insert into a Binary Search Tree.
//Memory Usage: 42.4 MB, less than 6.25% of C++ online submissions for Insert into a Binary Search Tree.
class Solution {
public:
    vector <int> tree;
    void convertTree (TreeNode* root){
        if (!root) return;
        tree.push_back(root->val);
        convertTree(root->right);
        convertTree(root->left);
    }
    
    TreeNode* build_tree (TreeNode* result, int counter){
        if (counter == tree.size()) return result;
        TreeNode* t = result;
        result->right = new TreeNode(tree[counter]);  
        t = result->right;
        counter++;
        build_tree(t, counter);
        return result;
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        convertTree(root);
        tree.push_back(val);
        sort(tree.begin(), tree.end());
        int begin = tree[0];
        TreeNode* result  = new TreeNode(begin);
        return build_tree(result,1);
    }
};

//Runtime: 88 ms, faster than 98.40% of C++ online submissions for Insert into a Binary Search Tree.
//Memory Usage: 38.5 MB, less than 6.25% of C++ online submissions for Insert into a Binary Search Tree.
TreeNode* insertIntoBST(TreeNode* r, int val) {
    if (r != nullptr)
        if (val < r->val)
            r->left = insertIntoBST(r->left, val);
        else
            r->right = insertIntoBST(r->right, val);            
    return r ?: new TreeNode(val);
}