//O(N),O(N)- using stack

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
    void flatten(TreeNode* root) {
        stack<TreeNode*>s;
        if(root==NULL) return;
        s.push(root);
        while(!s.empty())
        {
            auto top=s.top();
            s.pop();
            if(top->right) s.push(top->right);
            if(top->left) s.push(top->left);
            if(!s.empty())
            {
                top->right=s.top();
            }
            top->left=NULL;
        }
    }
};


//O(N),O(1)- using Morris
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
    void flatten(TreeNode* root) {
        TreeNode* curr=root;
        while(curr)
        {
            TreeNode* prev=curr->left;
            if(curr->left!=NULL)
            {
                while(prev->right){
                prev=prev->right;}
                prev->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
        }
    }
};
