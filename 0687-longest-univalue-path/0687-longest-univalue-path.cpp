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
    int ans=0;
    int longestUnivaluePath(TreeNode* root) {
        dfs(root,INT_MIN);
        return  ans;
    }
    int dfs(TreeNode*root,int parval){
        if(root==NULL)return 0;
        int left=dfs(root->left,root->val);
        int right=dfs(root->right,root->val);
        ans=max(ans,left+right);
        if(parval==root->val)return 1+max(left,right);
        return 0;
    }
};