// Last updated: 8/13/2025, 3:36:51 PM
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
int check(TreeNode* root){
    if(root==NULL)return 0;
    int lh=check(root->left);
    int rh=check(root->right);
    return 1+max(lh,rh);
}
    bool isBalanced(TreeNode* root) {
        if(root==NULL)return true;
        TreeNode*node=root;
        int leftone=check(node->left);
        int rightone=check(node->right);
        if(abs(leftone-rightone)>1)return false;
        bool lefty=isBalanced(node->left);
        bool righty=isBalanced(node->right);
        if(!lefty||!righty){
            return false;
        }
        return true;
    }
};