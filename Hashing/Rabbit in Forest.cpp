/*
There is a forest with an unknown number of rabbits. We asked n rabbits "How many rabbits have the same color as you?" and collected the answers in 
an integer array answers where answers[i] is the answer of the ith rabbit.

Given the array answers, return the minimum number of rabbits that could be in the forest.

 

Example 1:

Input: answers = [1,1,2]
Output: 5
Explanation:
The two rabbits that answered "1" could both be the same color, say red.
The rabbit that answered "2" can't be red or the answers would be inconsistent.
Say the rabbit that answered "2" was blue.
Then there should be 2 other blue rabbits in the forest that didn't answer into the array.
The smallest possible number of rabbits in the forest is therefore 5: 3 that answered plus 2 that didn't.
Example 2:

Input: answers = [10,10,10]
Output: 11
*/
SOLUTION :
-----------
class Solution {
public:
    int numRabbits(vector<int>& answers) 
    {
        unordered_map<int,int>hash;
        int n=answers.size();
        for(int i=0;i<n;i++)hash[answers[i]]++;
        int sum=0;
        for(auto h:hash)
        {
            sum=sum+ceil(h.second*1.0/(h.first+1.0))*(h.first+1);
            
        }
        return sum;
        
    }
};
