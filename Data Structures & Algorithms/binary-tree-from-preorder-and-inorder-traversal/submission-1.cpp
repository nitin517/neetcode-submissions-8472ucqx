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
    unordered_map<int,int>mp;
    TreeNode* f(vector<int>&preorder,vector<int>&inorder,int &i,int s,int e){
        if(s>e)return NULL;
        TreeNode*root=new TreeNode(preorder[i]);
        int in=mp[preorder[i]];
        i++;
        root->left=f(preorder,inorder,i,s,in-1);
        root->right=f(preorder,inorder,i,in+1,e);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        for(int j=0;j<n;j++){
            mp[inorder[j]]=j;
        }
        int i=0;
        return f(preorder,inorder,i,0,n-1);

        
    }
};
