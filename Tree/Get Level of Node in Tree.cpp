/*
Given a Binary Tree and a target key you need to find the level of target key in the given Binary Tree.

           3
         /   \
        2     5
      /   \
     1     4
Key: 4
Level: 3  
Note: if no such key exists then return 0.

Example 1:

Input:
        1
      /   \
     2     3
target = 4
Output: 0
*/

SOLUTION :
-----------
class Solution{
  public:
    // function should return level of the target node
    void solve(Node *root,int level,int &res,int key)
    {
        if(root==NULL)return;
        if(root->data==key)
        {
            res=level;
            return;
        }
        solve(root->left,level+1,res,key);
        solve(root->right,level+1,res,key);
    }
    int getLevel(struct Node *node, int target)
    {
        int ans=0;
        solve(node,1,ans,target);
        return ans;
        
    	//code here
    }
};
