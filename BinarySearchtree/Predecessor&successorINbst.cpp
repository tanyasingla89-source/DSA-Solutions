/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<Node*> findPreSuc(Node* roott, int key) {
        Node* succ=NULL;
        Node* pre=NULL;
        Node*root=roott;
        while(root){
        if(root->data>key) {succ=root; root=root->left;}
        else if(root->data<key) {pre=root; root=root->right;}
        else { 
            Node* keynode=root;
            if(keynode->left!=NULL){
            root=keynode->left;
            while(root!=NULL){
            pre=root;
            root=root->right;}}
            if(keynode->right!=NULL){
            root=keynode->right;
            while(root!=NULL){
            succ=root;
            root=root->left;}}
            break;
        }
            }
        return {pre,succ};
    }
};
