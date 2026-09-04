class Solution {
public:
    Node* connect(Node* root) {
        
        if(root == NULL)
            return root;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {

            int sz = q.size();
            vector<Node*> temp;

            while(sz--) {

                Node* node = q.front();
                q.pop();

                temp.push_back(node);

                if(node->left)
                    q.push(node->left);

                if(node->right)
                    q.push(node->right);
            }

            for(int i = 0; i < temp.size() - 1; i++) {
                temp[i]->next = temp[i + 1];
            }
        }

        return root;
    }
};