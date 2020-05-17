/*
437. Path Sum III
You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
*/
//Recursion + DFS
//Runtime: 36 ms, faster than 19.61% of C++ online submissions for Path Sum III.
//Memory Usage: 15.6 MB, less than 25.81% of C++ online submissions for Path Sum III.
class Solution {
public:
    int dfs(TreeNode* root, int sum){
        int res = 0;
        if (!root) return res;
        if (sum == root->val) res+=1;
        res += dfs(root->left, sum-root->val);
        res += dfs(root->right, sum-root->val);
        return res;
    }
    
    int pathSum(TreeNode* root, int sum) {
        int res = 0;
        if (!root) return res;
        res = dfs(root, sum);
        res += pathSum(root->left, sum);
        res += pathSum(root->right, sum);
        return res;
    }
};