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

/*
my sloution, it will pass some short tests, but cannot pass the long input test
Test cannot pass:
[10,9,6,4,19,0,41,30,27,15,14,39,33,7,34,17,24,46,2,46]
45
Time Limit Exceeded
*/
class Solution {
public:
    vector<int> symbols = {-1, 1};
    int count, sum = 0;
    
    void DFS (vector<int>& nums, int S, stack<int> s){
        int d = nums.size();
        if ((s.size()==d) && (sum != S)) return;
        if ((s.size()==d) && (sum == S)){
            count ++;
            return;
        }
        for (auto sym:symbols){
            if(s.empty()){
                sum = nums[0]*sym;
                s.push(nums[0]*sym);
            }
            else{
                int curr = nums[s.size()]*sym;
                sum += curr;
                s.push(curr);
            }
            DFS(nums, S, s);
            sum -= s.top();
            s.pop();
        }
        return;
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        stack<int> s;
        vector<int> NUMS;
        int zeros = 0;
        for (int i = 0; i<nums.size(); i++){
            if (nums[i] != 0) NUMS.push_back(nums[i]);
            else zeros ++;
        }
        DFS(NUMS, S, s);
        for (int j = 1; j <= zeros; j++){
            count = 2*count;
        }
        return count;
    }
};

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


//in GO
//Runtime: 60 ms, faster than 70.95% of Go online submissions for Target Sum.
//Memory Usage: 6.4 MB, less than 100.00% of Go online submissions for Target Sum
func findTargetSumWays(nums []int, S int) int {
    n := len(nums)
	dp := map[int]int{0: 1}
	for i := 0; i < n; i++ {
	    dp2 := make(map[int]int)
		for currSum, currCount := range dp {
		    for sign := -1; sign <= 1; sign += 2 {
			    dp2[currSum+sign*nums[i]] += currCount
			}
		}
		dp = dp2
	}
	return dp[S]
}