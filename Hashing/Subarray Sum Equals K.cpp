/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
*/
SOLUTION :
-----------
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int cu_sum=0,ans=0;
        unordered_map<int,int>hash;
        hash.insert({0,1});
        for(int i=0;i<nums.size();i++)
        {
            cu_sum+=nums[i];
            if(hash.find(cu_sum-k)!=hash.end())
            {
                ans+=hash[cu_sum-k];
            }
            hash[cu_sum]++;
        }
        return ans;
}
};
