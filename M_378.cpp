/*
378. Kth Smallest Element in a Sorted Matrix
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,
return 13.

Note:
You may assume k is always valid, 1 ≤ k ≤ n2.
*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        priority_queue<int>pq;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pq.push(matrix[i][j]);
                if (pq.size() > k)
                    pq.pop();
            }
        }
        
        return pq.top();
    }
};

//integer binary search
//Time: 32 * N * lg(N), Space: O(1)
//better
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        
        long lo = matrix[0][0];
        long hi = matrix[n-1][n-1];
        
        while (lo < hi) {
            long mi = lo + (hi-lo)/2;
            int no_less_number = countNoLess(static_cast<int>(mi), matrix);
            if (no_less_number >= k)
                hi = mi;
            else
                lo = mi + 1;
        }
        return lo;
    }
    
private:
    // count each row number which is <= val
    int countNoLess(const int val, const vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        int count = 0;
        for (int r = 0; r < n; ++r) {
            auto it = std::upper_bound(matrix[r].begin(), matrix[r].end(), val);
            count += it - matrix[r].begin();
        }
        return count;
    }
};