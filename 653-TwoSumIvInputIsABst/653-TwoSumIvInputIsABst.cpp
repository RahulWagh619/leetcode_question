// Last updated: 8/19/2025, 8:59:20 PM
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
    bool findTarget(TreeNode* root, int k) {
        vector<int>ans;
        helper(root,ans);
        map<int,int>mpp;
        for(int i=0;i<ans.size();i++){
            if(mpp[k-ans[i]]>0){
                return true;
            }
            mpp[ans[i]]++;
        }
        return false;
    }
};