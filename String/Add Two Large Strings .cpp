/*
Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). 
You must also not convert the inputs to integers directly.

Example 1:
Input: num1 = "11", num2 = "123"
Output: "134"

Example 2:
Input: num1 = "456", num2 = "77"
Output: "533"
*/
---------------------------------------------------------------------
APPROACH 1 : Reversing Both the Strings and Perform Simple Addition
Time Complexity : O(n1 + n2),  Auxiliary Space: O(max(n1, n2))
---------------------------------------------------------------------
SOLUTION :
-----------
class Solution {
public:
    string addStrings(string A, string B) 
    {
        string x=A,y=B;
        if(A.length()>B.length())
        {
            A=y;
            B=x;
        }
        reverse(A.begin(),A.end());
        reverse(B.begin(),B.end());
        string ans="";
        int carry=0;
        int n1=A.length();
        int n2=B.length();
        for(int i=0;i<n1;i++)
        {
            int sum=((A[i]-'0') + (B[i]-'0')+ carry);
            ans.push_back(sum%10+'0');
            carry=sum/10;
        }
        for(int i=n1;i<n2;i++)
        {
            int sum=((B[i]-'0')+carry);
            ans.push_back(sum%10+'0');
            carry=sum/10;
        }
        if(carry)ans.push_back(carry+'0');
        reverse(ans.begin(),ans.end());
        return ans;        
        
        
    }
};
-----------------------------------------------------------------------------
APPROACH 2 : Without Reversing Both the Strings and Perform Simple Addition
Time Complexity : O(n1 + n2),  Auxiliary Space: O(max(n1, n2))
-----------------------------------------------------------------------------

SOLUTION :
----------
class Solution {
public:
    string addStrings(string num1, string num2) 
    {
        if(num1.length()>num2.length())swap(num1,num2);
        string ans;
        int n=num1.length();
        int m=num2.length();
        int diff=m-n;
        int carry=0;
        for(int i=n-1;i>=0;i--)
        {
            int sum=num1[i]-'0'+num2[i+diff]-'0'+carry;
            ans.push_back(sum%10+'0');
            carry=sum/10;
        }
        for(int i=diff-1;i>=0;i--)
        {
            int sum=(num2[i]-'0')+carry;
            ans.push_back(sum%10+'0');
            carry=sum/10;            
        }
        if(carry==1)ans.push_back(carry+'0');
        reverse(ans.begin(),ans.end());
        return ans;
        
        
    }
};

