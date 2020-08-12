/*
1192. Critical Connections in a Network
There are n servers numbered from 0 to n-1 connected by undirected server-to-server connections forming a network where connections[i] = [a, b] represents a connection between servers a and b. Any server can reach any other server directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some server unable to reach some other server.

Return all critical connections in the network in any order.

Example 1:
Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
 

Constraints:

1 <= n <= 10^5
n-1 <= connections.length <= 10^5
connections[i][0] != connections[i][1]
There are no repeated connections.
*/

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        int time = 0;
        vector<vector<int>> parents (n, vector<int>());
        vector <int> shortest (n, -1);
        vector <int> level (n, -1);
        vector <bool> visit (n, false);
        vector<vector<int>> res;
        for ( auto edges:connections){
            parents[edges[0]].push_back(edges[1]);
            parents[edges[1]].push_back(edges[0]);
        }
        for (int i = 0; i < n; i++){
            if(!visit[i]){
                dfs(i, -1, res, parents, shortest, level, visit, time);
            }
        }
        return res;
    }
    
    void dfs (int a, int parent, vector<vector<int>>& res, vector<vector<int>>& parents, vector <int>& shortest,vector <int>& level,vector <bool>& visit, int&time){
        shortest[a] = level[a] = time++;
        visit[a] = true;
        for( auto b:parents[a]){
            if(!visit[b]){
                dfs(b, a, res, parents, shortest, level, visit, time);
                shortest[a] = min(shortest[a], shortest[b]);
                if(level[a] < shortest[b]){
                    vector<int> new_edge;
                    new_edge.push_back(a);
                    new_edge.push_back(b);
                    res.push_back(new_edge);
                }
            }
            else if(b!= parent){
                shortest[a] = min(shortest[a], level[b]);
            }
        }
    }
};