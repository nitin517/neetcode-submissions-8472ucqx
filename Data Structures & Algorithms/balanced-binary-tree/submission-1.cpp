class Solution {
public:

    int checkHeight(TreeNode* root) {
        if(root == NULL) return 0;
        int left = checkHeight(root->left);
        if(left == -1) return -1; // already unbalanced

        // Get height of right subtree
        int right = checkHeight(root->right);
        if(right == -1) return -1; // already unbalanced

        // Check balance condition
        if(abs(left - right) > 1) return -1;

        // Return height
        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};