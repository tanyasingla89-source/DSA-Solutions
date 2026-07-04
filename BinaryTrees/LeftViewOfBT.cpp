/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> leftView(Node *root) {
        /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

        queue<pair<Node*,int>>q;
        map<int,int>mp;
        if(root==NULL) return {};
        q.push({root,0});
        while(!q.empty())
        {
            auto top=q.front().first;
            int l=q.front().second;
            q.pop();
            if(mp.count(l)==0){
            mp[l]=top->data;}
            if(top->left!=NULL) q.push({top->left,l+1});
            if(top->right!=NULL) q.push({top->right,l+1});       
        }
        vector<int>ans;
        for(auto it:mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};
        
