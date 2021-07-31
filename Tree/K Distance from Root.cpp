/*
Given a Binary Tree of size N and an integer K. Print all nodes that are at distance k from root (root is considered at distance 0 from itself). Nodes should be printed from left to right. If k is more that height of tree, nothing should be printed.

For example, if below is given tree and k is 2. Output should be 4 5 6.

          1
       /     \
     2        3
   /         /   \
  4        5    6 
     \
      8
*/
-------------------------
SOLUTION : DFS APPROACH
--------------------------
vector<int> ans;
void solve(struct Node *root,int k)
{
    if(root==NULL or k<0)return;
    if(k==0)
    {
        ans.push_back(root->data);
        return;
    }
    solve(root->left,k-1);
    solve(root->right,k-1);
    
}
vector<int> Kdistance(struct Node *root, int k)
{
    solve(root,k);
    return ans;
}
