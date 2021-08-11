/*
1. You are given an array of integers(arr) and a number K.
2. You have to find length of the longest subarray whose sum is divisible by K.
*/
SOLUTION :
-----------
#include <bits/stdc++.h>
using namespace std;

int solve(int A[], int n,int K)
{
    unordered_map<int,int>mp;
    int curr_sum=0,ans=0,rem=0;
    mp[0]=-1;
    for(int i=0;i<n;i++)
    {
        curr_sum+=A[i];
        rem=curr_sum%K;
        if(rem<0)rem+=K;
        if(mp.find(rem)!=mp.end())
        {
            ans=max(ans,i-mp[rem]);
        }
        else mp[rem]=i;
    }
    return ans;
}

int main()
{
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++)cin >> A[i];
    int k;
    cin>>k;
    cout << solve(A, N,k) << endl;
}















