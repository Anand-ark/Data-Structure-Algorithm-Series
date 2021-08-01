/*
Given two binary trees with head reference as T and S having at most N nodes. The task is to check if S is present as subtree in T.
A subtree of a tree T1 is a tree T2 consisting of a node in T1 and all of its descendants in T1.

Example 1:

Input:
T:      1          S:   3
      /   \            /
     2     3          4
   /  \    /
  N    N  4
Output: 1 
Explanation: S is present in T

Example 2:

Input:
T:      26         S:   26
       /   \           /  \
     10     N        10    N
   /    \           /  \
   20    30        20  30
  /  \            /  \
 40   60         40  60
Output: 1 
Explanation: 
S and T are both same. Hence, 
it can be said that S is a subtree 
of T.
*/

SOLUTION : Time Complexity -> O(N^2)
--------------------------------------
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) 
    {
        if(s==NULL and t==NULL)return true;
        if(s==NULL or t==NULL)return false;
        if(isSameTree(s,t)==true)return true;
        bool l=false,r=false;
        l=isSubtree(s->left,t);
        r=isSubtree(s->right,t);
        return l|r;
    }
    bool isSameTree(TreeNode* s, TreeNode* t)
    {
        if(s==NULL and t==NULL)return true;
        if(s==NULL or t==NULL)return false;
        bool l=false;
        bool r=false;
        if(s->val==t->val)
        {
            l=isSameTree(s->left,t->left);
            r=isSameTree(s->right,t->right);
        }
        return l&r;
    }
};
