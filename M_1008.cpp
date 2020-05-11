/*
1008. Construct Binary Search Tree from Preorder Traversal
Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.

Example 1:
Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]
           8
          / \
         5   10
        / \    \
       1  7     12

Constraints:
1 <= preorder.length <= 100
1 <= preorder[i] <= 10^8
The values of preorder are distinct.
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
//Runtime: 12 ms, faster than 39.89% of C++ online submissions for Construct Binary Search Tree from Preorder Traversal.
//Memory Usage: 14.8 MB, less than 9.52% of C++ online submissions for Construct Binary Search Tree from Preorder Traversal.
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int size = preorder.size();
        if (!size) return nullptr; 
        TreeNode* tree = new TreeNode(preorder[0]);
        int root = preorder[0];
        vector<int> leftV, rightV;
        for (int i = 1; i<size; i++){
            if (preorder[i]<root){
                leftV.push_back(preorder[i]);
            }
            else {
                rightV.push_back(preorder[i]);
            }
        }
        tree->left = bstFromPreorder(leftV);
        tree->right = bstFromPreorder(rightV);
        return tree;
    }
};


//much faster, using pointer
//Runtime: 4 ms, faster than 85.27% of C++ online submissions for Construct Binary Search Tree from Preorder Traversal.
//Memory Usage: 9 MB, less than 100.00% of C++ online submissions for Construct Binary Search Tree from Preorder Traversal.
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        if(preorder.empty())
            return NULL;
        
        TreeNode * root = nullptr;
        for(auto x: preorder){
            if(root == nullptr){
                root = new TreeNode(x);
            }else{
                TreeNode* temp = root,*prev=NULL;     
                
                while(temp!=NULL){
                    prev = temp;
                    if(temp->val > x){
                        temp = temp->left;
                    }else {
                        temp =temp->right;
                    }
                }
                
                if(x>prev->val){
                    prev -> right = new TreeNode(x);                    
                }
                else {
                    prev->left = new TreeNode(x);
                }
            }
        }
        return root;
    }
};