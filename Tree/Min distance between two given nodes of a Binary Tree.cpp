/*
Given a binary tree and two node values your task is to find the minimum distance between them.

Example 1:

Input:
        1
      /  \
     2    3
a = 2, b = 3
Output: 2
Explanation: The tree formed is:
       1
     /   \ 
    2     3
We need the distance between 2 and 3.
Being at node 2, we need to take two
steps ahead in order to reach node 3.
The path followed will be:
2 -> 1 -> 3. Hence, the result is 2. 
*/

SOLUTION :
-----------
Node* lca(Node* root,int y,int z)
{
    if(root==NULL)return NULL;
    if(root->data==y or root->data==z)return root;
    Node* left=lca(root->left,y,z);
    Node* right=lca(root->right,y,z);
    if(left!=NULL and right!=NULL)return root;
    if(left!=NULL)return left;
    else return right;
}
//Distance of Node to Value//
int distrootnode(Node* root,int x)
{
    int dist=-1;
    if(root==NULL)return -1;
    if(root->data==x)return dist+1;
    dist=distrootnode(root->left,x);
    if(dist>=0)return dist+1;
    dist=distrootnode(root->right,x);
    if(dist>=0)return dist+1;
    return dist;
}
/* Should return minimum distance between a and b
   in a tree with given root*/
int findDist(Node* root, int a, int b) 
{
    Node* l=lca(root,a,b);
    int a1=distrootnode(l,a);
    int a2=distrootnode(l,b);
    return a1+a2;
}
