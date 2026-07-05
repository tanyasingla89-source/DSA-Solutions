/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
	public:
    bool isleaf(TreeNode* root)
    {
        return (root->left==NULL && root->right==NULL);
    }
    void print(TreeNode* root,vector<vector<int>>&ans,vector<int>&r)
    {
        r.push_back(root->data);
        if(isleaf(root))
        {
            ans.push_back(r);
            r.pop_back();
            return;
        }
        if(root->left!=NULL)
        {
        print(root->left,ans,r);}
        if(root->right!=NULL)
        {
            print(root->right,ans,r);}
            r.pop_back();

    }
		vector<vector<int>> allRootToLeaf(TreeNode* root) {
            vector<vector<int>>ans;
            vector<int>r;
            if(!root) return ans;
            print(root,ans,r);
            return ans;
		}
};
