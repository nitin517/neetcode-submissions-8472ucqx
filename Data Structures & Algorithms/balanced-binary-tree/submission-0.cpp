/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int h(TreeNode*root){
        if(!root)return 0;
        int l=1+h(root->left);
        int r=1+h(root->right);
        return max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)return true;
        int l=h(root->left);
        int r=h(root->right);
        return (abs(l-r)<=1)&&isBalanced(root->left)&&isBalanced(root->right);

        
    }
};
