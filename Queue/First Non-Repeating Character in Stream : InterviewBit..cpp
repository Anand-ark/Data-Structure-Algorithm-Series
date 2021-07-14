/*
Given a string A denoting a stream of lowercase alphabets. You have to make new string B.

B is formed such that we have to find first non-repeating character each time a character is inserted to the stream and 
append it at the end to B. If no non-repeating character is found then append '#' at the end of B.

Input 1:
A = "abadbc"
Output : "aabbdd"

Input 2:
A = "abcabc"
Output : "aaabc#"
*/

SOLUTION :
-----------
string Solution::solve(string A) 
{
    queue<int>q;
    vector<int>v(26,0);
    string ans="";
    for(char c:A)
    {
        q.push(c);
        v[c-'a']++;
        while(!q.empty() and v[q.front()-'a']>1)q.pop();
        if(!q.empty())ans+=q.front();
        else ans+='#';
    }
    return ans;
}
