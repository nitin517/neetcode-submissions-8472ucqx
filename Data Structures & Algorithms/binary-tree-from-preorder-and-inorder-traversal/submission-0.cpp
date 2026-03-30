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
    int ind(vector<int>&inorder,int s,int e,int val){
        for(int i=s;i<=e;i++){
            if(inorder[i]==val){
                return i;
            }
        }
        return -1;
    }
    TreeNode* f(vector<int>&preorder,vector<int>&inorder,int &i,int s,int e){
        if(s>e)return NULL;
        TreeNode*root=new TreeNode(preorder[i]);
        int in=ind(inorder,s,e,preorder[i]);
        i++;
        root->left=f(preorder,inorder,i,s,in-1);
        root->right=f(preorder,inorder,i,in+1,e);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        int i=0;
        return f(preorder,inorder,i,0,n-1);

        
    }
};
