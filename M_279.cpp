/*
279. Perfect Squares
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
*/
//Runtime: 216 ms, faster than 54.84% of C++ online submissions for Perfect Squares.
//Memory Usage: 9.1 MB, less than 90.38% of C++ online submissions for Perfect Squares.
/*
0 --> 0 fixed.
1 --> subtract all the possible squares starting from 1 and check
subtracting 1 is possible, okay... 1 + dp[1-1] = 1 + dp[0] = 1;
min(INT_MAX, 1) is 1 therefore dp[1] = 1;
2--> 1 + dp[2-1] = 1 + dp[1] = 2
3--> 1 + dp[3-1] = 1 + dp[2] = 3
4--> here we have two possiblities! minimim of 1+dp[4-1] and 1+dp[4-4]
min(1+dp[3], 1+ dp[0]) which is min(1+3, 1+0) =>1
5--> Again two possibilities, 1 and 4 both can be considered..

dp[18]
possible squares till this point are: 1,4,9,16
min(1+dp[18-1], 1+dp[18-4], 1+dp[18-9], 1+dp[18-16])
min(1+dp[17], 1+dp[14], 1+dp[9], 1+dp[2])
min(3, 4, 2, 3)
===> 2 is the answer.
*/
class Solution {
public:
	int numSquares(int n) {
        if(n<=0)return 0;
        
        vector<int>dp(n+1, INT_MAX);
        dp[0] = 0; 
        for(int i = 1; i<=n; i++)
            for(int j = 1; j*j<=i; j++)
                dp[i] = min(dp[i], 1+dp[i- j*j]);
            
        return dp[n];
    }
};

//Runtime: 896 ms, faster than 5.01% of C++ online submissions for Perfect Squares.
//Memory Usage: 9.4 MB, less than 90.38% of C++ online submissions for Perfect Squares.

class Solution {
public:
	int numSquares(int n) {
	   
		vector<int> nums;
		vector<int> dp(n+1,INT_MAX);
		for(int i=1;i*i<=n;i++){
			nums.push_back(i*i);
			dp[i*i] = 1;
		}
		
		for(int i=1;i<n;i++)
			for(int j=0;j<nums.size();j++){
				if(dp[i]!=INT_MAX&&i+nums[j]<=n)
					dp[i+nums[j]] = min(dp[i+nums[j]] , dp[i]+1);
			}
		return dp[n]==INT_MAX?n:dp[n];	
	}
};