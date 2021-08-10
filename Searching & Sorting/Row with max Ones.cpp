/*
Given a boolean 2D array of n x m dimensions where each row is sorted. Find the 0-based index of the first row that has the maximum number of 1's.

Example 1:

Input: 
N = 4 , M = 4
Arr[][] = {{0, 1, 1, 1},
           {0, 0, 1, 1},
           {1, 1, 1, 1},
           {0, 0, 0, 0}}
Output: 2
Explanation: Row 2 contains 4 1's (0-based
indexing).

Example 2:

Input: 
N = 2, M = 2
Arr[][] = {{0, 0}, {1, 1}}
Output: 1
Explanation: Row 1 contains 2 1's (0-based
indexing).
*/
SOLUTION :
-----------
class Solution{
public:
    int find(vector<int> nums,int left,int right)
    {
        int index=-1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(nums[mid]==1)
            {
                index=mid;
                right=mid-1;
            }
            else if(nums[mid]<1)left=mid+1;
            else right=mid-1;
        }
        return index;
        
    }
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) 
	{
	    int mx=-1,row=-1;
	    for(int i=0;i<n;i++)
	    {
	        int a=find(arr[i],0,m-1);
	        if(mx<(m-a) and a!=-1)
	        {
	            mx=m-a;
	            row=i;
	        }
	        
	    }
	    return row;
	    
	    // code here
	}

};
