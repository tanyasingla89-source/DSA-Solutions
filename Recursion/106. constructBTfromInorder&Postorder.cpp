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
TreeNode* build(vector<int>& postorder,int pstart,int pend,vector<int>& inorder, int instart,int inend,unordered_map<int,int>&mp)
{
    if(pstart<pend || instart>inend) return NULL;
    TreeNode* root=new TreeNode(postorder[pstart]);
    int inroot=mp[root->val];
    int inright=inend-inroot;
    root->right=build(postorder,pstart-1,pstart-inright,inorder,inroot+1,inend,mp);
    root->left=build(postorder,pstart-inright-1,pend,inorder,instart,inroot-1,mp);
    return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        return build(postorder,postorder.size()-1,0,inorder,0,inorder.size()-1,mp);
    }
};
