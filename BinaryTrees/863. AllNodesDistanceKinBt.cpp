/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void parent(unordered_map<TreeNode*,TreeNode*>&mp,TreeNode* root)
{
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
            auto top=q.front();
            q.pop();
            if(top->left){ mp[top->left]=top; q.push(top->left);}
            if(top->right) {mp[top->right]=top; q.push(top->right);}
        }
    
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>mp;
        parent(mp,root);
        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        visited[target]=true;
        q.push(target);
        int v=0;
        while(!q.empty())
        {
            int size=q.size();
            if(v>=k) break;
            for(int i=0;i<size;i++){
            auto top=q.front();
            q.pop();
            if(top->left && !visited[top->left])
            {
                q.push(top->left);
                visited[top->left]=true;
            }
            if(top->right && !visited[top->right])
            {
                q.push(top->right);
                visited[top->right]=true;
            }
            if(mp[top] && !visited[mp[top]])
            {
                q.push(mp[top]);
                visited[mp[top]]=true;
            }}
            v++;
        }
    
    vector<int>ans;
    while(!q.empty())
    {
        auto top=q.front();
        q.pop();
        ans.push_back(top->val);
    }
    return ans;}
};
