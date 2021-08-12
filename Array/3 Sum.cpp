/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and 
nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []
*/
APPROACH 1 :  Time Complexity -> O(N^3) , Space Complexity ->O(1)
------------------------------------------------------------------
Create three nested loop first loop runs from start to end (loop counter i), second loop runs from i+1 to end (loop counter j) and third loop 
runs from j+1 to end (loop counter k) The counter of these loops represents the index of 3 elements of the triplets.
    
APPROACH 2 :  Time Complexity -> O(N^2) , Space Complexity ->O(1)
------------------------------------------------------------------
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        //set<vector<int>>res;
        int n=nums.size();
        vector<vector<int>>ans;
        for(int i=0;i<n-2;i++)
        {
            //Processing Duplicates
            if (i>0 and nums[i] == nums[i-1])continue;
            int left=i+1;
            int right=n-1;
            while(left<right)
            {
                if(nums[i]+nums[left]+nums[right]==0)
                {
                    vector<int> triplet(3, 0);
                    triplet[0] = nums[i];
                    triplet[1] = nums[left];
                    triplet[2] = nums[right];
                    ans.push_back(triplet);
                    //Removing Duplicates
                    while(left<right and nums[left]==triplet[1])left++;
                    while(left<right and nums[right]==triplet[2])right--;
                }
                else if(nums[i]+nums[left]+nums[right]<0)left++;
                else right--;
            }
        }
        return ans;
        
    }
};
