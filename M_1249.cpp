/*
1249. Minimum Remove to Make Valid Parentheses
Given a string s of '(' , ')' and lowercase English characters. 

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
 
Example 1:
Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.

Example 2:
Input: s = "a)b(c)d"
Output: "ab(c)d"

Example 3:
Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.

Example 4:
Input: s = "(a(b(c)d)"
Output: "a(b(c)d)"
 
Constraints:
1 <= s.length <= 10^5
s[i] is one of  '(' , ')' and lowercase English letters.
*/

//Runtime: 116 ms, faster than 12.92% of C++ online submissions for Minimum Remove to Make Valid Parentheses.
//Memory Usage: 11.8 MB, less than 100.00% of C++ online submissions for Minimum Remove to Make Valid Parentheses.
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> myStack;
        for(int i=0;i<s.length();i++) {
            if(s[i] == ')') {
                if(myStack.empty()) s[i] = '#';       // ')' cannot occur before '(', hence mark it as '#' for later deletion
                else myStack.pop();                      // if ')' and stack is not empty pop the index of '('
            } else if(s[i] == '(') myStack.push(i);     // if '(' push the index to stack
        }
        while(!myStack.empty()) {      // make index of extra '(' as '#' to be removed later
            s[myStack.top()] = '#';
            myStack.pop();
        }
        string ans = "";
        for(char ch : s) {           // remove all '#' characters
            if(ch != '#') ans.push_back(ch);
        }
        return ans;
    }
};
