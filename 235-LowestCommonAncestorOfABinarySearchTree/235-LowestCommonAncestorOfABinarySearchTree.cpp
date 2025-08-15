// Last updated: 8/15/2025, 3:20:34 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val>=p->val && root->val<=q->val||root->val>=q->val && root->val<=p->val){
            return root;
        }
        // if(root->val>p->val){
             while(true){
                if(root->val>p->val && root->val>q->val){
                    root=root->left;
                }
                else if(root->val<p->val && root->val<q->val){
                    root=root->right;
                }
                else{
                    return root;
                    break;
                }
             }
        // } 
    }
};