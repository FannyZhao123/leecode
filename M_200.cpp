/*
200. Number of Islands
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:
Input:
11110
11010
11000
00000
Output: 1

Example 2:
Input:
11000
11000
00100
00011
Output: 3
*/
//mine 
//Runtime: 36 ms, faster than 13.14% of C++ online submissions for Number of Islands.
//Memory Usage: 9.6 MB, less than 100.00% of C++ online submissions for Number of Islands.
class Solution {
public:
    void climLand (vector<vector<char>>& grid, int x, int y, int i, int j){
        //if (grid == NULL) return;
        grid[i][j] = '0';
        if (i-1>=0 && grid[i-1][j] == '1') climLand (grid, x, y, i-1, j);
        if (i+1<y && grid[i+1][j] == '1') climLand (grid, x, y, i+1, j);
        if (j-1>=0 && grid[i][j-1] == '1') climLand (grid, x, y, i, j-1);
        if (j+1<x && grid[i][j+1] == '1') climLand (grid, x, y, i, j+1);
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        if(grid.empty()) return res;
        int y = grid.size();
        int x = grid[0].size();
        for (int i = 0; i < y; i++){
            for (int j = 0; j< x; j++){
                if(grid[i][j] == '1'){
                    cout << "i =" << i << " and j = " << j << endl;
                    res++;
                    climLand (grid, x, y, i, j);
                }
            }
        }
        return res;
    }
};

//a bit faster, using direction.
class Solution {
    int c=0;
    int x[4]={-1,0,1,0};
    int y[4]={0,1,0,-1};
public:
    void dfs(vector<vector<char> > &gr,int i,int j,int m,int n,vector<vector<int> > &vis){
        vis[i][j]=1;
        for(int dir=0;dir<4;dir++){
            int xd=i+x[dir];
            int yd=j+y[dir];
            if(xd>=0 && yd>=0 && xd<=m-1 && yd<=n-1){
                if(!vis[xd][yd] && gr[xd][yd]=='1'){
                    dfs(gr,xd,yd,m,n,vis);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        if(m==0) return 0;
        int n=grid[0].size();
        vector<vector<int> > visi(m+1,vector<int>(n+1,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !visi[i][j]){
                    c++;
                    dfs(grid,i,j,m,n,visi);
                }
            }
        }
        return c;
    }
};

//using queue, BFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (!grid.size() || !grid[0].size()) return 0;
        int count = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<int> queue; 
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0' || visited[i][j]) continue;
                count++;
                visited[i][j] = true;
                queue.push(i * n + j);
                while (!queue.empty()) {
                    int x = queue.front() / n, y = queue.front() % n;
                    queue.pop();
                    if (grid[x][y] == '0') continue;
                    if (x - 1 >= 0 && !visited[x-1][y]) {queue.push((x-1) * n + y); visited[x-1][y] = true;}
                    if (y - 1 >= 0 && !visited[x][y-1]) {queue.push(x * n + y-1); visited[x][y-1] = true;}
                    if (x + 1 < m && !visited[x+1][y]) {queue.push((x+1) * n + y); visited[x+1][y] = true;}
                    if (y + 1 < n && !visited[x][y+1]) {queue.push(x * n + y+1); visited[x][y+1] = true;}
                }
            }
                
        return count;           
    }

};