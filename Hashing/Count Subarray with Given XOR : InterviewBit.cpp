/*
Problem Description

Given an array of integers A and an integer B.

Find the total number of subarrays having bitwise XOR of all elements equals to B.

Input 1:

 A = [4, 2, 2, 6, 4]
 B = 6
Output : 4

Input 2:

 A = [5, 6, 7, 8, 9]
 B = 5
Output : 2
*/

SOLUTION :
------------
int Solution::solve(vector<int> &A, int B) 
{
    unordered_map<int,int>map;
    long long sum=0;
    long long count=0;
    long long xr=0;
    int n=A.size();
    for(int i=0;i<n;i++)
    {
        //sum+=arr[i];
        xr=xr^A[i];
        if(xr==B)count++;
        if(map.find(xr^B)!=map.end())
        {
            count+=map[xr^B];
            map[xr]++;
        }
        else map[xr]++;
    }
    return count;
}
