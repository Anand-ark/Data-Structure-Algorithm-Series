/*
Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 
 

Example 1:

Input:
N = 6
arr[] = {3,0,0,2,0,4}
Output:
10
Explanation: 

Example 2:

Input:
N = 4
arr[] = {7,4,0,9}
Output:
10
Explanation:
Water trapped by above 
block of height 4 is 3 units and above 
block of height 0 is 7 units. So, the 
total unit of water trapped is 10 units.
Example 3:

Input:
N = 3
arr[] = {6,9,9}
Output:
0
Explanation:
No water will be trapped.
*/

SOLUTION :
----------
class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n=height.size();
        int left_mx=0,right_mx=0;
        int low=0,high=n-1;
        int res=0;
        while(low<=high)
        {
            if(height[low]<height[high])
            {
                if(height[low]>left_mx)left_mx=height[low];
                else res+=(left_mx-height[low]);
                low++;
            }
            else
            {
                if(height[high]>right_mx)right_mx=height[high];
                else res+=(right_mx-height[high]);
                high--;
            }
        }
        return res;
        
    }
};
