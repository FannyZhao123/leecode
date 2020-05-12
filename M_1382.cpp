/*
1382. Balance a Binary Search Tree

Example:
Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2,null,null] is also correct.
 

Constraints:
The number of nodes in the tree is between 1 and 10^4.
The tree nodes will have distinct values between 1 and 10^5.
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
    void BSTtoVector (TreeNode* root, vector<int>& v){
        if (!root) return;
        BSTtoVector(root->left, v);
        v.push_back(root->val);
        BSTtoVector(root->right, v);
    } 
    
    TreeNode* buildBalencedBST (vector<int>& v, int begin, int end){
        if(begin>end) return nullptr;
        int mid = (begin+end)/2;
        TreeNode* result = new TreeNode(v[mid]);
        result->left = buildBalencedBST(v, begin, mid-1);
        result->right = buildBalencedBST(v, mid+1, end);
        return result;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        BSTtoVector(root, v);
        int s = v.size();
        return buildBalencedBST(v, 0, s-1);
    }
};