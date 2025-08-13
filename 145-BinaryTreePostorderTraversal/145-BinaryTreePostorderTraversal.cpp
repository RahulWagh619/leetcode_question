// Last updated: 8/13/2025, 3:36:25 PM
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

    vector<int> postorderTraversal(TreeNode* root) {
       vector<int>ans;
       stack<TreeNode*>st1;
       stack<TreeNode*>st2;
       TreeNode*node=root;
       if(node==NULL)return ans;
       st1.push(node);
       while(!st1.empty()){
           TreeNode*k=st1.top();
           st2.push(k);
           st1.pop();
           if(k->left){
            st1.push(k->left);
           }
           if(k->right){
            st1.push(k->right);
           }
       }
       while(!st2.empty()){
          ans.push_back(st2.top()->val);
          st2.pop();
       }
       return ans;

    }
};