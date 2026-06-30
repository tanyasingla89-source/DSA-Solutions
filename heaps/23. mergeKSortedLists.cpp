class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        for(auto node:lists)
        {
            if(node) pq.push({node->val,node});
        }
        ListNode* dummy=new ListNode(0);
        ListNode* tail=dummy;
        while(!pq.empty())
        {
            auto top=pq.top();
            pq.pop();
            ListNode* node=top.second;
            tail->next=node;
            tail=tail->next;
            if(node->next)
            {
                pq.push({node->next->val,node->next});
            }

        }
        return dummy->next;
    }
};
