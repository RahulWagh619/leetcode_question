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
int count=0;
int helper(TreeNode* root) {
    if (root == NULL)
        return INT_MIN;

    int left = helper(root->left);
    int right = helper(root->right);

    int maxi = max({root->val, left, right});
    if(maxi==root->val){
        count++;
    }

    return maxi;
}
    int countDominantNodes(TreeNode* root) {
        helper(root);
        return count;
    }
};