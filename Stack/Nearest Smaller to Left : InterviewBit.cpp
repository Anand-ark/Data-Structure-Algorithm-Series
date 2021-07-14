/*
Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that the element has an index smaller than i.
Return the integar array G such that G[i] contains nearest smaller number than A[i].If no such element occurs G[i] should be -1.
Input 1:
    A = [4, 5, 2, 10, 8]
Output 1:
    G = [-1, 4, -1, 2, 2]
*/

/*
SOLUTION 1 : Time Complexity -> O(N^2)
---------------------------------------
Use two loops: The outer loop picks all the elements one by one. The inner loop looks for the first smaller element for the element picked 
by the outer loop. If a smaller element is found then that element is printed as next, otherwise, -1 is printed.
*/

SOLUTION 2 : Time Complexity -> O(N) (Using Stack)
--------------------------------------------------
vector<int> Solution::prevSmaller(vector<int> &A) 
{
    stack<int>st;
    vector<int>ans;
    for(int i=0;i<A.size();i++)
    {
        if(st.size()==0)ans.push_back(-1);
        else if(st.size()>0 and st.top()<A[i])
        {
            ans.push_back(st.top());
        }
        else if(st.size()>0 and st.top()>=A[i])
        {
            while(!st.empty() and st.top()>=A[i])st.pop();
            if(st.size()==0)ans.push_back(-1);
            else ans.push_back(st.top());
        }
        st.push(A[i]);
    }
    return ans;

}
 
  
