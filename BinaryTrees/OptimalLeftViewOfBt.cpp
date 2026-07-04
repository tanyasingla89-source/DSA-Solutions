class Solution {
public:
    vector<int> leftView(Node* root) {
        vector<int> ans;
        if(root == NULL) return ans;

        queue<Node*> q;        // ✅ no pair needed
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();

            for(int i = 0; i < size; i++)
            {
                Node* top = q.front();
                q.pop();

                if(i == 0)                    // ✅ only first node
                    ans.push_back(top->data);

                if(top->left)  q.push(top->left);
                if(top->right) q.push(top->right); // ✅ push both!
            }
        }
        return ans;
    }
};
