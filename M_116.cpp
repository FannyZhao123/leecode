/*
116. Populating Next Right Pointers in Each Node
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.

Follow up:
You may only use constant extra space.
Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.
 

Example 1:
Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
 
Constraints:
The number of nodes in the given tree is less than 4096.
-1000 <= node.val <= 1000
*/


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

//Runtime: 40 ms, faster than 9.02% of C++ online submissions for Populating Next Right Pointers in Each Node.
//Memory Usage: 17.6 MB, less than 100.00% of C++ online submissions for Populating Next Right Pointers in Each Node.
class Solution {
public:
    vector<vector<Node*>> node_level;
    void bfs (Node* root, int level){
        if (!root) return;
        if(!root->left && !root->right) return;
        if (node_level.size() > level){
            Node* temp = node_level[level].back();
            temp->next = root->left;
            node_level[level].push_back(root->left);
            root->left->next = root->right;
            root->right->next = NULL;
            node_level[level].push_back(root->right);
        }
        else{
            vector<Node*> l;
            l.push_back(root->left);
            node_level.push_back(l);
            root->left->next = root->right;
            node_level[level].push_back(root->right);
            root->right->next = NULL;
        }
        
        bfs(root->left, level+1);
        bfs(root->right, level+1);
    }
    
    Node* connect(Node* root) {
        if(!root) return NULL;
        vector<Node*> l;
        l.push_back(root);
        root->next = NULL;
        node_level.push_back(l);
        bfs(root, 1);
        return root;
    }
};


//faster Solution
//Runtime: 28 ms, faster than 64.44% of C++ online submissions for Populating Next Right Pointers in Each Node.
//Memory Usage: 18.2 MB, less than 100.00% of C++ online submissions for Populating Next Right Pointers in Each Node.
class Solution {
public:
    Node* rTree = NULL; 
    /*
        1. Pop all nodes and put in a vector<node>
        2. Set node->next = right
        3. Rebuild tree
    */
    Node* connect(Node* root) {
        if(!root){
            return root;
        }
        vector<vector<Node*>> ty; 
        queue<Node*> q;
        q.push(root); 
        while(!q.empty()){
            int n = q.size();
            vector<Node*> temp; 
            while(n > 0){
                Node *t = q.front(); 
                temp.push_back(t);
                q.pop(); 
                n--; 
                if(t->left != NULL) q.push(t->left);
                if(t->right != NULL) q.push(t->right);
            }
            ty.push_back(temp); 
        }
        // Now we have all nodes level wise
        // Go to each level and set next pointer
        for(int i = 0; i < ty.size(); i++){
            if(ty[i].size() == 1){
                ty[i][0]->next = NULL; 
                continue;
            } else {
                for(int j = 0; j < ty[i].size()-1; j++){
                    ty[i][j]->next = ty[i][j+1]; 
                }
                // Set the last element in this level to NULL
                ty[i][ty[i].size()-1]->next = NULL;
            }  
        }
        // for(int i = 0; i < ty.size(); i++){
        //     for(int j = 0; j < ty[i].size(); j++){
        //         cout << ty[i][j]->val << "->"; 
        //         ty[i][j]->next == NULL ? cout << "NULL" : cout << ty[i][j]->next->val; 
        //         cout << " ";
        //     }
        //     cout << endl;
        // }
        return root; 
    }
};