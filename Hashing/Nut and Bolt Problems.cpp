/*
Given a set of N nuts of different sizes and N bolts of different sizes. There is a one-one mapping between nuts and bolts. Match nuts and bolts efficiently.

Comparison of a nut to another nut or a bolt to another bolt is not allowed. It means nut can only be compared with bolt and bolt can only be compared with nut to see which one is bigger/smaller.
The elements should follow the following order ! # $ % & * @ ^ ~ .

Example 1:

Input: 
N = 5
nuts[] = {@, %, $, #, ^}
bolts[] = {%, @, #, $ ^}
Output: 
# $ % @ ^
# $ % @ ^
Example 2:

Input: 
N = 9
nuts[] = {^, &, %, @, #, *, $, ~, !}
bolts[] = {~, #, @, %, &, *, $ ,^, !}
Output: 
! # $ % & * @ ^ ~
! # $ % & * @ ^ ~
*/
SOLUTION :
-----------
class Solution{
public:	

	void matchPairs(char nuts[], char bolts[], int n) 
	{
	    unordered_map<char,int>hash;
	    for(int i=0;i<n;i++)hash[nuts[i]]=i;
	    for(int i=0;i<n;i++)
	    {
	        if(hash.find(nuts[i])!=hash.end())
	        {
	            nuts[i]=bolts[i];
	        }
	    }
	    // code here
	}

};
