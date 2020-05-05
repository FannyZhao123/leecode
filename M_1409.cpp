/*
1409. Queries on a Permutation With Key
Given the array queries of positive integers between 1 and m, you have to process all queries[i] (from i=0 to i=queries.length-1) according to the following rules:

In the beginning, you have the permutation P=[1,2,3,...,m].
For the current i, find the position of queries[i] in the permutation P (indexing from 0) and then move this at the beginning of the permutation P. Notice that the position of queries[i] in P is the result for queries[i].
Return an array containing the result for the given queries.

 

Example 1:

Input: queries = [3,1,2,1], m = 5
Output: [2,1,2,1] 
Explanation: The queries are processed as follow: 
For i=0: queries[i]=3, P=[1,2,3,4,5], position of 3 in P is 2, then we move 3 to the beginning of P resulting in P=[3,1,2,4,5]. 
For i=1: queries[i]=1, P=[3,1,2,4,5], position of 1 in P is 1, then we move 1 to the beginning of P resulting in P=[1,3,2,4,5]. 
For i=2: queries[i]=2, P=[1,3,2,4,5], position of 2 in P is 2, then we move 2 to the beginning of P resulting in P=[2,1,3,4,5]. 
For i=3: queries[i]=1, P=[2,1,3,4,5], position of 1 in P is 1, then we move 1 to the beginning of P resulting in P=[1,2,3,4,5]. 
Therefore, the array containing the result is [2,1,2,1].  
Example 2:

Input: queries = [4,1,2,2], m = 4
Output: [3,1,2,0]
Example 3:

Input: queries = [7,5,5,8,3], m = 8
Output: [6,5,0,7,5]
 

Constraints:

1 <= m <= 10^3
1 <= queries.length <= m
1 <= queries[i] <= m
*/

//Runtime: 12 ms, faster than 93.96% of C++ online submissions for Queries on a Permutation With Key.
//Memory Usage: 8.5 MB, less than 100.00% of C++ online submissions for Queries on a Permutation With Key.
#include <array>
#include <iterator>
class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> result;
        int ql = queries.size();
        vector<int> p1;
        vector<int> p2;
        
        if ( m < 1 || m > 1000 || ql <1 || ql > m){
            throw "Required 1 <= m <= 10^3, 1 <= queries.length <= m";
        }
        
        for(int i = 1; i <= m ; i++){
            p1.push_back(i);
            p2.push_back(i);
        }
        for(int i = 0; i < ql; i++){
            int temp = queries[i];
            cout << temp << endl;
            if(temp >= 1 && temp <= m){
                vector<int>::iterator p;
                p = find (p1.begin(), end(p1), temp);
                int pos = distance(p1.begin(), p);
                result.push_back(pos);
                p2[0] = p1[pos];
                if (pos == 0){
                    continue;
                }
                else if (pos == m-1){
                    copy (begin(p1), begin(p1)+pos, begin(p2)+1);
                }
                else{
                    copy(begin(p1), begin(p1)+pos, begin(p2)+1);
                    
                }
                copy(begin(p2), end(p2), begin(p1));
            }
            else{
                throw "Required 1 <= queries[i] <= m";
            }
        }
        return result;
    }
};