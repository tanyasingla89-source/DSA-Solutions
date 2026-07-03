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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        if(root==NULL) return 0;
        q.push({root,0});
        int maxi=0;
        while(!q.empty())
        {
            maxi=max(maxi,q.back().second-q.front().second+1);
            int size=q.size();
            int start=q.front().second;
            for(int i=0;i<size;i++)
            {
                auto top=q.front().first;
                int v=q.front().second;
                q.pop();
                if(top->left!=NULL) q.push({top->left,(long long)2*(v-start)+1});
                if(top->right!=NULL) q.push({top->right,(long long)2*(v-start)+2});
            }
        }
        return maxi;

    }
};
