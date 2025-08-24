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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>a;
            for(int i=0;i<size;i++){
               TreeNode*node=q.front();
               q.pop();
               if(node->left){
                q.push(node->left);
               }
               if(node->right){
                q.push(node->right);
               }
               a.push_back(node->val);
            }
            ans.push_back(a);
        }
        vector<vector<int>>newone;
        for(int i=ans.size()-1;i>=0;i--){
              newone.push_back(ans[i]);
        }
        return newone;
        
    }
};