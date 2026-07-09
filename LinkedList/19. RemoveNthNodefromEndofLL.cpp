/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return head;
        ListNode* temp=head;
        int count=0;
        while(temp)
        {
            count++;
            temp=temp->next;
        }
        temp=head;
        if(count==n)
        {
            head=temp->next;
        }
        else{
        temp=head;
        while(count-n-1)
        {
            temp=temp->next;
            count--;
        }
        ListNode* t=temp->next->next;
        temp->next=t;
        }
        return head;
    }
};
