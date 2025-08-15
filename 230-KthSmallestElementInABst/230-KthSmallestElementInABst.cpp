// Last updated: 8/15/2025, 3:20:37 PM
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
void helper(TreeNode*root,vector<int>&ans){
    if(root==NULL)return;
    helper(root->left,ans);
    ans.push_back(root->val);
    helper(root->right,ans);
}
    int kthSmallest(TreeNode* root, int k) {
        vector<int>ans;
        if(root==NULL)return 0;
        helper(root,ans);
        k--;
        return ans[k];
    }
};