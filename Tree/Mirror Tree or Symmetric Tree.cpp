/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Input: root = [1,2,2,3,4,4,3]
Output: true

Input: root = [1,2,2,null,3,null,3]
Output: false
*/

-----------------
  DFS APPROACH
-----------------
class Solution {
public:
    bool isSymmetric(TreeNode* root) 
    {
        return check(root,root);
        
    }
    bool check(TreeNode* root1,TreeNode* root2)
    {
        if(root1==NULL and root2==NULL) return true;
        if(root1==NULL or root2==NULL) return false;
        bool left=false;
        bool right=false;
        if(root1->val==root2->val)
        {
            left=check(root1->left,root2->right);
            right=check(root1->right,root2->left);
        }
        return left&right;
    }
};
