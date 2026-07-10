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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        ListNode* first=NULL;
        ListNode* lastend=NULL;
        int count=0;
        int kk=k;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        temp=head;
        int n=count/k;
        bool isfirst=true;
        first=temp;
        while(n)
        {
            first=temp;
            prev=NULL;
            k=kk;
            while(k)
            {
                next=temp->next;
                temp->next=prev;
                prev=temp;
                temp=next;
                k--;
            }
            if(isfirst){head=prev; isfirst=false;}
            else{lastend->next=prev;}
            lastend=first;
            n--;
            
        }
        lastend->next=temp;
        return head;
    }
};
