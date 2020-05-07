/*
451. Sort Characters By Frequency
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/
//Runtime: 40 ms, faster than 26.26% of C++ online submissions for Sort Characters By Frequency.
//Memory Usage: 8.6 MB, less than 100.00% of C++ online submissions for Sort Characters By Frequency.
class Solution {
public:    
    string frequencySort(string s) {
        unordered_map<char, int> m;
        priority_queue<pair<int, char>> q;
        string r;
        for (auto a : s) ++m[a]; 
        for (auto it : m) q.push({it.second, it.first});
        for (int i = 0; i < m.size() ; ++i) {
            for(int j  = 0; j < q.top().first; j++){
                r.push_back(q.top().second); 
            }
            q.pop();
        }
        return r;
    }
};