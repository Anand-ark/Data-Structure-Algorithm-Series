/*
Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.

 

Example 1:

Input:
        3
      /   \
     2     1
Output:
3 1 2
Example 2:

Input:
           7
        /     \
       9       7
     /  \     /   
    8    8   6     
   /  \
  10   9 
Output:
7 7 9 8 8 6 9 10 
*/

SOLUTION :
------------
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        if(root==NULL)return{};

        vector<vector<int>>ans;
        TreeNode* curr;
        bool ltor=true;
        
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int l=q.size();
            vector<int>v(l);
            
            for(int i=0;i<l;i++)
            {
                curr=q.front();
                q.pop();
                if(ltor==true)v[i]=curr->val;
                else v[l-i-1]=curr->val;
                
                if(curr->left!=NULL)q.push(curr->left);
                if(curr->right!=NULL)q.push(curr->right);
                
            }
            ans.push_back(v);
            ltor=!ltor;
        }
        return ans;
        
    }
};
