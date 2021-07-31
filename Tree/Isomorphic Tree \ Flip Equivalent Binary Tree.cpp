/*
Given two Binary Trees. Check whether they are Isomorphic or not.

Note: 
Two trees are called isomorphic if one can be obtained from another by a series of flips, i.e. by swapping left and right children of several nodes. 
Any number of nodes at any level can have their children swapped. Two empty trees are isomorphic.
For example, the following two trees are isomorphic with the following sub-trees flipped: 2 and 3, NULL and 6, 7 and 8.
ISomorphicTrees

Example 1:

Input:
 T1    1     T2:   1
     /   \        /  \
    2     3      3    2
   /            /
  4            4
Output: false

Example 2:

Input:
T1    1     T2:    1
    /  \         /   \
   2    3       3     2
  /                    \
  4                     4
Output: true

*/

SOLUTION :
-----------
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) 
    {
        if(root1==NULL and root2==NULL) return true;
        if(root1==NULL or root2==NULL)return false;
        bool l1=false,r1=false;
        bool l2=false,r2=false;
        if(root1->val!=root2->val) return false;
        l1=flipEquiv(root1->left,root2->left);
        r1=flipEquiv(root1->right,root2->right);
        l2=flipEquiv(root1->left,root2->right);
        r2=flipEquiv(root1->right,root2->left);
        return (l1 & r1) or (l2 & r2);
    }
};
