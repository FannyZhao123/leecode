/*
1347. Minimum Number of Steps to Make Two Strings Anagram
Given two equal-size strings s and t. In one step you can choose any character of t and replace it with another character.

Return the minimum number of steps to make t an anagram of s.

An Anagram of a string is a string that contains the same characters with a different (or the same) ordering.

 

Example 1:

Input: s = "bab", t = "aba"
Output: 1
Explanation: Replace the first 'a' in t with b, t = "bba" which is anagram of s.
Example 2:

Input: s = "leetcode", t = "practice"
Output: 5
Explanation: Replace 'p', 'r', 'a', 'i' and 'c' from t with proper characters to make t anagram of s.
Example 3:

Input: s = "anagram", t = "mangaar"
Output: 0
Explanation: "anagram" and "mangaar" are anagrams. 
Example 4:

Input: s = "xxyyzz", t = "xxyyzz"
Output: 0
Example 5:

Input: s = "friend", t = "family"
Output: 4
 

Constraints:

1 <= s.length <= 50000
s.length == t.length
s and t contain lower-case English letters only.
*/

//my answer will pas some test, but will fill when input strings are extramely large
//Time Limit Exceeded
class Solution {
public:
    int minSteps(string s, string t) {
        int steps, removed = 0;
        int l = s.length();
        for (int i = 0; i<l; i++){
            size_t found = t.find(s[i-removed]);
            if (found!=std::string::npos){
                s.erase(s.begin()-removed+i);
                t.erase(found, 1);
                removed++;
            }
            else steps++;
        }
        return steps;
    }
};

//better solution, using a char table
//Runtime: 152 ms, faster than 46.09% of C++ online submissions for Minimum Number of Steps to Make Two Strings Anagram.
//Memory Usage: 16.7 MB, less than 100.00% of C++ online submissions for Minimum Number of Steps to Make Two Strings Anagram.
class Solution {
public:
    int minSteps(string s, string t) {
        int len = s.length();
        vector<int> isInS (26, 0);
        int count = 0;
        for(int i=0; i < len; i++)
          isInS[s[i]-'a']++; 
        for(int i=0; i < len; i++) {
            if(--isInS[t[i] - 'a']<0)
               count++;
        }
        return count;
    }
};

//using hashing
class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>m,m1;
        if(s.size()==0)return 0;
        for(int i=0;i<s.size();i++){m[s[i]]++;m1[t[i]]++;}
        int ans=0;
        
        for(auto i:m1)
        if(m1[i.first]>=m[i.first]) ans+=abs(m1[i.first]-m[i.first]);
        
        return ans;
        
    }
};