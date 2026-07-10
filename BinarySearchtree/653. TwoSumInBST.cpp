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
stack<TreeNode*>sn;
stack<TreeNode*>sb;
void pushnext(TreeNode* root)
{
    while(root)
    {
        sn.push(root);
        root=root->left;
    }
}
void pushbefore(TreeNode* root)
{
    while(root)
    {
        sb.push(root);
        root=root->right;
    }
}
int next()
{
    auto top=sn.top();
        sn.pop();
        pushnext(top->right);
        return top->val;
}
int before()
{
     auto top=sb.top();
        sb.pop();
        pushbefore(top->left);
        return top->val;
}
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        pushnext(root);
        pushbefore(root);
        int left=next();
        int right=before();
        while(left<right)
        {
            int sum=left+right;
            if(sum==k) return true;
            else if(sum<k) left=next();
            else right=before();
        }
        return false;
    }
};
