/*
1161. Maximum Level Sum of a Binary Tree
Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.
Return the smallest level X such that the sum of all the values of nodes at level X is maximal.

Example 1:
Input: [1,7,0,7,-8,null,null]
Output: 2
Explanation: 
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.
 
Note:
The number of nodes in the given tree is between 1 and 10^4.
-10^5 <= node.val <= 10^5
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

//Runtime: 272 ms, faster than 41.35% of C++ online submissions for Maximum Level Sum of a Binary Tree.
//Memory Usage: 104.7 MB, less than 100.00% of C++ online submissions for Maximum Level Sum of a Binary Tree
class Solution {
public:
    void bfs (TreeNode* root, vector<int>& sum, int level){
        if (!root) return;
        if(level > sum.size()-1) sum.push_back(root->val);
        else sum[level] += root ->val;
        level ++;
        bfs(root->left, sum, level);
        bfs(root->right, sum, level);
    }
    
    int maxLevelSum(TreeNode* root) {
        vector<int> sum;
        sum.push_back(0);
        bfs(root, sum, 1);
        int maxsum = 0;
        int x = 1;
        for (int i = 1; i<sum.size(); i++){
            if (maxsum < sum[i]){
                maxsum = sum[i];
                x = i;
            }
        }
        return x;
    }
};

