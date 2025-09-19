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
void helper(TreeNode*root,string s,int &val){
       if(root==NULL)return;
       s+=to_string(root->val);
       if(root->left==NULL&& root->right==NULL){
        val+=stoi(s);
       }
       helper(root->left,s,val);
       helper(root->right,s,val);
}
    int sumNumbers(TreeNode* root) {

        int val=0;
        string s;
        helper(root,s,val);
        return val;
    }
};