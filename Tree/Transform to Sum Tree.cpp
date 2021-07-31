/*
Given a Binary Tree of size N , where each node can have positive or negative values. Convert this to a tree where each node contains 
the sum of the left and right sub trees of the original tree. The values of leaf nodes are changed to 0.

Example 1:

Input:
             10
          /      \
        -2        6
       /   \     /  \
     8     -4   7    5

Output:
            20
          /    \
        4        12
       /  \     /  \
     0     0   0    0

Explanation:

           (4-2+12+6)
          /           \
      (8-4)          (7+5)
       /   \         /  \
      0     0       0    0
      
*/

SOLUTION 
----------
int solve(Node *root)
{
    if(root==NULL)return 0;
    int old=root->data;
    int left=solve(root->left);
    int right=solve(root->right);
    root->data=left+right;
    return root->data+old;
    
}
void toSumTree(Node *node)
{
    solve(node);
    // Your code here
}
