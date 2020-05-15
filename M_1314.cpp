/*
1314. Matrix Block Sum
Given a m * n matrix mat and an integer K, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for i - K <= r <= i + K, j - K <= c <= j + K, and (r, c) is a valid position in the matrix.
 

Example 1:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], K = 1
Output: [[12,21,16],[27,45,33],[24,39,28]]
Example 2:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], K = 2
Output: [[45,45,45],[45,45,45],[45,45,45]]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n, K <= 100
1 <= mat[i][j] <= 100
*/

//memory good but slow
//Runtime: 1040 ms, faster than 8.82% of C++ online submissions for Matrix Block Sum.
//Memory Usage: 9.3 MB, less than 100.00% of C++ online submissions for Matrix Block Sum.
class Solution {
public:
    int sumup (vector<vector<int>>& mat, int k, int sum, int i, int j, int m, int n){
        for (int r = max(0, i-k); r <= min(i+k, m); r++){
            for (int c = max(0, j-k); c <= min(j+k, n); c++){
                    sum+=mat[r][c];
            }
        }
        return sum;
    }
    
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> answer(m , vector<int> (n, 0));
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                int sum = sumup(mat, K, 0, i, j, m-1, n-1);
                answer[i][j] += sum;
            }
        }
        return answer;
    }
};


//Runtime: 16 ms, faster than 93.89% of C++ online submissions for Matrix Block Sum.
//Memory Usage: 9.3 MB, less than 100.00% of C++ online submissions for Matrix Block Sum.
class Solution {
public:
    void prefixSum(vector<vector<int>> &mat, int rows, int cols)
    {
        for(int i=1; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                mat[i][j] += mat[i-1][j];
            }
        }
        for(int i=1; i<cols; i++)
        {
            for(int j=0; j<rows; j++)
            {
                mat[j][i] += mat[j][i-1];
            }
        }
    }
    void blockSum(vector<vector<int>> &mat, vector <vector<int>> &res, int K)
    {
        int row = mat.size(), col = mat[0].size();
        for(int rows=0; rows<row; rows++)
        {
            for(int cols=0; cols<col; cols++)
            {
                int r1 = max(0, rows-K), c1 = max(0, cols-K);
                int r2 = min(row-1 , rows+K), c2 = min(col-1, cols+K);
                //加上最右下角所有的和
                int ans = mat[r2][c2];
                if(r1-1 >= 0 && c1-1 >= 0)
                	//加上最左上角所有的和
                	//此时第一象限被加了两遍
                    ans += mat[r1-1][c1-1];
                if(r1-1 >= 0)
                	//减掉第一象限，第二象限
                    ans -= mat[r1-1][c2];
                if(c1-1 >= 0)
                	//减掉第一象限第三象限，最后就只剩下第四象限
                    ans -= mat[r2][c1-1];
                res[rows][cols] = ans;
            }
        }
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int rows = mat.size(), cols = mat[0].size();
        vector <vector<int>> res(rows, vector<int>(cols));
        prefixSum(mat, rows, cols);
        blockSum(mat, res, K);
        return res;
    }
};

//dynamic programming
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int> >& mat, int k) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int> > dp(m+1,vector<int>(n+1));
        dp[0][0]=mat[0][0];
        for(int i=1;i<n;i++){
            dp[0][i]=dp[0][i-1]+mat[0][i];
        }
        for(int i=1;i<m;i++){
            dp[i][0]=dp[i-1][0]+mat[i][0];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+mat[i][j];
            }
        }
        vector<vector<int> > ans(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=dp[min(i+k,m-1)][min(j+k,n-1)]-((j-k-1)>=0 ? dp[min(i+k,m-1)][j-k-1] : 0)-((i-k-1)>=0 ? dp[i-k-1][min(n-1,j+k)] : 0)+(((j-k-1)>=0 && (i-k-1)>=0) ? dp[i-k-1][j-k-1] : 0);
            }
        }
        return ans;
    }
};