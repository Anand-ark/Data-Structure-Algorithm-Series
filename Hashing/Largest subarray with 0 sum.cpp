/*
Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Example 1:

Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.
*/

SOLUTION :
-----------
int maxLen(int A[], int n)
{
    unordered_map<int,int>hash;
    int curr_sum=0;
    int res=0;
    hash[0]=-1;
    for(int i=0;i<n;i++)
    {
        curr_sum+=A[i];
        if(hash.find(curr_sum)!=hash.end())
        {
            res=max(res,i-hash[curr_sum]);
        }
        else hash[curr_sum]=i;
    }
    return res;
    
}
