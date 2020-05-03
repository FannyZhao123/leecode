/*
438. Find All Anagrams in a String
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/


/*
Approach 1 :-
Brute force approach in O(n^2) is to generate all the substrings of s having a length same as that of p and checking each one of them to be anagram of p. This results give us TLE as maximum length of input string is 20000.

Approach 2 :-
The next approach can be to generate all the substring in s of length p, sort that substring and compare it with sorted p string, if they are equal than we got one of our index.
This approach first seems to me to be satisfying time constraints, but after carefully looking into it, I understood it als gives TLE as O(n)*(nlogn) * for generating sunstring and sorting it.

Optimized Approach :-
Create a vector pFreq of length 26 and initialize it with 0 ,(26 is choosen ass there are 26 small letter alphabets). Iterate over string p and fill this array accordingly. Now on similar lines create an another array that will contain the freq of characters present in first window of s having a length equal to the length of string p.
Now, in a while loop compare this two array, if they are exactly equal then it will be our answer. Now move this window further in s and keep on comparing.
You can understood properly from the complete code.
*/


//bad solution -- Time Limit Exceeded when s.length() = 20000
class Solution {
public:
    bool same_string (string a, string b){
        for (int i = 0; i < a.length(); i++){
            if (b.find(a[i]) == std::string::npos){
                return false;
            }
            else {
                b.erase(b.find(a[i]), 1);
            }
        }
        if (b.length() == 0) return true;
        else return false;
    }
    
    vector<int> findAnagrams(string s, string p) {
        int l = p.length();
        vector<int> result;
        if (s.length() == 0 || l >s.length() || l > 20100 || s.length()>20100 ){
            return result;
        }
        for (int i = 0; i <= s.length()-l; i++){
            if (same_string(p, s.substr(i, l))){
                result.push_back(i);
            }
        }
        return result;
    }
};



//good solution
//Runtime: 24 ms, faster than 97.64% of C++ online submissions for Find All Anagrams in a String.
//Memory Usage: 8.3 MB, less than 100.00% of C++ online submissions for Find All Anagrams in a String.
class Solution {
public:
    vector<int> findAnagrams(const string &s, const string &p) {
        if (p.empty() || p.size() > s.size())
            return {};
        
        array<int, 'z'-'a' + 1> pa{}, sa{};
              
        for (size_t i = 0; i < p.size(); ++i)
        {
            pa[p[i]-'a']++;
            sa[s[i]-'a']++;
        }
        
        vector<int> ret;
        int i = 0;
        for (;;)
        {
            if (pa == sa)
                ret.push_back(i);
            
            sa[s[i]-'a']--;
            i++;
            if (i + p.size() - 1 == s.size())
                break;
            
            sa[s[i+p.size() - 1]-'a']++;
        }
        return ret;            
    }
};