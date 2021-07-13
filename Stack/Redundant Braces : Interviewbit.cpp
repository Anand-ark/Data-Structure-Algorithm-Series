/*
Write a program to validate if the input string has redundant braces?
Return 0/1 
 0 -> NO 1 -> YES 
Input will be always a valid expression
and operators allowed are only + , * , - , /
Example:
((a+b)) has redundant braces so answer will be 1
(a + (a + b)) doesn't have have any redundant braces so answer will be 0
*/

//SOLUTION :
--------------
int Solution::braces(string A) 
{
    stack<int>st;
    int n=A.length();
    for(int i=0;i<n;i++)
    {
        char c=A[i];
        if(c=='(' or c=='+' or c=='-' or c=='/' or c=='*')st.push(A[i]);
        else if(A[i]==')')
        {
            if(st.top()=='(')return 1;
            else 
            {
                while(!st.empty() and st.top()!='(')st.pop();
                st.pop();
            }
        }
    }
    return 0;
}


