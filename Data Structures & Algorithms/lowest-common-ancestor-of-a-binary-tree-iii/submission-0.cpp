/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node*f(Node*root,Node*p,Node*q){
        if(root==NULL)return NULL;
        if(root==p || root==q)return root;
        Node*left=f(root->left,p,q);
        Node*right=f(root->right,p,q);
        if(left!=NULL && right!=NULL)return root;
        else{
            if(left!=NULL)return left;
            if(right!=NULL)return right;
            return NULL;
        }

    }
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node*root=p;
        while(root->parent!=NULL){
            root=root->parent;
        }
        return f(root,p,q);
        
    }
};