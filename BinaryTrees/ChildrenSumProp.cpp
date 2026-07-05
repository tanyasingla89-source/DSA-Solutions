/* class TreeNode {
       int val;
       TreeNode *left, *right;
       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
   };
*/

class Solution {
public:
bool isleaf(TreeNode* root)
{return (root->left==NULL && root->right==NULL);}
    bool checkChildrenSum(TreeNode* root) {
        if(root==NULL) return true;
        if(isleaf(root)) return true;
        int childSum = 0;
        if(root->left)  childSum += root->left->val;
        if(root->right) childSum += root->right->val;
        return (root->val == childSum) &&
               isSumProperty(root->left) &&
               isSumProperty(root->right);
    }
};
