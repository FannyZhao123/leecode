/*
494. Target Sum
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.
*/

//DP
//Runtime: 12 ms, faster than 83.67% of C++ online submissions for Target Sum.
//Memory Usage: 9.1 MB, less than 38.46% of C++ online submissions for Target Sum.
class Solution {
    int dp[20][2001];
    int findWays(const vector<int>& nums, int S, int i) {
        if (i < 0 || S > 1000 || S < -1000) return 0;
        if (dp[i][S + 1000] > -1) return dp[i][S + 1000];
        dp[i][S + 1000] = findWays(nums, S - nums[i], i - 1) + findWays(nums, S + nums[i], i - 1);
        return dp[i][S + 1000];
    }
public:
    int findTargetSumWays(vector<int>& nums, int S) {        
        memset(dp, -1, sizeof(int) * 20 * 2001);
        dp[0][-nums[0] + 1000] = 1;
        dp[0][nums[0] + 1000] = 1;
		// For the 0 case
        if (!nums[0]) dp[0][nums[0] + 1000]++;
        return findWays(nums, S, nums.size() - 1);
    }
};


//DP in python
class Solution:
    def findTargetSumWays(self, nums, S):
        index = len(nums) - 1
        curr_sum = 0
        self.memo = {}
        return self.dp(nums, S, index, curr_sum)
        
    def dp(self, nums, target, index, curr_sum):
        if (index, curr_sum) in self.memo:
            return self.memo[(index, curr_sum)]
        
        if index < 0 and curr_sum == target:
            return 1
        if index < 0:
            return 0 
        
        positive = self.dp(nums, target, index-1, curr_sum + nums[index])
        negative = self.dp(nums, target, index-1, curr_sum + -nums[index])
        
        self.memo[(index, curr_sum)] = positive + negative
        return self.memo[(index, curr_sum)]
