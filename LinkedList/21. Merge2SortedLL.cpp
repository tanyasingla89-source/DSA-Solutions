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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        ListNode* prev=NULL;
        if(!list1) return list2;
        if(!list2) return list1;
        if(temp1->val<=temp2->val)
            {
                prev=temp1;
                temp1=temp1->next;
            }
            else
            {
                prev=temp2;
                temp2=temp2->next;
            }
            ListNode* root=prev;
        while(temp1!=NULL && temp2!=NULL)
        {
            if(temp1->val<=temp2->val)
            {
                prev->next=temp1;
                prev=temp1;
                temp1=temp1->next;
            }
            else
            {
                prev->next=temp2;
                prev=temp2;
                temp2=temp2->next;
            }
        }
        while(temp2!=NULL)
        {
            prev->next=temp2;
            prev=temp2;
            temp2=temp2->next;
        }
        while(temp1!=NULL)
        {
            prev->next=temp1;
            prev=temp1;
            temp1=temp1->next;
        }
        return root;
    }
};
