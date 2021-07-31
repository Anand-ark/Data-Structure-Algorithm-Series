/*
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

*/

---------------------
  BFS APPROACH 
----------------------
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if(root==NULL)return{};

        vector<vector<int>>ans;
        TreeNode*  curr;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            vector<int>v;
            int l=q.size();
            for(int i=0;i<l;i++)
            {
                curr=q.front();
                q.pop();
                v.push_back(curr->val);
                if(curr->left!=NULL)q.push(curr->left);
                if(curr->right!=NULL)q.push(curr->right);
                
            }
            ans.push_back(v);
        }
        return ans;
    }
};
