/*
797. All Paths From Source to Target
Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.

The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.

Example:
Input: [[1,2], [3], [3], []] 
Output: [[0,1,3],[0,2,3]] 
Explanation: The graph looks like this:
0--->1
|    |
v    v
2--->3
There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
Note:

The number of nodes in the graph will be in the range [2, 15].
You can print different paths in any order, but you should keep the order of nodes inside one path.
*/

//Runtime: 16 ms, faster than 98.00% of C++ online submissions for All Paths From Source to Target.
//Memory Usage: 12.2 MB, less than 100.00% of C++ online submissions for All Paths From Source to Target.
class Solution {
    vector<vector<int>>res;
    void dfs(vector<vector<int>>& graph, int i, int n, vector<int>&v) {
        if (i == n-1)
            res.push_back(v);
        for (int j  = 0; j < graph[i].size(); j++) {
            v.push_back(graph[i][j]);
            dfs(graph, graph[i][j], n, v);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>v;
        v.push_back(0);
        dfs(graph, 0, n, v);
        return res;
    }
};