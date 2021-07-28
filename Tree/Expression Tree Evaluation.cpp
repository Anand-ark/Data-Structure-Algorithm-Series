/*
Given a full binary expression tree consisting of basic binary operators (+ , – ,*, /) and some integers, Your task is to evaluate the expression tree.

Example 1:

Input: 
              +
           /     \
          *       -
        /  \    /   \
       5    4  100  20 

Output: 100

Explanation:
((5 * 4) + (100 - 20)) = 100

Example 2:

Input:
            -
          /   \
         4     7

Output: -3

Explanation:
4 - 7 = -3
*/

-------------------
  DFS APPROACH
-------------------
class Solution{
  public:
    int solve(node* root)
    {
        if(root->left==NULL and root->right==NULL)return stoi(root->data);
        int a=solve(root->left);
        int b=solve(root->right);
        if(root->data=="*")return a*b;
        else if(root->data=="+")return a+b;
        else if(root->data=="-")return a-b;
        else return a/b;
        
    }
    int evalTree(node* root) 
    {
        solve(root);
    }
};
