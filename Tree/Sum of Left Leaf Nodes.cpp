/*
Given a Binary Tree of size N. Find the sum of all the leaf nodes that are left child of their parent of the given binary tree.

Example 1:

Input:
       1
     /   \
    2     3
Output: 2

Example 2:

Input : 
         1
        /  \
       2    3
     /  \     \
    4    5     8 
  /  \        /  \
 7    2      6    9
Output: 13
Explanation:
sum = 6 + 7 = 13
*/

SOLUTION :
------------
void solve(Node *root,int &sum)
{
    if(root==NULL)return;
    if(root->left!=NULL)
    {
        if(root->left->left==NULL and root->left->right==NULL)sum+=root->left->data;
    }
   
    solve(root->left,sum);
    solve(root->right,sum);
}
int leftLeavesSum(Node *root)
{
    int sum=0;
    solve(root,sum);
    return sum;
}
  
