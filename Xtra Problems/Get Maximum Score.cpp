/*
You are given two sorted arrays of distinct integers nums1 and nums2.

A valid path is defined as follows:

Choose array nums1 or nums2 to traverse (from index-0).
Traverse the current array from left to right.
If you are reading any value that is present in nums1 and nums2 you are allowed to change your path to the other array. (Only one repeated value is considered in the valid path).
Score is defined as the sum of uniques values in a valid path.

Return the maximum score you can obtain of all possible valid paths.

Since the answer may be too large, return it modulo 10^9 + 7

Input: nums1 = [2,4,5,8,10], nums2 = [4,6,8,9]
Output: 30
Explanation: Valid paths:
[2,4,5,8,10], [2,4,5,8,9], [2,4,6,8,9], [2,4,6,8,10],  (starting from nums1)
[4,6,8,9], [4,5,8,10], [4,5,8,9], [4,6,8,10]    (starting from nums2)

Input: nums1 = [1,3,5,7,9], nums2 = [3,5,100]
Output: 109
Explanation: Maximum sum is obtained with the path [1,3,5,100].
*/
SOLUTION :
-----------
class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) 
    {
        long long int mod=1e9+7;
        long long int n=nums1.size();
        long long int m=nums2.size();
        long long int sum1=0,sum2=0,globalsum=0;
        long long int i=0,j=0;
        while(i<n and j<m)
        {
            if(nums1[i]<nums2[j])
            {
                sum1+=nums1[i];
                i++;
            }
            else if (nums1[i]>nums2[j])
            {
                sum2+=nums2[j];
                j++;
            }
            else 
            {
                globalsum+=max(sum1,sum2)+nums1[i];
                sum1=0;
                sum2=0;
                i++;
                j++;
            }
        }
        while(i<n)sum1+=nums1[i],i++;
        while(j<m)sum2+=nums2[j],j++;
        globalsum+=max(sum1,sum2);
        return globalsum%mod;
        
    }
};
