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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* head    = nullptr;  // fix 1 — LL not vector
        ListNode* current = nullptr;
        while(temp1!=NULL && temp2!=NULL)
        {
            int sum=0;
            sum=temp1->val+temp2->val+carry;
            carry=sum/10;
            sum=sum%10;
            if(head == nullptr) { head = new ListNode(sum); current = head; }
            else { current->next = new ListNode(sum); current = current->next; }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1)
        {
            int sum=0;
            sum=temp1->val+carry;
            carry=sum/10;
            sum=sum%10;
            if(head == nullptr) { head = new ListNode(sum); current = head; }
            else { current->next = new ListNode(sum); current = current->next; }
            temp1=temp1->next;
        }
        while(temp2)
        {
            int sum=0;
            sum=temp2->val+carry;
            carry=sum/10;
            sum=sum%10;
            if(head == nullptr) { head = new ListNode(sum); current = head; }
            else { current->next = new ListNode(sum); current = current->next; }
            temp2=temp2->next;
        }
        if(carry) {  // fix 4 — add carry node if remaining
            current->next = new ListNode(carry);
    }
    return head;
    }
};
