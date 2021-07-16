/*
Find the largest continuous sequence in a array which sums to zero.

Example:

Input:  {1 ,2 ,-2 ,4 ,-4}
Output: {2 ,-2 ,4 ,-4}

NOTE : If there are multiple correct answers, return the sequence which occurs first in the array.
*/

SOLUTION :
------------
vector<int> Solution::lszero(vector<int> &A) 
{
    vector<int>ans;
    int n=A.size();
    unordered_map<int,int>mp;
    int sum=0,mx=0;
    int start=-1,end=-1;
    mp[0]=-1;
    for(int i=0;i<n;i++)
    {
        sum+=A[i];
        if(mp.find(sum)!=mp.end())
        {
            if(i-mp[sum]>mx)
            {
                mx=i-mp[sum];
                end=i;
                start=mp[sum]+1;

            }
        }
        else mp[sum]=i;
    }
    if(start==-1 and end==-1)return {};
    else 
    {
        for(int i=start;i<=end;i++)ans.push_back(A[i]);
        return ans;
    }
}
