/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the 
largest rectangle in the histogram.
  

Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
*/

SOLUTION :
-------------
int Solution::largestRectangleArea(vector<int> &A) 
{
    int n=A.size();
    stack<int>st;
    //left index i.e NSL (next smaller element to left) if not present store -1 
    vector<int>left;
    for(int i=0;i<n;i++)
    {
        if(st.size()==0)left.push_back(-1);
        else if(st.size()>0 and A[st.top()]<A[i])
        {
            left.push_back(st.top());
        }
        else if(st.size()>0 and A[st.top()]>=A[i])
        {
            while(!st.empty() and A[st.top()]>=A[i])st.pop();
            if(st.size()==0)left.push_back(-1);
            else left.push_back(st.top());
        }
        st.push(i);
    }
    //clear stack
    while(!st.empty())st.pop();
    //right index i.e. NSR (next smaller element to right) if not present store n
    vector<int>right;
    for(int i=n-1;i>=0;i--)
    {
        if(st.size()==0)right.push_back(n);
        else if(st.size()>0 and A[st.top()]<A[i])
        {
            right.push_back(st.top());
        }
        else if(st.size()>0 and A[st.top()]>=A[i])
        {
            while(!st.empty() and A[st.top()]>=A[i])st.pop();
            if(st.size()==0)right.push_back(n);
            else right.push_back(st.top());
        }
        st.push(i);
    }
    reverse(right.begin(),right.end());
    //res
    int width,maxarea=0,height;
    for(int i=0;i<n;i++)
    {
        width=right[i]-left[i]-1;
        height=A[i];
        int x=width*height;
        if(maxarea<x)maxarea=x;
    }
    return maxarea;

}

