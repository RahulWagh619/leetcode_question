// Last updated: 8/13/2025, 3:35:04 PM
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
    int widthOfBinaryTree(TreeNode* root) {
         if(root==NULL)return 0;
         queue<pair<TreeNode*,long long>>q;
         q.push({root,0});
         int maxi=INT_MIN;
         while(!q.empty()){
            int size=q.size();
            vector<pair<int,long long>>level;
            long long last=q.front().second;
            for(int i=0;i<size;i++){
                auto [node, idx] = q.front();
                q.pop();
                long long val=idx-last;
                if(node->left!=NULL){
                    q.push({node->left,2*val+1});
                }
                if(node->right!=NULL){
                    q.push({node->right,2*val+2});
                }
                level.push_back({node->val,val});
            }
            maxi=max(maxi,(int)level[size-1].second-(int)level[0].second +1);
         }
    return maxi;
    }
};