/*
1283. Find the Smallest Divisor Given a Threshold
Given an array of integers nums and an integer threshold, we will choose a positive integer divisor and divide all the array by it and sum the result of the division. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

It is guaranteed that there will be an answer.

 

Example 1:

Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
If the divisor is 4 we can get a sum to 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 
Example 2:

Input: nums = [2,3,5,7,11], threshold = 11
Output: 3
Example 3:

Input: nums = [19], threshold = 5
Output: 4
 

Constraints:

1 <= nums.length <= 5 * 10^4
1 <= nums[i] <= 10^6
nums.length <= threshold <= 10^6
*/

//binary search
//Runtime: 88 ms, faster than 11.41% of C++ online submissions for Find the Smallest Divisor Given a Threshold.
//Memory Usage: 20.1 MB, less than 100.00% of C++ online submissions for Find the Smallest Divisor Given a Threshold.
class Solution {
public:
    bool possible(vector<int> &nums, int threshold, int div) {
        int sum = 0;
        for(auto &n : nums) {
            sum += ceil(n/double(div));
        }
        return sum <= threshold;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start = 1, end = pow(10,6);
        while(start < end) {
            int mid = start + (end-start)/2;
            if(possible(nums, threshold, mid))
                end = mid;
            else
                start = mid + 1;
        }
        return start;
    }
};