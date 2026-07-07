/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        queue<TreeNode*>q;
        if(root==NULL) return s;
        q.push(root);
        while(!q.empty())
        {
            auto top=q.front();
            q.pop();
            if(top==NULL) s+=("#,");
            else {s+=(to_string(top->val)+",");
            q.push(top->left);
            q.push(top->right);
        }
       
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream ss(data);
        string str;
        getline(ss,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            auto top=q.front();
            q.pop();
            getline(ss,str,',');
            if(str=="#")
            {
                top->left=NULL;
            }
            else
            {
                top->left = new TreeNode(stoi(str));
                q.push(top->left);
            }
            getline(ss,str,',');
            if(str=="#")
            {
                top->right=NULL;
            }
            else
            {
                top->right = new TreeNode(stoi(str));
                q.push(top->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
