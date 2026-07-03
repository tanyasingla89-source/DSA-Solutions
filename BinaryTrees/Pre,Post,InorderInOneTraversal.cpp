/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : val(data) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
	public:
		vector<vector<int>> treeTraversal(TreeNode* root){
			stack<pair<TreeNode*,int>>s;
            vector<int>pre;
            vector<int>post;
            vector<int>ino;
            vector<vector<int>>ans;
            if(root==NULL) return ans;
            s.push({root,1});
            while(!s.empty())
            {
                if(s.top().second==1)
                {
                    auto top=s.top().first;
                    pre.push_back(top->val);
                    s.top().second++;
                    if(top->left!=NULL) s.push({top->left,1});
                }
                else if(s.top().second==2)
                {
                    auto top=s.top().first;
                    ino.push_back(top->val);
                    s.top().second++;
                    if(top->right!=NULL) s.push({top->right,1});
                }
                else if(s.top().second==3)
                {
                    auto top=s.top().first;
                    post.push_back(top->val);
                    s.pop();
                }
            }
            ans={ino,pre,post};
            return ans;
		}
};
