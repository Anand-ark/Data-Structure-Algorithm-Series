/*
Given a Singly linked list, check if the linked list has loop or not.

METHOD 1: (Using Hashing)
Traverse the list one by one and keep putting the node addresses in a Hash Table. 
At any point, if NULL is reached then return false, and if next of current node points to any 
of the previously stored nodes in Hash then return true. 
Time Complexity : O(N) , Space Complexity : O(N)

METHOD 2: (Floyd Cycle Finding Algorithm)
This is the fastest method and has been described below:  
Traverse linked list using two pointers.
Move one pointer(slow_p) by one and another pointer(fast_p) by two.
If these pointers meet at the same node then there is a loop. If pointers do not meet then linked list doesn’t have a loop.
Time Complexity : O(N) , Space Complexity : O(1)
*/
SOLUTION : METHOD 2: (Floyd Cycle Finding Algorithm)
-----------------------------------------------------
DETECT LOOP IN LINKED LIST
---------------------------
class Solution {
public:
    bool hasCycle(ListNode *head) 
    {
        if(head==NULL) return false;
        ListNode *slow=head,*fast=head;
        while(fast!=NULL and fast->next !=NULL and slow!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)return true;
        }
        return false;
    }
};
-----------------------------
REMOVE LOOP IN LINKED LIST
-----------------------------
class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        Node* slow=head;
        Node* fast=head;
        while(slow!=NULL and fast!=NULL and fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                break;
            }
        }
        if(slow==head)//exception case when last node make cycle with head of Linked List
        {
            while(fast->next!=slow)
            {
                fast=fast->next;
            }
            fast->next=NULL;
        }
        else if(slow==fast)
        {
            slow=head;
            while(slow->next!=fast->next)
            {
                slow=slow->next;
                fast=fast->next;
            }
            fast->next=NULL;
            
        }
    }
};
