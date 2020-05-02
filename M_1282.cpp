/*
1282. Group the People Given the Group Size They Belong To
There are n people whose IDs go from 0 to n - 1 and each person belongs exactly to one group. Given the array groupSizes of length n telling the group size each person belongs to, return the groups there are and the people's IDs each group includes.

You can return any solution in any order and the same applies for IDs. Also, it is guaranteed that there exists at least one solution. 

Example 1:

Input: groupSizes = [3,3,3,3,3,1,3]
Output: [[5],[0,1,2],[3,4,6]]
Explanation: 
Other possible solutions are [[2,1,6],[5],[0,4,3]] and [[5],[0,6,2],[4,3,1]].

Example 2:

Input: groupSizes = [2,1,3,3,3,2]
Output: [[1],[0,5],[2,3,4]]
 

Constraints:

groupSizes.length == n
1 <= n <= 500
1 <= groupSizes[i] <= n
*/

//Runtime: 24 ms, faster than 91.96% of C++ online submissions for Group the People Given the Group Size They Belong To.
//Memory Usage: 12.9 MB, less than 100.00% of C++ online submissions for Group the People Given the Group Size They Belong To.
class Solution {
public:
    vector<int> get_new_goup (vector<int>& groupSizes, int g){
        vector<int> new_group;
        int temp = groupSizes[g];
        for (int i = 0; i < groupSizes.size(); i++){
            if (new_group.size() == temp) break;
            if (groupSizes[i] == temp){
                new_group.push_back(i);
                groupSizes[i] = -1;
            }
        }
        return new_group;
    }
    
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> result;
        for (int i = 0; i < groupSizes.size(); i++){
            if (groupSizes[i] != -1){
                result.push_back(get_new_goup (groupSizes, i));
            }
        }
        return result;
    }
};