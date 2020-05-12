/*
763. Partition Labels
A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
Note:

S will have length in range [1, 500].
S will consist of lowercase letters ('a' to 'z') only.
*/
//Runtime: 8 ms, faster than 52.40% of C++ online submissions for Partition Labels.
//Memory Usage: 6.9 MB, less than 100.00% of C++ online submissions for Partition Labels.
class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char,int> map;
        vector<int> ans;
        if(S.size()==0)return ans;
        for(int i=0;i<S.size();i++)
            map[S[i]]=i;
        int maxindex=0,lastindex=0;
        for(int i=0;i<S.size();i++)
        {
            maxindex=max(maxindex,map[S[i]]);
            if(i==maxindex)
            {
                ans.push_back(maxindex-lastindex+1);
                lastindex=i+1;
            }
        }
        return ans;
    }
};