/*
Given a binary tree, connect the nodes that are at same level. You'll be given an addition nextRight pointer for the same.

Initially, all the nextRight pointers point to garbage values. Your function should set these pointers to point next right for each node.
       10                       10 ------> NULL
      / \                       /      \
     3   5       =>     3 ------> 5 --------> NULL
    / \     \               /  \           \
   4   1   2          4 --> 1 -----> 2 -------> NULL

 

Example 1:

Input:
     3
   /  \
  1    2
Output:
3 1 2
1 3 2
Explanation:The connected tree is
        3 ------> NULL
     /    \
    1-----> 2 ------ NULL
*/

SOLUTION :
-----------
/*
// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node* nextRight;
};
*/
class Solution{
    
    public:
    void connect(Node *root)
    {
        queue<Node*>q;
        q.push(root);
        while(q.size()!=0)
        {
            Node* prev=NULL;
            
            int l=q.size();
            for(int i=0;i<l;i++)
            {
                Node* curr=q.front();
                q.pop();
                if(prev!=NULL)prev->nextRight=curr;
                prev=curr;
                if(curr->left!=NULL)q.push(curr->left);
                if(curr->right!=NULL)q.push(curr->right);
            }
            prev->nextRight=NULL;
        }
    }    
      
};
