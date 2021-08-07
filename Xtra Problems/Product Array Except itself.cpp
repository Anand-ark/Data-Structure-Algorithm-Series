/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
*/
SOLUTION : APPROACH 1
-------------------------
Approach: Create two extra space, i.e. two extra arrays to store the product of all the array elements from start, up to that index 
and another array to store the product of all the array elements from the end of the array to that index. 
To get the product excluding that index, multiply the prefix product up to index i-1 with the suffix product up to index i+1.
  
SOLUTION : APPROACH 2:
-----------------------
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>ans(n,1);
        ans[0]=1;
        for(int i=1;i<n;i++)
        {
            ans[i]=ans[i-1]*nums[i-1];
        }
        int r=1;
        for(int i=n-1;i>=0;i--)
        {
            ans[i]=ans[i]*r;
            r=r*nums[i];
            
        }
        return ans;
        
    }
};
