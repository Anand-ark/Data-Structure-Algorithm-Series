/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
*/

SOLUTION :
----------
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>res;
        int start=intervals[0][0];
        int end=intervals[0][1];
        for(auto x:intervals)
        {
            if(x[0]>end)
            {
                res.push_back({start,end});
                start=x[0];
                end=x[1];
            }
            else end=max(end,x[1]);
        }
        res.push_back({start,end});
        return res;
        
    }
};
