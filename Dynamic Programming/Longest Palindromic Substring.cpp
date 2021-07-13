/*Given a string s, return the longest palindromic substring in s.

Example 1:
Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"

Example 3:
Input: s = "a"
Output: "a"

Example 4:
Input: s = "ac"
Output: "a"

APPROACH 1: Time Complexity -> O(N^3), Space Complexity -> O(1)
----------------------------------------------------------------
The simple approach is to check each substring whether the substring is a palindrome or not.

APPROACH 2: Time Complexity -> O(N^2), Space Complexity -> O(N^2)
-------------------------------------------------------------------
Using dynamic prograaming as we can Maintain a boolean table[n][n] that is filled in bottom up manner.

APPROACH 3: Time Complexity -> O(N^2), Space Complexity -> O(1)
-------------------------------------------------------------------
The idea is to generate all even length and odd length palindromes and keep track of the longest palindrome seen so far.
To generate odd length palindrome, Fix a centre and expand in both directions for longer palindromes, i.e. fix i (index) 
as center and two indices as i1 = i+1 and i2 = i-1

APPROACH 4: Time Complexity -> O(N), Space Complexity -> O(N)
-------------------------------------------------------------------
Using Manacher Algorithm

-----------------------
SOLUTION : APPROACH 2
-----------------------
*/
class Solution {
public:
    string longestPalindrome(string s) 
    {
        int g,i,j,start=0,end=0,maxlen=0;
        int n=s.length();
        int mxg=n,mxj=n;
        //if(n==1)return s;
        int dp[n][n];
        for(g=0;g<n;g++)
        {
            for(i=0,j=g;j<n;i++,j++)
            {
                if(g==0)dp[i][j]=1;
                else if(g==1)
                {
                    if(s[i]==s[j])dp[i][j]=1;
                    else dp[i][j]=0;
                }
                else
                {
                    if(s[i]==s[j] and dp[i+1][j-1]==1)dp[i][j]=1;
                    else dp[i][j]=0;
                }
                if(dp[i][j]==1)
                {
                    if(j-g>=maxlen)
                    {
                        //maxlen=j-g;
                        start=j-g;
                        end=j;
                    }
                }
            }
        }
        return s.substr(start,end-start+1);
        
    }
};
/*
-------------------------
SOLUTION : APPROACH 3
-------------------------
*/
class Solution {
public:
    string longestPalindrome(string s) 
    {
        int start=0,end=0,len=0;
        if(s.length()<=1)return s;
        int res=0;
        for(int i=0;i<s.length();i++)
        {
            int len1=expandcenter(s,i,i); //handle aca type
            int len2=expandcenter(s,i-1,i); //handle abb type
            len=max(len1,len2);
            if(len>res)
            {
                res=len;
                start=i-len/2;
                end=len;
                
                
            }
        }
        return s.substr(start,end);
    }
    int expandcenter(string str,int i,int j)
    {
        while(i>=0 and j<str.length() and str[i]==str[j])
        {
            i--;
            j++;
        }
        return j-i-1;
        
    }
};
