/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
*/
SOLUTION :
-------------
class Solution {
public:
    bool pairs(char a1,char a2)
    {
        if(a1 == '(' and a2 == ')') return true;
        else if(a1 == '{' and a2 == '}') return true;
        else if(a1 == '[' and a2 == ']') return true;
         return false;
    }
    bool isValid(string str) 
    {
        stack<char>s;
        for(int i =0;i<str.length();i++)
        {
            if(str[i] == '(' or str[i] == '{' or str[i] == '[')s.push(str[i]);
            else if(str[i] == ')' or str[i] == '}' or str[i] == ']')
            {
                if(s.empty() or pairs(s.top(),str[i])==false)return false;
                else s.pop();
            }
        }
        if(s.empty())return true;
        else return false;
    }
        
        
};
