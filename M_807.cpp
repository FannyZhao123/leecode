/*
807. Max Increase to Keep City Skyline
In a 2 dimensional array grid, each value grid[i][j] represents the height of a building located there. We are allowed to increase the height of any number of buildings, by any amount (the amounts can be different for different buildings). Height 0 is considered to be a building as well. 

At the end, the "skyline" when viewed from all four directions of the grid, i.e. top, bottom, left, and right, must be the same as the skyline of the original grid. A city's skyline is the outer contour of the rectangles formed by all the buildings when viewed from a distance. See the following example.

What is the maximum total sum that the height of the buildings can be increased?

Example:
Input: grid = [[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]
Output: 35
Explanation: 
The grid is:
[ [3, 0, 8, 4], 
  [2, 4, 5, 7],
  [9, 2, 6, 3],
  [0, 3, 1, 0] ]

The skyline viewed from top or bottom is: [9, 4, 8, 7]
The skyline viewed from left or right is: [8, 7, 9, 3]

The grid after increasing the height of buildings without affecting skylines is:

gridNew = [ [8, 4, 8, 7],
            [7, 4, 7, 7],
            [9, 4, 8, 7],
            [3, 3, 3, 3] ]

Notes:

1 < grid.length = grid[0].length <= 50.
All heights grid[i][j] are in the range [0, 100].
All buildings in grid[i][j] occupy the entire grid cell: that is, they are a 1 x 1 x grid[i][j] rectangular prism.
*/


//Runtime: 16 ms, faster than 9.09% of C++ online submissions for Max Increase to Keep City Skyline.
//Memory Usage: 10.4 MB, less than 6.45% of C++ online submissions for Max Increase to Keep City Skyline.
class Solution {
public:
    int totalIncreace = 0;
    vector<int> top;
    vector<int> right;
    
    void skyline_top (vector<vector<int>>& grid, int x, int y){
        for (int i = 0; i < y; i++){
            int max = 0;
            for (int j =0; j < x; j++){
                if (grid[j][i] > max){
                    max = grid[j][i];
                }
            }
            top.push_back(max);
        }
    }
    
    void skyline_right (vector<vector<int>>& grid, int x, int y){
        for (int i = 0; i < x; i++){
            int max = 0;
            for (int j =0; j < y; j++){
                if (grid[i][j] > max){
                    max = grid[i][j];
                }
            }
            right.push_back(max);
        }
    }
    
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int x = grid.size();
        int y = grid[1].size();
        skyline_top(grid, x, y);
        skyline_right(grid, x, y);
        for (int i = 0; i < x; i++){
            for (int j =0; j < y; j++){
                int temp = min(top[j], right[i]);
                if (grid[i][j] < temp){
                    totalIncreace += (temp - grid[i][j]);
                }
            }
        }
        return totalIncreace;
    }
};


// better , but not best 
//Runtime: 12 ms, faster than 14.94% of C++ online submissions for Max Increase to Keep City Skyline.
//Memory Usage: 10.2 MB, less than 6.45% of C++ online submissions for Max Increase to Keep City Skyline.
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> row(m,0), col(n,0);
        for(int i=0; i<m; i++)
        {            
            for(int j=0; j<n; ++j)
            {
               if(row[i] < grid[i][j])
                   row[i]= grid[i][j];
                
                 if(col[j] < grid[i][j])
                    col[j]= grid[i][j];
            }            
        }
        
        
        int totalSum = 0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; ++j)
            {
               totalSum += min(row[i],col[j])-grid[i][j];
            }
        }
        return totalSum;
    }
};