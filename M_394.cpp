/*
394. Decode String
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*/

//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Decode String.
//Memory Usage: 6.9 MB, less than 100.00% of C++ online submissions for Decode String.

class Solution {
public:
	// if  multiplier is zero, then empty string is output 
    string mulString(string s, int x) {
        string n = "";
        for(int i=0; i<x;i++) {
            n += s;
        }
        return n;
    }
    bool is_num(char c) {
        return c>='0' && c<='9';
    }
    string decodeString(string s) {
	    // which stores multiplier
        stack<int> mul_st;
		// stack which stores current state of string
        stack<string> str_st;
        string curr = "";
        for(int i=0;i<s.length();i++) {
            if(is_num(s[i])) {
			    // number may be more than 1 digit
                string num = ""+ string(1, s[i]);
                i++;
				// breaks when index is at '['
                while(is_num(s[i])) {
                    num += string(1, s[i]);
                    i++;
                }
                mul_st.push(atoi(num.c_str()));
                str_st.push(curr);
                curr = "";
            } else if(s[i] == ']') {
				// pop multiplier and 
                curr = mulString(curr, mul_st.top());
                mul_st.pop();
                curr = str_st.top() + curr;
                str_st.pop();
            } else {
				//build string in current parenthesis
                curr += string(1, s[i]);
            }
        }
        return curr;
    }
};