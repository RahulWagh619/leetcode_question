// Last updated: 8/13/2025, 3:35:57 PM
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
bool helper(TreeNode*root,int x,vector<TreeNode*>&ans){
    if(root==NULL)return false;
    ans.push_back(root);
    if(root->val==x)return true;
    if(helper(root->left,x,ans)||helper(root->right,x,ans)){
        return true;
    }
    ans.pop_back();
    return false;

}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>ans1;
        vector<TreeNode*>ans2;
        helper(root,p->val,ans1);
        helper(root,q->val,ans2);
        int i = 0;
        while (i < ans1.size() && i < ans2.size() && ans1[i] == ans2[i])
            i++;

        return ans1[i - 1]; 

    }
};