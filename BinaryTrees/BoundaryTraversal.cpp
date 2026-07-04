/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
bool isLeaf(Node* node)
    {
        return node->left==NULL && node->right==NULL;
    }
 void leftadd(Node *root,vector<int>&ans)
 {
     auto curr=root->left;
     while(curr)
     {if(!isLeaf(curr)){
     ans.push_back(curr->data);}
     if(curr->left!=NULL) curr=curr->left;
     else curr=curr->right;
     }
 }
 void leafadd(Node *root,vector<int>&ans)
 {
     if(isLeaf(root))
     {
         ans.push_back(root->data);
         return;
     }
    if(root->left)  leafadd(root->left, ans);
    if(root->right) leafadd(root->right, ans);
 }
 void rightadd(Node *root,vector<int>&ans)
 {
     auto curr=root->right;
     vector<int>s;
     while(curr)
     {if(!isLeaf(curr)){
     s.push_back(curr->data);}
     if(curr->right!=NULL) curr=curr->right;
     else curr=curr->left;
     }
     reverse(s.begin(),s.end());
     for(int x : s) ans.push_back(x);
 }
    vector<int> boundaryTraversal(Node *root) {
        vector<int>ans;
        if(root==NULL) return ans;
        if(!isLeaf(root))
        {ans.push_back(root->data);}
        leftadd(root,ans);
        leafadd(root,ans);
        rightadd(root,ans);
        return ans;
    }
};
