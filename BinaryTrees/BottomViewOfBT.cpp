/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        queue<pair<Node*,int>>q;
        map<int,int>mp;
        q.push({root,0});
        while(!q.empty())
        {
            auto top=q.front().first;
            int v=q.front().second;
            mp[v]=top->data;
            q.pop();
            if(top->left!=NULL) q.push({top->left,v-1});
            if(top->right!=NULL) q.push({top->right,v+1});
            
        }
        vector<int>ans;
        for(auto x:mp)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};
