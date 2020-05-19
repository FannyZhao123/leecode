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