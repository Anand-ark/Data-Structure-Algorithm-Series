/*
Given the root of a binary tree, imagine yourself standing on the right side of it, 
return the values of the nodes you can see ordered from top to bottom.

Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]

*/
----------------
  DFS APPROACH
-----------------
class Solution {
public:
    vector<int>ans;
    int mx=0;
    void solve(TreeNode *root,int level)
    {
        if(root==NULL)return;
        if(level>mx)
        {
            mx=level;
            ans.push_back(root->val);
        }
        solve(root->right,level+1);
        solve(root->left,level+1);
    }
    vector<int> rightSideView(TreeNode* root) 
    {
        solve(root,1);
        return ans;
    }
};

------------------
  BFS APPROACH 
------------------



