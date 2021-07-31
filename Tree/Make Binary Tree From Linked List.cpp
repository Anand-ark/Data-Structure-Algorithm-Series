/*
Given a Linked List Representation of Complete Binary Tree. The task is to construct the Binary tree.
Note : The complete binary tree is represented as a linked list in a way where if root node is stored at position i, its left, and right children are stored at position 2*i+1, 2*i+2 respectively.

Example 1:
Input:
N = 5
K = 1->2->3->4->5
Output: 1 2 3 4 5
Explanation: The tree would look like
      1
    /   \
   2     3
 /  \
4   5
Now, the level order traversal of the above tree is 1 2 3 4 5.

Example 2:
Input:
N = 5
K = 5->4->3->2->1
Output: 5 4 3 2 1
Explanation: The tree would look like
     5
   /  \
  4    3
 / \
2    1
Now, the level order traversal of the above tree is 5 4 3 2 1.
*/
SOLUTION :
----------
void convert(Node *head, TreeNode *&root) 
{
    queue<TreeNode*>q;
    //base case
    if(head==NULL)
    {
        root=NULL;
        return;
    }
    root=new TreeNode(head->data);
    q.push(root);
    head=head->next;
    while(head!=NULL)
    {
        TreeNode *parent=q.front();
        q.pop();
        TreeNode  *leftchild=NULL,*rightchild=NULL;
        leftchild=new TreeNode(head->data);
        q.push(leftchild);
        head=head->next;
        if(head!=NULL)
        {
            rightchild=new TreeNode(head->data);
            q.push(rightchild);
            head=head->next;
        }
        parent->left=leftchild;
        parent->right=rightchild;
    }
}
