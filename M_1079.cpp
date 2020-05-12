/*
1079. Letter Tile Possibilities
You have a set of tiles, where each tile has one letter tiles[i] printed on it.  Return the number of possible non-empty sequences of letters you can make.

Example 1:
Input: "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".

Example 2:
Input: "AAABBC"
Output: 188
 
Note:
1 <= tiles.length <= 7
tiles consists of uppercase English letters.
*/
//自己做不出来，直接看的答案
//Runtime: 104 ms, faster than 32.91% of C++ online submissions for Letter Tile Possibilities.
//Memory Usage: 14.3 MB, less than 100.00% of C++ online submissions for Letter Tile Possibilities
class Solution {
public:
    unordered_set<string>res;
    void dfs(string s,string prefix,int st)
    {
        if(prefix.length()>s.length()) return;
        if(prefix.length()>0 and prefix.length()<=s.length()) res.insert(prefix);
        for(int i=st ; i<s.length() ; i++)
        {
            prefix+=s[i];
            swap(s[i],s[st]);
            cout << "s after 1 swap" << " when i = " << i <<" and st = " << st << " : " << s << endl;
            cout << "prefix is :" << prefix<< endl;
            dfs(s,prefix,st+1);
            swap(s[i],s[st]);
            cout << "s after 2 swap" << " when i = " << i <<" and st = " << st << " : " << s << endl;
            prefix.pop_back();
        }
    }
    int numTilePossibilities(string tiles) {
        string prefix;
        dfs(tiles,prefix,0);
        return res.size();
    }
};

/*
Test case: "AAB"
output: 8
stdout:
s after 1 swap when i = 0 and st = 0 : AAB
prefix is :A
s after 1 swap when i = 1 and st = 1 : AAB
prefix is :AA
s after 1 swap when i = 2 and st = 2 : AAB
prefix is :AAB
s after 2 swap when i = 2 and st = 2 : AAB
s after 2 swap when i = 1 and st = 1 : AAB
s after 1 swap when i = 2 and st = 1 : ABA
prefix is :AB
s after 1 swap when i = 2 and st = 2 : ABA
prefix is :ABA
s after 2 swap when i = 2 and st = 2 : ABA
s after 2 swap when i = 2 and st = 1 : AAB
s after 2 swap when i = 0 and st = 0 : AAB
s after 1 swap when i = 1 and st = 0 : AAB
prefix is :A
s after 1 swap when i = 1 and st = 1 : AAB
prefix is :AA
s after 1 swap when i = 2 and st = 2 : AAB
prefix is :AAB
s after 2 swap when i = 2 and st = 2 : AAB
s after 2 swap when i = 1 and st = 1 : AAB
s after 1 swap when i = 2 and st = 1 : ABA
prefix is :AB
s after 1 swap when i = 2 and st = 2 : ABA
prefix is :ABA
s after 2 swap when i = 2 and st = 2 : ABA
s after 2 swap when i = 2 and st = 1 : AAB
s after 2 swap when i = 1 and st = 0 : AAB
s after 1 swap when i = 2 and st = 0 : BAA
prefix is :B
s after 1 swap when i = 1 and st = 1 : BAA
prefix is :BA
s after 1 swap when i = 2 and st = 2 : BAA
prefix is :BAA
s after 2 swap when i = 2 and st = 2 : BAA
s after 2 swap when i = 1 and st = 1 : BAA
s after 1 swap when i = 2 and st = 1 : BAA
prefix is :BA
s after 1 swap when i = 2 and st = 2 : BAA
prefix is :BAA
s after 2 swap when i = 2 and st = 2 : BAA
s after 2 swap when i = 2 and st = 1 : BAA
s after 2 swap when i = 2 and st = 0 : AAB
*/