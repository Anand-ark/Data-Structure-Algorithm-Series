/*
Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. 
The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and 
ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.
*/

-------------------
  BFS APPROACH
-------------------
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        if(root==NULL)return {};
        queue<pair<int,TreeNode*>>q;
        map<int,vector<int>>m;
        q.push({0,root});
        while(!q.empty())
        {
            set<pair<int,int>>s;
            int l=q.size();
            for(int i=0;i<l;i++)
            {
                pair<int,TreeNode*>p=q.front();
                q.pop();
                s.insert({p.first,p.second->val});
                if(p.second->left!=NULL)q.push({p.first-1,p.second->left});
                if(p.second->right!=NULL)q.push({p.first+1,p.second->right});
            }
            for(auto i:s) m[i.first].push_back(i.second);
        }
        vector<vector<int>>ans;
        for(auto i:m) ans.push_back(i.second);
        return ans;
        
        
    }
};
