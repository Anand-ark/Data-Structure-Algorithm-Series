/*
Given the root of a binary tree, invert the tree, and return its root.

Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

Input: root = [2,1,3]
Output: [2,3,1]
*/

--------------------
  DFS APPROACH
---------------------
class Solution {
public:
    void solve(TreeNode* curr)
    {
        if(curr==NULL)return;
        if(curr->left!=NULL)solve(curr->left);
        if(curr->right!=NULL)solve(curr->right);
        swap(curr->left,curr->right);
        /*TreeNode* temp;
        temp=curr->left;
        curr->left=curr->right;
        curr->right=temp;*/
    }
    TreeNode* invertTree(TreeNode* root) 
    {
        solve(root);
        return root;
    }
};
