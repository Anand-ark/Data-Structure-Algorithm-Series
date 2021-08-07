/*
Given an array containing positive and negative numbers. The array represents checkpoints from one end to other end of street. Positive and negative values represent amount of energy at that checkpoint. Positive numbers increase the energy and negative numbers decrease. Find the minimum initial energy required to cross the street such that Energy level never becomes 0 or less than 0.

Note :  The value of minimum initial energy required will be 1 even if we cross street successfully without loosing energy to less than and equal to 0 at any checkpoint. The 1 is required for initial check point.

 

Example 1:

Input
N = 5
A[] = {4, -10, 4, 4, 4}
Output
7
Explanation
By having an initial energy of 7 we can
make sure that all the checkpoints are
visited and the fuel never reaches 0
or less value.
 

Example 2:

Input
N = 5
A[] = {3, 5, 2, 6, 1}
Output
1
Explanation
We need at least 1 initial energy
to reach first checkpoint.
*/
SOLUTION :
-------------
class Solution{
    public:
    int minEnergy(int a[], int n)
    {
        int mn_energy=0;
        int curr_energy=0;
        bool flag=0;
        for(int i=0;i<n;i++)
        {
            curr_energy+=a[i];
            if(curr_energy<=0)
            {
                mn_energy+=abs(curr_energy)+1;
                curr_energy=1;
                flag=1;
            }
        }
        if(flag==1)return mn_energy;
        else return 1;
    }
};
