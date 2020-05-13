/*
894. All Possible Full Binary Trees
A full binary tree is a binary tree where each node has exactly 0 or 2 children.

Return a list of all possible full binary trees with N nodes.  Each element of the answer is the root node of one possible tree.

Each node of each tree in the answer must have node.val = 0.

You may return the final list of trees in any order.

Example 1:
Input: 7
Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]


Note:
1 <= N <= 20
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
//Runtime: 56 ms, faster than 99.69% of C++ online submissions for All Possible Full Binary Trees.
//Memory Usage: 15.3 MB, less than 100.00% of C++ online submissions for All Possible Full Binary Trees.
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        if(N % 2 == 0) return {};
        vector<vector<TreeNode*>> dp(N+1);
        dp[1] = {new TreeNode(0)};
        for(int sub = 3; sub <= N; sub+=2){ //subproblem
            for(int left = 1; left < sub; left += 2){ //number of left child
                int right = sub - 1 - left; //number of right child
                for(auto& l : dp[left]){
                    for(auto& r : dp[right]){
                        TreeNode* root = new TreeNode(0);
                        root->left = l;
                        root->right = r;
                        dp[sub].push_back(root);
                    }
                }
            }
        }
        return dp[N];
    }
};