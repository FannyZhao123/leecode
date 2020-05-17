/*
71. Simplify Path
Given an absolute path for a file (Unix-style), simplify it. Or in other words, convert it to the canonical path.

In a UNIX-style file system, a period . refers to the current directory. Furthermore, a double period .. moves the directory up a level.

Note that the returned canonical path must always begin with a slash /, and there must be only a single slash / between two directory names. The last directory name (if it exists) must not end with a trailing /. Also, the canonical path must be the shortest string representing the absolute path.

Example 1:
Input: "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.

Example 2:
Input: "/../"
Output: "/"
Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.

Example 3:
Input: "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.

Example 4:
Input: "/a/./b/../../c/"
Output: "/c"

Example 5:
Input: "/a/../../b/../c//.//"
Output: "/c"

Example 6:
Input: "/a//b////c/d//././/.."
Output: "/a/b/c"
*/

//using stack
//Runtime: 12 ms, faster than 49.49% of C++ online submissions for Simplify Path.
//Memory Usage: 8.7 MB, less than 100.00% of C++ online submissions for Simplify Path.
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> folders;
        string s="";
        int l=path.length();
        for(int i=1;i<=l;++i){
            if(path[i]=='/' || i==l){
                if(s==".."){
                    if(!folders.empty()) 
                        folders.pop();
                }
                else if(s!="" && s!=".") folders.push(s);
                s="";
            }
            else s.push_back(path[i]);
        }
        if(folders.empty())
            return "/";
        string ans;
        while(!folders.empty()){
            ans="/"+folders.top()+ans;
            folders.pop();
        }
        return ans;
    }
};



