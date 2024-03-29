/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

Example 1:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: 1

Example 2:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: 0
*/
SOLUTION: Time Complexity : O(log(n * m))
-------------------------------------------
int Solution::searchMatrix(vector<vector<int> > &A, int B) 
{
    int n=A.size();
    int m=A[0].size();
    int left=0, right=m-1;
    while(left<n and right<m and left>=0 and right>=0)
    {
        if(A[left][right]==B)return 1;
        else if(A[left][right]>B)right--;
        else left++;

    }
    return 0;
}
