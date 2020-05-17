/*
101. Symmetric Tree
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
 

Follow up: Solve it both recursively and iteratively.
*/

//recursively
//Runtime: 8 ms, faster than 37.39% of C++ online submissions for Symmetric Tree.
//Memory Usage: 16.5 MB, less than 8.48% of C++ online submissions for Symmetric Tree.
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		return recur(root,root);
	}
	bool recur(TreeNode* &l,TreeNode* &r){
		if(l == r && l == nullptr) return true;
		if(l == nullptr || r == nullptr) return false;
		if(l->val != r->val) return false;
		return recur(l->right,r->left)&recur(l->left,r->right);
	}
};

//Runtime: 4 ms, faster than 78.00% of C++ online submissions for Symmetric Tree.
//Memory Usage: 16.5 MB, less than 8.48% of C++ online submissions for Symmetric Tree.
class Solution {
public:
    bool bfs(TreeNode* left, TreeNode* right){
        if (!left && !right) return true;
        if (!left || !right) return false;
        if (left->val != right->val) return false;
        return (bfs(left->left,right->right) &&bfs(right->left,left->right) );
    }
        
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        else return bfs(root->left, root->right);
    }
};


//iteratively for/while loop
//Runtime: 20 ms, faster than 8.75% of C++ online submissions for Symmetric Tree.
//Memory Usage: 16.8 MB, less than 8.48% of C++ online submissions for Symmetric Tree.
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        if(root->right and !root->left) return false;
        if(root->left and !root->right) return false;
        if(root->left == NULL and root->right == NULL) return true;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        TreeNode *a,*b;
        while(!q.empty()) {
            a = q.front();
            q.pop();
            b = q.front();
            q.pop();
            
            if(a->val != b->val) return false;
            
            if(a->left and b->right){
                q.push(a->left);
                q.push(b->right);
            }
            else if((a->left and !b->right) or (!a->left and b->right)) {
                return false;
            }
            
            if(a->right and b->left){
                q.push(a->right);
                q.push(b->left);
            }
            else if((a->right and !b->left) or (!a->right and b->left)) {
                return false;
            }
            
        }
        return true;
    }
};