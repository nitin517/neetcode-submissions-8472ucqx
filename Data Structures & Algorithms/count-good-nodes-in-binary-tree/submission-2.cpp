class Solution {
public:
    
    int f(TreeNode* root, int maxi) {
        if(root == NULL) return 0;

        int count = 0;

        if(root->val >= maxi) count = 1;

        int newMax = max(maxi, root->val);

        count += f(root->left, newMax);
        count += f(root->right, newMax);

        return count;
    }

    int goodNodes(TreeNode* root) {
        return f(root, root->val);
    }
};