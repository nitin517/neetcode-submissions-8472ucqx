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
    unordered_map<TreeNode*,int>mp;
    int rob(TreeNode* root) {
        if(root==NULL)return 0;
        if(mp.find(root)!=mp.end())return mp[root];
        int a=0;
        int b=0;
        //take
        int c=0,d=0;
        if(root->right){
            c=rob(root->right->left)+rob(root->right->right);
        }
        if(root->left){
            d=rob(root->left->left)+rob(root->left->right);
        }
        a=root->val+c+d;
        b=rob(root->right)+rob(root->left);

        return mp[root]=max(a,b);
        
    }
};