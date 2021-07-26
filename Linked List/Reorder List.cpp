/*
Given a linked list. arrange the linked list in manner of alternate first and last element.

Examples: 

Input : 1->2->3->4->5->6->7->8
Output :1->8->2->7->3->6->4->5

Input :10->11->15->13
Output :10->13->11->15

METHOD 1: (Using Dequeue)
Create an empty deque 
Insert all element from the linked list to the deque 
Insert the element back to the linked list from deque in alternate fashion i.e first then last and so on 
Time Complexity : O(N) , Space Complexity : O(N)

SOLUTION METHOD 1
-------------------
void arrange(struct Node* head)
{
    struct Node* temp = head;
    deque<int> d; // defining a deque
 
    // push all the elements of linked list in to deque
    while (temp != NULL) 
    {
        d.push_back(temp->data);
        temp = temp->next;
    }
    int i = 0;
    temp = head;
    while (!d.empty()) 
    {
        if (i % 2 == 0) 
        {
            temp->data = d.front();
            d.pop_front();
        }
        else 
        {
            temp->data = d.back();
            d.pop_back();
        }
        i++;
        temp = temp->next; // increase temp
    }
}
*/

METHOD 2:
Find the middle point using tortoise and hare method.
Split the linked list into two halves using found middle point in step 1.
Reverse the second half.
Do alternate merge of first and second halves.
Time Complexity : O(N) , Space Complexity : O(1)

SOLUTION METHOD 2:
--------------------
class Solution {
public:
    void reorderList(ListNode* head) 
    {
        ListNode *slow=head,*fast=head;
        //find middle to split
        while(fast!=NULL and fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *head1=head;
        ListNode *head2=slow->next;
        slow->next=NULL;
        //reverse linked list
        ListNode *prev=NULL,*curr=head2,*next=NULL;
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head2=prev;
        //now rearrange
        ListNode *dummy=new ListNode(0);
        ListNode *res=dummy;
        while(head1!=NULL or head2!=NULL)
        {
            if(head1!=NULL)
            {
                res->next=head1;
                res=res->next;
                head1=head1->next;
                
            }
            if(head2!=NULL)
            {
                res->next=head2;
                res=res->next;
                head2=head2->next;               
            }
            
        }
        head=dummy->next;        
    }
};
