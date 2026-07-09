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
bool check(TreeNode* root,long long maxv,long long minv)
{
    if(root == NULL) return true;
    if(root->val<=minv || root->val>maxv) return false;
    return check(root->left,root->val,minv) && check(root->right,maxv,root->val);

    
}
    bool isValidBST(TreeNode* root) {
        return check(root,LLONG_MAX,LLONG_MIN);
    }
};
