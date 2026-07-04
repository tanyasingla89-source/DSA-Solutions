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
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        q.push(root);
        bool ltor=true;
        while(!q.empty())
        {
            int size=q.size();
            vector<int>l(size);
            for(int i=0;i<size;i++)
            {
                auto top=q.front();
                q.pop();
                int index;
                if(ltor)
                {
                    index=i;
                }
                else
                {
                    index=size-i-1;
                }
                l[index]=top->val;
                if(top->left!=NULL) q.push(top->left);
                if(top->right!=NULL) q.push(top->right);
            }
            ltor=!ltor;
            ans.push_back(l);
        }
        return ans;
    }
};
