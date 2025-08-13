// Last updated: 8/13/2025, 3:37:00 PM
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

bool helper(TreeNode* lefty,TreeNode* righty){
    if(lefty==NULL && righty==NULL)return true;
    if(lefty==NULL||righty==NULL)return false;
    return helper(lefty->left,righty->right) && helper(lefty->right,righty->left) && (lefty->val==righty->val);
}
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true;
        return helper(root->left,root->right);
    }
};