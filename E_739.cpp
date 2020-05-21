/*
739. Daily Temperatures
Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].
*/


//Runtime: 124 ms, faster than 78.99% of C++ online submissions for Daily Temperatures.
//Memory Usage: 37.4 MB, less than 8.00% of C++ online submissions for Daily Temperatures.
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> result(T.size());
        stack<int> st;
        int s = T.size();
        for (int i = 0; i<s; i++){
            while (!st.empty() && T[st.top()] < T[i]){
                result[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
};