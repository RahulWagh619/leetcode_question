// Last updated: 8/19/2025, 8:59:30 PM
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
TreeNode*lastrightchild(TreeNode*root){
    if(root->right==NULL)return root;
    return lastrightchild(root->right);
}
TreeNode*helper(TreeNode*root){
    if(root->left==NULL){
        return root->right;
    }
    else if(root->right==NULL){
        return root->left;
    }
    TreeNode*righty=root->right;
    TreeNode*lefty=lastrightchild(root->left);
    lefty->right=righty;
    return root->left;
}
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)return NULL;
        if(root->val==key){
            return helper(root);
        }
        TreeNode*curr=root;
        while(root){
            if(root->val>key){
                if(root->left!=NULL && root->left->val==key){
                   root->left=helper(root->left);
                   break;
                }
                else{
                    root=root->left;
                }
            }
            else{
                 if(root->right!=NULL && root->right->val==key){
                   root->right=helper(root->right);
                   break;
                }
                else{
                    root=root->right;
                }

            }

        }
        return curr;
    }
};