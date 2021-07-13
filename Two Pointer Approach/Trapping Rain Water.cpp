/*Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
  
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water 
(blue section) are being trapped.
  
Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9*/

/*
SOLUTION 1 : Time Complexity : O(N^2) , Space Complexity : 0(N)
----------------------------------------------------------------
Traverse the array from start to end.
For every element, traverse the array from start to that index and find the maximum height (a) and traverse the array from the current index to end, 
and find the maximum height (b).
The amount of water that will be stored in this column is min(a,b) – array[i], add this value to the total amount of water stored

SOLUTION 2 : Time Complexity : O(N) , Space Complexity : 0(N)
----------------------------------------------------------------
Create two arrays left and right of size n. 
Run one loop from start to end. In each iteration update maxleft array
Run another loop from end to start. In each iteration update rightmax array
Traverse the array from start to end.
The amount of water that will be stored in this column is min(a,b) – array[i],(where a = left[i] and b = right[i]) add this value to total amount of water stored*/

class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n=height.size();
        if(n==0)return 0;
        int maxleft[n];
        int maxright[n];
        maxleft[0]=height[0];
        for(int i=1;i<n;i++)
        {
            maxleft[i]=max(maxleft[i-1],height[i]);
        }
        maxright[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            maxright[i]=max(maxright[i+1],height[i]);
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            int x=min(maxleft[i],maxright[i]);
            sum+=(x-height[i]);
        }
        return sum;
        
    }
};

/*
SOLUTION 3 : Time Complexity : O(N) , Space Complexity : 0(1)
----------------------------------------------------------------
Instead of maintaining two arrays of size n for storing the left and a right max of each element, maintain two variables to store the maximum till 
that point. Since water trapped at any element = min(max_left, max_right) – arr[i]. Calculate water trapped on smaller elements out of A[lo] and A[hi] 
first and move the pointers till lo doesn’t cross hi.
*/
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
