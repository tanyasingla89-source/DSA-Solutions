/* Structure for tree and linked list
class Node {
  public:
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};*/
class Solution {
  public:
    Node* treeToDLL(Node* root) {
        Node* prev=NULL;
        Node* head=NULL;
        Node* curr=root;
        while(curr)
        {
            if(curr->left==NULL)
            {
                if(prev==NULL) head=curr;
                else
                {
                    prev->right=curr;
                    curr->left=prev;
                }
                prev=curr;
                curr=curr->right;
            }
            else
            {
                Node* pr=curr->left;
                while(pr->right!=NULL && pr->right!=curr)
                {
                    pr=pr->right;
                }
                if(pr->right==NULL)
                {
                    pr->right=curr;
                    curr=curr->left;
                }
                else
                {
                    pr->right=NULL;
                    if(prev==NULL) head=curr;
                else
                {
                    prev->right=curr;
                    curr->left=prev;
                }
                prev=curr;
                curr=curr->right;
                }
            }
        }
        return head;
        
    }
};
