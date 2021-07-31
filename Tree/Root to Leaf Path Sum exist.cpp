/*
Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that 
adding up all the values along the path equals targetSum.

A leaf is a node with no children.
*/

SOLUTION : 
-----------
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) 
    {
        bool left=false;
        bool right=false;
        if(root==NULL)return false;
        if(root->left==NULL and root->right==NULL and sum-root->val==0) return true;
        else 
        {
            left=hasPathSum(root->left,sum-root->val);
            right=hasPathSum(root->right,sum-root->val);
        }
        return left or right;
        
    }
};
