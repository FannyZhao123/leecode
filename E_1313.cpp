/*
1313. Decompress Run-Length Encoded List
We are given a list nums of integers representing a list compressed with run-length encoding.

Consider each adjacent pair of elements [freq, val] = [nums[2*i], nums[2*i+1]] (with i >= 0).  For each such pair, there are freq elements with value val concatenated in a sublist. Concatenate all the sublists from left to right to generate the decompressed list.

Return the decompressed list.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [2,4,4,4]
Explanation: The first pair [1,2] means we have freq = 1 and val = 2 so we generate the array [2].
The second pair [3,4] means we have freq = 3 and val = 4 so we generate [4,4,4].
At the end the concatenation [2] + [4,4,4] is [2,4,4,4].
Example 2:

Input: nums = [1,1,2,3]
Output: [1,3,3]
 

Constraints:

2 <= nums.length <= 100
nums.length % 2 == 0
1 <= nums[i] <= 100
*/

// Runtime: 80 ms, faster than 5.43% of C++ online submissions for Decompress Run-Length Encoded List.
// Memory Usage: 11.6 MB, less than 100.00% of C++ online submissions for Decompress Run-Length Encoded List.
class Solution {
public:
    vector<int> decoding (vector<int>& two_nums){
        vector <int> result;
        for (int i = two_nums[0]; i > 0; i--){
            result.push_back(two_nums[1]);
        }
        return result;
    }
    
    vector<int> decompressRLElist(vector<int>& nums) {
        vector <int> result;
        
        vector <int> temp2;
        vector<int>::iterator it;
        
        for (int i = 0; i < nums.size()/2 ; i++){
            vector <int> temp;
            temp.push_back(nums[2*i]);
            temp.push_back(nums[2*i+1]);
            it = result.end();
            temp2 = decoding(temp);
            result.insert(it, temp2.begin(), temp2.end());
        }
        return result;
    }
};


// much better solution 
//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Decompress Run-Length Encoded List.
//Memory Usage: 10.2 MB, less than 100.00% of C++ online submissions for Decompress Run-Length Encoded List.
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> answer;
        for(int i=0;i<nums.size();i+=2){
            while(nums[i]--){
                answer.push_back(nums[i+1]);
            }
        }
        return answer;
    }
};
