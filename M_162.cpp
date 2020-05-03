/*
162. Find Peak Element
A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -∞.

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 1 or 5 
Explanation: Your function can return either index number 1 where the peak element is 2, 
             or index number 5 where the peak element is 6.
Note:

Your solution should be in logarithmic complexity.
*/

//Runtime: 4 ms, faster than 96.13% of C++ online submissions for Find Peak Element.
//Memory Usage: 9.6 MB, less than 6.82% of C++ online submissions for Find Peak Element.
class Solution {
public:
    int loc = 0;
    
    int findPeakElement(vector<int>& nums) {
        int peak = nums.size()/2;
        if ((peak-1 >= 0) && (nums[peak] < nums[peak-1])){
            vector<int> sub(nums.begin(), nums.begin()+peak);
            return findPeakElement(sub);
        }
        else if ((peak+1 < nums.size()) && (nums[peak] < nums[peak+1])){
            vector<int> sub(nums.begin()+(peak+1), nums.end());
            loc += peak;
            loc += 1;
            return findPeakElement(sub);
        }
        else {
            loc += peak;
            return loc;
        }
    }
};

