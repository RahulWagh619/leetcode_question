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
void helper(TreeNode*root,int targetSum,long long total,map<long long,int>&mpp,long long &count){
    if(root==NULL)return ;
    total+=root->val;
    if(mpp.find(total-targetSum)!=mpp.end()){
        count+=mpp[total-targetSum];
    }
    mpp[total]++;
    helper(root->left,targetSum,total,mpp,count);
    helper(root->right,targetSum,total,mpp,count);
    mpp[total]--;
}
    int pathSum(TreeNode* root, int targetSum) {
        map<long long,int>mpp;
        mpp[0]++;
        long long count=0;
        helper(root,targetSum,0,mpp,count);
        return (int)count;
    }
};