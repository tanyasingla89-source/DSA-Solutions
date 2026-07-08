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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>mp;
        queue<pair<TreeNode*,pair<int,int>>>q;
        vector<vector<int>>ans;
        if(!root) return ans;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            auto top=q.front().first;
            int v=q.front().second.first;
            int l=q.front().second.second;
            q.pop();
            mp[v][l].insert(top->val);
            if(top->left) q.push({top->left,{v-1,l+1}});
            if(top->right) q.push({top->right,{v+1,l+1}});
        }
        for(auto [col,rowval]:mp)
        {
            vector<int>colval;
            for(auto [row,rows]:rowval)
            {
                for(auto val:rows)
                {
                    colval.push_back(val);
                }
            }
            ans.push_back(colval);
        }
        return ans;

    }
};
