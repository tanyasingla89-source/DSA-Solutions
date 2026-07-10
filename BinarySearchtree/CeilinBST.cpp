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
    int findCeil(Node* root, int x) {
        if(!root) return -1;
        Node* curr=root;
        int ceil=-1;
        while(curr)
        {
            if(curr->data>x)
            {
                ceil=curr->data;
                curr=curr->left;
            }
            else if(curr->data<x)
            {
                curr=curr->right;
            }else
            {
                ceil=curr->data;
                break;
            }
        }
        return ceil;
        
    }
};
