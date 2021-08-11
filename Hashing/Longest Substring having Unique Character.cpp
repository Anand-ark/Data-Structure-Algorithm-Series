/*
Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
SOLUTION :
------------
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        string str=s;
        int n=s.length();
        unordered_map<char,int>mp;
        int res=0;
        int i=-1;
        int j=-1;
        string ans;
        while(true)
        {
            bool f1=false;
            bool f2=false;
            while(i<n-1)
            {
                f1=true;
                i++;
                mp[str[i]]++;
                if(mp[str[i]]==2)break;
                else res=max(res,i-j);
            }
            while(j<i)
            {
                f2=true;
                j++;
                mp[str[j]]--;
                if(mp[str[j]]==1)break;
                    
                
            }
            if(f1==false and f2==false)break;
        }
        return res;
        
    }
};
