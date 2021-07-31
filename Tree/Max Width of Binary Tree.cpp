/*
Given a Binary Tree, find the maximum width of it. Maximum width is defined as the maximum number of nodes in any level.
For example, maximum width of following tree is 4 as there are 4 nodes at 3rd level.

          1
       /     \
     2        3
   /    \    /    \
  4    5   6    7
    \
      8
Output : 4

Example 1:
Input:
       1
     /    \
    2      3
Output: 2
*/

SOLUTION :
-----------
long long max(long long a,long long b)
{
    if(a>b)return a;
    return b;
}
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) 
    {
        if(root==NULL) return 0;
        queue<pair<TreeNode*, unsigned int>> q;
        q.push({root,1});
        long long int ans=0;
        while(!q.empty())
        {
            ans = max(ans, q.back().second-q.front().second+1);
            int n=q.size();
            while(n--)
            {
                auto t=q.front();
                q.pop();
                if(t.first->left!=NULL)
                {
                    q.push({t.first->left,2*t.second});
                }
                if(t.first->right!=NULL)
                {
                    q.push({t.first->right,2*t.second+1});
                }
            }
        }
        return ans;
    }
};
