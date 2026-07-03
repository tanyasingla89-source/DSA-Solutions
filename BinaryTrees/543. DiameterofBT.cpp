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
int height(int &maxi,TreeNode* root)
{
    if(root==NULL) return 0;
        int l=height(maxi,root->left);
        int r=height(maxi,root->right);
        maxi=max(maxi,l+r);
        return 1+max(l,r);
}
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0;
       height(maxi,root);
       return maxi;
    }
};
