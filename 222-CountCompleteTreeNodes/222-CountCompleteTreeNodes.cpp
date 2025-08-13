// Last updated: 8/13/2025, 3:36:05 PM
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
int helper(TreeNode*root){
    if(root==NULL)return 0;
    int val1=0;
    int val2=0;
    if(root->left!=NULL){
        val1=helper(root->left)+1;
    }
    if(root->right!=NULL){
        val2=helper(root->right)+1;
    }
    return val1+val2;
}
    int countNodes(TreeNode* root) {
        if(root==NULL)return 0;
        return helper(root)+1;
    }
};