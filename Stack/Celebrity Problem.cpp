/*
A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there 
is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means 
ith person knows jth person. Here M[i][i] will always be 0.
Note: Follow 0 based indexing.
 

Example 1:

Input:
N = 3
M[][] = {{0 1 0},
         {0 0 0}, 
         {0 1 0}}
Output: 1
Explanation: 0th and 2nd person both
know 1. Therefore, 1 is the celebrity. 

Example 2:

Input:
N = 2
M[][] = {{0 1},
         {1 0}}
Output: -1
Explanation: The two people at the party both
know each other. None of them is a celebrity.
*/
SOLUTION :
-------------
class Solution {
    public:
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int>st;
        for(int i=0;i<n;i++)st.push(i);
        while(st.size()>=2)
        {
            int i=st.top();
            st.pop();
            int j=st.top();
            st.pop();
            if(M[i][j]==1)
            {
                st.push(j);
                
            }
            else st.push(i);
        }
        int x=st.top();
        for(int i=0;i<n;i++)
        {
            if(i!=x)
            {
                if(M[i][x]==0 or M[x][i]==1)
                {
                    return -1;
                }
            }
        }
        return x;
    }
};
