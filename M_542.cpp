/*
542. 01 Matrix
Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

 

Example 1:

Input:
[[0,0,0],
 [0,1,0],
 [0,0,0]]

Output:
[[0,0,0],
 [0,1,0],
 [0,0,0]]
Example 2:

Input:
[[0,0,0],
 [0,1,0],
 [1,1,1]]

Output:
[[0,0,0],
 [0,1,0],
 [1,2,1]]
 

Note:

The number of elements of the given matrix will not exceed 10,000.
There are at least one 0 in the given matrix.
The cells are adjacent in only four directions: up, down, left and right.
*/
//Runtime: 124 ms, faster than 93.79% of C++ online submissions for 01 Matrix.
//Memory Usage: 30 MB, less than 33.33% of C++ online submissions for 01 Matrix.
class Solution {
public:
    //using queue
    void helper(vector<vector<int>>& matrix, queue<pair<int,int>>q){
        while (!q.empty()){
            auto point = q.front();
            q.pop();
            int x = point.first;
            int y = point.second;
            int min_curr = matrix[x][y];
            //check left
            if(y-1 >=0 && matrix[x][y-1] == INT_MAX){
                matrix[x][y-1] = min_curr+1;
                q.push(pair(x,y-1));
            }
            //check right
            if((y+1 < matrix[0].size()) && matrix[x][y+1] == INT_MAX){
                matrix[x][y+1] = min_curr+1;
                q.push(pair(x,y+1));
            }
            //check up
            if(x-1 >=0 && matrix[x-1][y] == INT_MAX){
                matrix[x-1][y] = min_curr+1;
                q.push(pair(x-1,y));
            }
            //check down
            if((x+1 < matrix.size()) && matrix[x+1][y] == INT_MAX){
                matrix[x+1][y] = min_curr+1;
                q.push(pair(x+1,y));
            }
        }
        return;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        queue<pair<int,int>>q;
        for (int i = 0; i<r; i++){
            for (int j = 0; j <c; j++){
                if (matrix[i][j]==0){
                    q.push(pair(i,j));
                }
                else matrix[i][j] = INT_MAX;
            }
        }
        helper(matrix, q);
        return matrix;
    }
};


