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
TreeNode* build(vector<int>& preorder,int pres,int preend,vector<int>& inorder, int ins,int inend,unordered_map<int,int>&mp)
{
    if(pres>preend || ins>inend) return NULL;
    TreeNode* root=new TreeNode(preorder[pres]);
    int inroot=mp[root->val];
    int index=inroot-ins;//checks how many values to the right of root
    root->left=build(preorder,pres+1,pres+index,inorder,ins,inroot-1,mp);
    root->right=build(preorder,pres+index+1,preend,inorder,inroot+1,inend,mp);
    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        return build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
    }
};
