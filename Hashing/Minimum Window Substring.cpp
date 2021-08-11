/*
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in 
t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
*/
SOLUTION :
----------
class Solution {
public:
    string minWindow(string s, string t) 
    {
        unordered_map<int,int>m1;
        unordered_map<int,int>m2;
        int n=s.length();
        int m=t.length();
        int i=0,j=0,res=INT_MAX;
        for(int i=0;i<m;i++)m2[t[i]]++;
        int totalmatch=m;
        string p;
        int match=0;
        while(true)
        {
            bool f1=false,f2=false;
            while(i<n and match<totalmatch)
            {
                m1[s[i]]++;
                if(m1[s[i]]<=m2[s[i]])match++;
                i++;
                f1=true;
            }
            while(j<i and match==totalmatch)
            {
                int ans=i-j;
                if(ans<res)
                {
                    string q;
                    res=ans;
                    for(int x=j;x<i;x++)q+=s[x];
                    p=q;
                    
                }
                if(m1[s[j]]==1)m1.erase(s[j]);
                else m1[s[j]]--;
                if(m1[s[j]]<m2[s[j]])match--;
                j++;
                f1=true;
                
            }
            if(f1==false and f2==false)break;
        }
        return p;
        
        
    }
};
