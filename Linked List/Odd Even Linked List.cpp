/*
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices,
and return the reordered list.
The first node is considered odd, and the second node is even, and so on.
Note that the relative order inside both the even and odd groups should remain as it was in the input.
Example 1

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL
Explanation: The first group is of elements at odd position (1,3,5) in the linked list and then the ones at the even position(2,4)
Example 2

Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL
*/
SOLUTION : Time Complexity: O(N), Space Complexity: O(1)
-----------------------------------------------------------
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) 
    {
        if(head==NULL)return head;
        ListNode *odd=head,*even=head->next;
        //ListNode *odd_head=head;
        ListNode *even_head=head->next;
        while(even!=NULL and even->next!=NULL)
        {
            odd->next=odd->next->next;
            even->next=even->next->next;
            odd=odd->next;
            even=even->next;
            
        }
        odd->next=even_head;
        return head;
        
    }
};
