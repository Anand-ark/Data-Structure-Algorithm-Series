/*
Problem Description

Given an 1D integer array A containing N distinct integers.

Find the number of unique pairs of integers in the array whose XOR is equal to B.

NOTE:

Pair (a, b) and (b, a) is considered to be same and should be counted once.

Input 1:
A = [5, 4, 10, 15, 7, 6]
B = 5
Output : 1
Explanation 1: (10 ^ 15) = 5

Input 2:
A = [3, 6, 8, 10, 15, 50]
B = 5
Output : 2
Explanation 2: (3 ^ 6) = 5 and (10 ^ 15) = 5

APPROACH :
----------
A Simple solution is to traverse each element and check if there’s another number whose XOR with it is equal to x. 
This solution takes O(N^2) time.  An efficient solution to this problem takes O(N) time. 
The idea is based on the fact that arr[i] ^ arr[j] is equal to x if and only if arr[i] ^ x is equal to arr[j]. 
*/
  
SOLUTION :
-----------
int Solution::solve(vector<int> &A, int B) 
{
    int count=0;
    int n=A.size();
    unordered_set<int>hash;
    for(int i=0;i<n;i++)
    {
        if(hash.find(A[i]^B)!=hash.end())
        {
            count++;
        }
        hash.insert(A[i]);
    }
    return count;
}
  
