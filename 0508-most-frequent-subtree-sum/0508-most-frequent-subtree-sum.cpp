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
void helper(TreeNode*root,map<int,int>&mpp){
    if(root==NULL)return;
    helper(root->left,mpp);
    helper(root->right,mpp);
    if(root->left==NULL && root->right==NULL){
        mpp[root->val]++;
    }
    else if(root->left==NULL){
        mpp[root->val+root->right->val]++;
        root->val=root->val+root->right->val;
    }
    else if(root->right==NULL){
        mpp[root->val+root->left->val]++;
        root->val=root->val+root->left->val;
    }
    else{
        mpp[root->val+root->left->val+root->right->val]++;
        root->val=root->val+root->left->val+root->right->val;
    }
}
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int,int>mpp;
        vector<int>ans;
        if(root==NULL)return ans;
        helper(root,mpp);
        int maxi=-1;
        for(auto &i:mpp){
            maxi=max(maxi,i.second);
        }
        for(auto &i:mpp){
            if(i.second==maxi){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};