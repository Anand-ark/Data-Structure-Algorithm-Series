/*
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. 
You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
*/

METHOD 1:
--------------------------------------------------------
-> Traverse all the N elements of the array (Outer loop)
-> At each step, calculate maximum element among next k elements (Inner loop)
-> Store the maximum element of each window in the answer array
-> Return the answer array

Time Complexity: O(N*K) , Space Complexity: O(1)

Pseudo Code :
------------
int[] slidingWindowMaximum(int arr[], int n, int k)
{
    ans = []
    // there are N-k+1 windows
    for (i = 0 to N-k)
    {
        max = arr[i]
        for(j = i to i+k-1)
        {
            if(arr[j] > max)
                max = arr[j]
        }
        ans.append(max)
    }
    return ans
}

METHOD 2: Using Priority Queue ( Max Heap )
-------------------------------------------------------------
Time Complexity: O(N * log K) , Space Complexity: O(N)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        priority_queue<pair<int,int>> maxheap;
        for(int i=0;i<k;i++) maxheap.push({nums[i],i});
        vector<int> res;
        res.push_back(maxheap.top().first);
        for(int i=k;i<nums.size();i++)
        {
            maxheap.push({nums[i],i});
            while(maxheap.top().second+k<=i)maxheap.pop();
            res.push_back(maxheap.top().first);
        }
        return res;
        
    }
};
METHOD 3 : Using Dequeue
-------------------------------------------------------------
Time Complexity: O(N) , Space Complexity: O(k)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        vector<int>vec;
        deque<int>q;
        int i=0;
        if(nums.size()<k)return vec;
        //For the initial K window size we try to store the index which has the maximum element
        while(i<k)
        {
            while(q.size()>0 and nums[i]>nums[q.back()])q.pop_back();
            q.push_back(i);
            i++;
        }
        while(i<nums.size())
        {
            //Adding to the vector the front part coz it has the index of the max ele;  
            vec.push_back(nums[q.front()]);
            //1.Remove elements which are not part of the window (Contraction)
            while((q.size()>0 and (q.front()+k<=i)))q.pop_front();
            //2.Remove elements whcih are part of the window but not useful anymore coz a new element with               
            //greater value has come which will stay longer than others
            while((q.size()>0 and (nums[i]>=nums[q.back()])))q.pop_back();
            q.push_back(i);
            i++;
        }
        vec.push_back(nums[q.front()]);
        return vec;
    }
};

