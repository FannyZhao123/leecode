/*
802. Find Eventual Safe States
In a directed graph, we start at some node and every turn, walk along a directed edge of the graph.  If we reach a node that is terminal (that is, it has no outgoing directed edges), we stop.

Now, say our starting node is eventually safe if and only if we must eventually walk to a terminal node.  More specifically, there exists a natural number K so that for any choice of where to walk, we must have stopped at a terminal node in less than K steps.

Which nodes are eventually safe?  Return them as an array in sorted order.

The directed graph has N nodes with labels 0, 1, ..., N-1, where N is the length of graph.  The graph is given in the following form: graph[i] is a list of labels j such that (i, j) is a directed edge of the graph.

Example:
Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]

Note:
graph will have length at most 10000.
The number of edges in the graph will not exceed 32000.
Each graph[i] will be a sorted list of different integers, chosen within the range [0, graph.length - 1].
*/

//自己没做出来 看的别人的
//Runtime: 344 ms, faster than 26.57% of C++ online submissions for Find Eventual Safe States.
//Memory Usage: 46.9 MB, less than 15.38% of C++ online submissions for Find Eventual Safe States.
class Solution {
public:
    vector<bool> cycle;//All node which leads to cycle will be set true
    vector<bool> visited;
    
    void dfscycle (vector<vector<int>>& graph,int node,vector<bool>&instack){
        visited[node]=true;
        instack[node]=true;
    
        for(int neighbour:graph[node]){
            if(!visited[neighbour])
                dfscycle(graph,neighbour,instack);
        
            if(instack[neighbour]||cycle[neighbour]) cycle[node]=true;
            //BACK EDGE OR NEIGHBOUR LEADING TO A CYCLE MEANS THAT NODE IS UNSAFE
        }
        instack[node]=false;
        return;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
         vector<bool>instack(graph.size(),false);
         cycle.resize(graph.size(),false);
         visited.resize(graph.size(),false);
         vector<int> result;
         for(int i=0;i<graph.size();i++){
            if(!visited[i])//First visit if not visited
                dfscycle(graph,i,instack);
            if(cycle[i]==false) result.push_back(i);
        //Then check if this node leads to a cycle. Push it to result if it's not.
      }
    return result;
    }
};