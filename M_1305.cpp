/*
1305. All Elements in Two Binary Search Trees
Given two binary search trees root1 and root2.

Return a list containing all the integers from both trees sorted in ascending order.

Example 1:
Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]

Example 2:
Input: root1 = [0,-10,10], root2 = [5,1,7,0,2]
Output: [-10,0,0,1,2,5,7,10]

Example 3:
Input: root1 = [], root2 = [5,1,7,0,2]
Output: [0,1,2,5,7]

Example 4:
Input: root1 = [0,-10,10], root2 = []
Output: [-10,0,10]

Example 5:
Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]
 

Constraints:
Each tree has at most 5000 nodes.
Each node's value is between [-10^5, 10^5].

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

//////***********///////
//soooo samrt!!!
//perfect!
//Runtime: 212 ms, faster than 97.47% of C++ online submissions for All Elements in Two Binary Search Trees.
//Memory Usage: 83.7 MB, less than 100.00% of C++ online submissions for All Elements in Two Binary Search Trees.
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v;
        v.reserve(10000);
        in_order(root1, v);
        int pos = v.size();
        in_order(root2, v);
        inplace_merge(v.begin(),v.begin()+pos, v.end());
        return v;
    }
    void in_order(TreeNode* root, vector<int>& v){
        if(!root) return ;
        in_order(root->left,v);
        v.push_back(root->val);
        in_order(root->right,v);
    }
};


//Runtime: 712 ms, faster than 5.12% of C++ online submissions for All Elements in Two Binary Search Trees.
//Memory Usage: 424.7 MB, less than 100.00% of C++ online submissions for All Elements in Two Binary Search Trees.
class Solution {
public:    
    vector<int> treeToVec (TreeNode* root){
        vector<int> result;
        if(!root) return result;
        else{
            if(root->left != nullptr){
                vector<int> left = treeToVec(root->left);
                result.insert(result.end(), left.begin(), left.end());
            }
            result.push_back(root->val);
            if(root->right != nullptr){
                vector<int> right = treeToVec(root->right);
                result.insert(result.end(), right.begin(), right.end());
            }   
        }
        return result;
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1 = treeToVec(root1);
        vector<int> v2 = treeToVec(root2);
        priority_queue<int>pq;
        vector<int> result1, result2;
        for (int i = 0; i<v1.size(); i++){
            pq.push(v1[i]);
        } 
        for (int i = 0; i<v2.size(); i++) pq.push(v2[i]);
        for (int i = 0; i<v1.size()+v2.size(); i++){
            result1.push_back(pq.top());
            pq.pop();
        }
        for (int i = result1.size()-1 ; i >= 0; i--){
            result2.push_back(result1[i]);
        }
        return result2;
    }
};

