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
    int ios(TreeNode* root){
        root = root->right;
        while(root->left!=NULL){
            root = root->left;
        } 
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        else if (key<root->val){
            root->left = deleteNode(root->left,key);
        }
        else if(key>root->val){
            root->right = deleteNode(root->right,key);
        }
        else{
            if(root->left==NULL && root->right ==NULL) return NULL;
            else if(root->left==NULL && root->right!=NULL) return root->right;
            else if(root->left!=NULL && root->right==NULL) return root->left;
            else{
                int succval = ios(root);
                root->val = succval;
                root->right = deleteNode(root->right,succval);
            }
        }
        return root;
    }
};