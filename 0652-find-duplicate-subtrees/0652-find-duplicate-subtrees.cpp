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
string helper(TreeNode*root,map<string,int>&mpp,vector<TreeNode*>&ans){
    if(root==NULL){
        return "N";
    }
    string s=to_string(root->val)+","+helper(root->left,mpp,ans)+","+helper(root->right,mpp,ans);
    if(mpp[s]==1){
        ans.push_back(root);
    }
    mpp[s]++;
    return s;
}
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        map<string,int>mpp;
        vector<TreeNode*>ans;
       helper(root,mpp,ans);
        return ans;
    }
};