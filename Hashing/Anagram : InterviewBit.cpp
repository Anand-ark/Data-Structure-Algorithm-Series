/*
Given an array of strings, return all groups of strings that are anagrams. Represent a group by a list of integers representing the index in 
the original list. Look at the sample case for clarification.

Anagram : a word, phrase, or name formed by rearranging the letters of another, such as 'spar', formed from 'rasp'

Note:  All inputs will be in lower-case.

Example :

Input : cat dog god tca
Output : [[1, 4], [2, 3]]
cat and tca are anagrams which correspond to index 1 and 4. 

dog and god are another set of anagrams which correspond to index 2 and 3.
*/

SOLUTION :
--------------
vector<vector<int> > Solution::anagrams(const vector<string> &A) 
{
    unordered_map<string,vector<int>>mp;
    vector<vector<int>>ans;
    int n=A.size();
    for(int i=0;i<n;i++)
    {
        string t=A[i];
        sort(t.begin(),t.end());
        mp[t].push_back(i+1);
    }
    for(auto x:mp)
    {
        ans.push_back(x.second);
    }
    return ans;
}
