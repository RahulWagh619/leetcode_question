// Last updated: 8/13/2025, 3:36:27 PM
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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        TreeNode*node=root;
        vector<int>ans;
        while(true){
            if(node!=NULL){
                st.push(node);
                ans.push_back(node->val);
                node=node->left;
            }
            else{
                if(st.empty())break;
                node=st.top();
                node=node->right;
                st.pop();
            }
        }
        return ans;
        
    }
};