/*
Given an array(0-based indexing), you have to find the max sum of i*A[i] where A[i] is the element at index i in the array. The only operation allowed is to rotate(clock-wise or counter clock-wise) the array any number of times.

Example 1:

Input:
N = 4
A[] = {8,3,1,2}
Output: 29
Explanation: Above the configuration
possible by rotating elements are
3 1 2 8 here sum is 3*0+1*1+2*2+8*3 = 29
1 2 8 3 here sum is 1*0+2*1+8*2+3*3 = 27
2 8 3 1 here sum is 2*0+8*1+3*2+1*3 = 17
8 3 1 2 here sum is 8*0+3*1+1*2+2*3 = 11
Here the max sum is 29 
*/

SOLUTION : O(N) Time Complexity
---------------------------------
int max_sum(int A[],int N)
{
    int sum=0,curr_sum=0;
    for(int i=0;i<N;i++)sum+=A[i];
    for(int i=0;i<N;i++)curr_sum+=A[i]*i;
    int res=curr_sum;
    for(int i=1;i<N;i++)
    {
        int next=curr_sum-(sum-A[i-1])+A[i-1]*(N-1);
        curr_sum=next;
        res=max(res,next);
    }
    return res;
//Your code here
}
