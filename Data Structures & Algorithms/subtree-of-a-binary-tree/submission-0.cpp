class Solution {
public:

    void preorder(TreeNode* root, string &s) {
        if(!root) {
            s += "N,";   // NULL marker
            return;
        }

        s += to_string(root->val) + ",";
        preorder(root->left, s);
        preorder(root->right, s);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string s1 = "", s2 = "";

        preorder(root, s1);
        preorder(subRoot, s2);

        return s1.find(s2) != string::npos;
    }
};