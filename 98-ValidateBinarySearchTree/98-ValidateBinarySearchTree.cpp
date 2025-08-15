// Last updated: 8/15/2025, 3:21:08 PM
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

void helper(TreeNode*root,vector<int>&a){
    if(root==NULL)return;
    helper(root->left,a);
    a.push_back(root->val);
    helper(root->right,a);
}
    bool isValidBST(TreeNode* root) {
        if(root==NULL)return true;
        bool x=true;
        vector<int>a;
        helper(root,a);
        for(int i=1;i<a.size();i++){
            if(a[i]<=a[i-1]){
                x=false;
                break;
            }
        }
        if(x){
            return true;
        }
        return false;
    }
};