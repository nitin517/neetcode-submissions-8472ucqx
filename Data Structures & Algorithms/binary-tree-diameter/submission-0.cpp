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
    int height(TreeNode*root){
        if(!root)return 0;
        int l=1+height(root->left);
        int r=1+height(root->right);
        return max(l,r);
    }
    int ans=0;
    void preorder(TreeNode*root){
        if(!root)return;
        int l=height(root->left);
        int r=height(root->right);
        ans=max(ans,l+r+1);
        preorder(root->left);
        preorder(root->right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
       preorder(root);
       return ans-1;

        
    }
};
