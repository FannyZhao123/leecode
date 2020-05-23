/*
133. Clone Graph
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a val (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
 

Test case format:
For simplicity sake, each node's value is the same as the node's index (1-indexed). For example, the first node with val = 1, the second node with val = 2, and so on. The graph is represented in the test case using an adjacency list.
Adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.
The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.

Example 1:
Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).

Example 2:
Input: adjList = [[]]
Output: [[]]
Explanation: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.

Example 3:
Input: adjList = []
Output: []
Explanation: This an empty graph, it does not have any nodes.

Example 4:
Input: adjList = [[2],[1]]
Output: [[2],[1]]
 
Constraints:
1 <= Node.val <= 100
Node.val is unique for each node.
Number of Nodes will not exceed 100.
There is no repeated edges and no self-loops in the graph.
The Graph is connected and all nodes can be visited starting from the given node.
*/

/*
Solution1:
DFS using stack not recursion.
Time: O(n), Space: O(n) for visited map.
Runtime: 4 ms, faster than 98.64% of C++ online submissions for Clone Graph.
Memory Usage: 8.5 MB, less than 100.00% of C++ online submissions for Clone Graph.
*/
Node* cloneGraph(Node* node){
        if (node == NULL)
            return NULL; 
        unordered_map<int, Node*> visited;
        stack<Node*> st;
		// Push the node in the stack and create a corresponding copy node and mark it visited.
        st.push(node);
        Node* newStart = new Node(node->val);
        visited[node->val] = newStart;
		// While stack is not empty.
        while(!st.empty()){
            Node* topNode = st.top();
            Node* correspondingCopyNode = visited[topNode->val];
            st.pop();
            for (auto neighbour: topNode->neighbors){  
                Node* temp;
				// check if neighbour node already copied.
                if (visited.count(neighbour->val)>0){
                    temp = visited[neighbour->val];
                } else {
                    temp = new Node(neighbour->val);
                    visited[neighbour->val] = temp;
                    st.push(neighbour); 
                }
				// Update the neighbours of new copied node.
                correspondingCopyNode->neighbors.push_back(temp);           
            }  
        }
        return newStart;
    } 

/*
Solution2:
DFS using recursion.
Time: O(n) + recurssion overhead, Space: O(n) (visited map) + Recussion stack memory.
*/
Node* cloneGraphDfsHelper(Node* node, unordered_map<int, Node*>& visited) {
        Node* root = NULL;
        if (node == NULL)
            return root;
        if (visited.count(node->val)>0)
            return visited[node->val];
        root = new Node(node->val);
        visited[node->val] = root;
        for (auto neighbour: node->neighbors){
            root->neighbors.push_back(cloneGraphDfsHelper(neighbour, visited));
        }
        return root;
}
Node* cloneGraph(Node* node){
        unordered_map<int, Node*> visited;
