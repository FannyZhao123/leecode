/*
890. Find and Replace Pattern
You have a list of words and a pattern, and you want to know which words in words matches the pattern.
A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.
(Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.)
Return a list of the words in words that match the given pattern. 
You may return the answer in any order.

Example 1:

Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation,
since a and b map to the same letter.
 
Note:
1 <= words.length <= 50
1 <= pattern.length = words[i].length <= 20
*/
/*
Using 2 Maps:
If say, the first letter of the pattern is "a", 
and the first letter of the word is "x", then in the permutation, 
"a" must map to "x".

We can write this bijection using two maps: a forward map m1 and a backwards map m2.
m1:"a"→"x" 
m2:"x"→"a"
Then, if there is a contradiction later, we can catch it via one of the two maps. 
For example, if the (word, pattern) is ("aa", "xy"), 
we will catch the mistake in m1 (namely, m1("a")="x"="y"). 
Similarly, with (word, pattern) = ("ab", "xx"), we will catch the mistake in m2.

*/
//Runtime: 4 ms, faster than 88.25% of C++ online submissions for Find and Replace Pattern.
//Memory Usage: 8.3 MB, less than 100.00% of C++ online submissions for Find and Replace Pattern.

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        unordered_map<char,char>mp1,mp2;
        vector<string>res;
        for(int i=0 ; i<words.size() ; i++)
        {
            mp1.clear();mp2.clear();
            string s=words[i]; bool flag=true;
            for(int i=0 ; i<s.length() ; i++)
            {
                if(mp1.find(pattern[i])!=mp1.end() and mp1[pattern[i]]!=s[i]) {flag=false;break;}
                if(mp2.find(s[i])!=mp2.end() and mp2[s[i]]!=pattern[i]) {flag=false;break;}
                mp1[pattern[i]]=s[i]; mp2[s[i]]=pattern[i];
            }
            if(flag) res.push_back(s);
        }
        return res;
    }
};