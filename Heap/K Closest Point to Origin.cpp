/*
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).
Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].
Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
Explanation: The answer [[-2,4],[3,3]] would also be accepted.
*/

SOLUTION :
----------
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) 
    {
        typedef pair<int,pair<int,int>>pi;
        priority_queue<pi> heap;
        int n=points.size();
        for(int i=0;i<n;i++)
        {
            heap.push({points[i][0]*points[i][0]+points[i][1]*points[i][1],{points[i][0],points[i][1]}});
            if(heap.size()>K)heap.pop();
        }
        vector<vector<int>>ans;
        while(!heap.empty())
        {
            vector<int>temp;
            int x=heap.top().second.first;
            temp.push_back(x);
            int y=heap.top().second.second;
            temp.push_back(y);
            heap.pop();
            ans.push_back(temp);
        }
        return ans;
        
    }
};
