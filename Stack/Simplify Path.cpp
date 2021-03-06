/*Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a Unix-style file system, 
convert it to the simplified canonical path.

In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers to the directory up a level, 
and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'. For this problem, 
any other format of periods such as '...' are treated as file/directory names.

The canonical path should have the following format:

The path starts with a single slash '/'.
Any two directories are separated by a single slash '/'.
The path does not end with a trailing '/'.
The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')
Return the simplified canonical path.*/

/*SOLUTION 1: 
-----------
By looking at examples we can see that the above simplification process just behaves like a stack. Whenever we encounter any file’s name, 
we simply push it into the stack. when we come across ” . ” we do nothing. When we find “..” in our path, we simply pop the topmost element 
as we have to jump back to parent’s directory. When we see multiple “////” we just ignore them as they are equivalent to one single “/”.*/

class Solution {
public:
    string simplifyPath(string path) 
    {
        int n = path.length();

        stack<string>st;
        for (int i = 0; i < n; i++) 
        {
            if (path[i] == '/') continue;

            string t = "";
            while (i < n && path[i] != '/') 
            {
                t += path[i];
                i++;
            }

            if (t == ".") continue;
            else if (t == "..") 
            {
                if (!st.empty()) st.pop();
                continue;
            }

            st.push(t);
        }
        if (st.empty()) return "/";
        string ans = "";
        while (!st.empty()) 
        {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
/*
------------
SOLUTION 2:
------------
In Solution 1, the directories so formed, are first pushed into the stack and then the stack is reversed to form the canonical path.
The only optimization here is to reduce the number of stack operations and this can be done by using vectors in place of a stack.*/

class Solution {
public:
    string simplifyPath(string path) 
    {
        int n = path.length();

        vector<string>v;
        for (int i = 0; i < n; i++) 
        {
            if (path[i] == '/') continue;
            string t = "";
            while (i < n && path[i] != '/') 
            {
                t += path[i];
                i++;
            }

            if (t == "." or t==" ") continue;
            else if (t == "..") 
            {
                if(!v.empty())v.pop_back();
            }
            else v.push_back(t);
        }
        string ans="";
        for (auto i : v) ans += "/" + i;
        if (ans == "")return "/";
        return ans;
    }
};


