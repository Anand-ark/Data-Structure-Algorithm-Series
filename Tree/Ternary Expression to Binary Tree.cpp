/*
Given a string that contains ternary expressions. The expressions may be nested. You need to convert the given ternary expression to a binary Tree and return the root.

Example 1:

Input: a?b:c
Output: a b c
Explanation:
string expression = a?b:c
So the binary tree for the above expression is:
       a  
     /   \   
    b     c
Example 2:

Input: a?b?c:d:e
Output: a b c d e
Explanation:
string expression =  a?b?c:d:e
So the binary tree for the above expression is:
                  a
                /   \
               b     e
             /   \
            c     d
*/

SOLUTION : 
------------
Node *convertExpression(string str,int i)
{
    Node *root=new Node(str[i]);
    if(i==str.length())return NULL;
    i++;
    if(str[i]=='?')
    {
        i++;//skip ?
        root->left=convertExpression(str,i);
    }
    if(str[i]==':')
    {
        i++;//skip :
        root->right=convertExpression(str,i);
    }
    return root;
}
