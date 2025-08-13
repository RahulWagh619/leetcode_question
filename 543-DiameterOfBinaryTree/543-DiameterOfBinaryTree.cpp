// Last updated: 8/13/2025, 3:35:10 PM
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
int maxd=0;
int check(TreeNode* root){
    if(root==NULL)return 0;
    int lh=check(root->left);
    int rh=check(root->right);
    maxd=max(maxd,lh+rh);
    return 1+max(lh,rh);
}
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        check(root);
        return maxd;
    }
};