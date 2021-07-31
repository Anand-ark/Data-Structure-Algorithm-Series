/*
Given a binary tree, find if it is height balanced or not. 
A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 

A height balanced tree
        1
     /     \
   10      39
  /
5

An unbalanced tree
        1
     /    
   10   
  /
5

*/
SOLUTION :
-----------
int height(Node *root)
{
    if(root==NULL)return 0;
    int left=height(root->left);
    int right=height(root->right);
    if(left==-1 or right==-1 or abs(left-right)>1)return -1;
    return max(left,right)+1;
    
}
bool isBalanced(Node *root)
{
    if(height(root)<0)return false;
    else return true;
}
