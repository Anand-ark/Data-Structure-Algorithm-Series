/*
For Given Number N find if its COLORFUL number or not

Return 0/1

COLORFUL number:

A number can be broken into different contiguous sub-subsequence parts. 
Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. 
And this number is a COLORFUL number, since product of every digit of a contiguous subsequence is different
Example:

N = 23
2 3 23
2 -> 2
3 -> 3
23 -> 6
this number is a COLORFUL number since product of every digit of a sub-sequence are different. 

Output : 1
*/

SOLUTION :
----------
int Solution::colorful(int A) 
{
    string str=to_string(A);
    unordered_set<int>hash;
    for(int i=0;i<str.length();i++)
    {
        long long mu=1;
        for(int j=i;j<str.length();j++)
        {
            mu*=(long long) (str[j]-'0');
            if(hash.find(mu)!=hash.end())return 0;
            hash.insert(mu);

        }
    }
    return 1;
}
