class Solution {
public:
    TreeNode* markParent(unordered_map<TreeNode*, TreeNode*>& mp,
                    TreeNode* root,int target)
    {
        queue<TreeNode*> q;
        TreeNode* res;
        q.push(root);
        while(!q.empty())
        {
            auto top = q.front();
            if(target==top->val) res=top;
            q.pop();
            if(top->left)
            {
                mp[top->left] = top;
                q.push(top->left);
            }
            if(top->right)
            {
                mp[top->right] = top;
                q.push(top->right);
            }
        }
        return res;
    }
    int amountOfTime(TreeNode* root, int targe)
    {
        unordered_map<TreeNode*, TreeNode*> mp;
        TreeNode* target=markParent(mp, root,targe);
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        visited[target] = true;  // ✅ TreeNode* not int
        q.push(target);          // ✅ TreeNode* not int
        int v = 0;

        while(!q.empty())
        {
            int size = q.size();
            bool flag = false;

            for(int i = 0; i < size; i++)
            {
                auto top = q.front();
                q.pop();

                if(top->left && !visited[top->left])
                {
                    q.push(top->left);
                    visited[top->left] = true;
                    flag = true;
                }
                if(top->right && !visited[top->right])
                {
                    q.push(top->right);
                    visited[top->right] = true;
                    flag = true;
                }
                if(mp.count(top) && !visited[mp[top]])
                {
                    q.push(mp[top]);
                    visited[mp[top]] = true;
                    flag = true;
                }
            }
            if(flag) v++;  
        }
        return v;
    }
};
