/*
998. Maximum Binary Tree II
We are given the root node of a maximum tree: a tree where every node has a value greater than any other value in its subtree.

Just as in the previous problem, the given tree was constructed from an list A (root = Construct(A)) recursively with the following Construct(A) routine:

If A is empty, return null.
Otherwise, let A[i] be the largest element of A.  Create a root node with value A[i].
The left child of root will be Construct([A[0], A[1], ..., A[i-1]])
The right child of root will be Construct([A[i+1], A[i+2], ..., A[A.length - 1]])
Return root.
Note that we were not given A directly, only a root node root = Construct(A).

Suppose B is a copy of A with the value val appended to it.  It is guaranteed that B has unique values.

Return Construct(B).

 

Example 1:
Input: root = [4,1,3,null,null,2], val = 5
Output: [5,4,null,1,3,null,null,2]
Explanation: A = [1,4,2,3], B = [1,4,2,3,5]

Example 2:
Input: root = [5,2,4,null,1], val = 3
Output: [5,2,4,null,1,null,3]
Explanation: A = [2,1,5,4], B = [2,1,5,4,3]

Example 3:
Input: root = [5,2,3,null,1], val = 4
Output: [5,2,4,null,1,3]
Explanation: A = [2,1,5,3], B = [2,1,5,3,4]
 

Note:
1 <= B.length <= 100
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

//Runtime: 8 ms, faster than 45.50% of C++ online submissions for Maximum Binary Tree II.
//Memory Usage: 15.9 MB, less than 20.00% of C++ online submissions for Maximum Binary Tree II.
class Solution {
public:
    vector<int> tree_to_vector (TreeNode* root){
        vector<int> result;
        if (!root) return result;
        int max = root->val;
        vector<int> left = tree_to_vector(root->left);
        vector<int> right = tree_to_vector(root->right);
        result.insert(result.end(), left.begin(), left.end());
        result.push_back(max);
        result.insert(result.end(), right.begin(), right.end());
        return result;
    }
    
    TreeNode* construct(vector<int>& nums, int s, int e) {
        if (s>e) return NULL;
        int m = nums[s], ind = s;
        for (int i=s+1; i<=e; i++){
            if (nums[i]>m){
                m = nums[i]; ind = i;
            }
        }
        TreeNode* node = new TreeNode(m);
        node->left = construct(nums, s, ind-1);
        node->right = construct(nums, ind+1, e);
        return node;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums, 0, nums.size()-1);
    }
    
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        vector<int> tree = tree_to_vector(root);
        cout << tree.size() << endl;
        tree.push_back(val);
        return constructMaximumBinaryTree(tree);
    }
};