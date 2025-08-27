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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode*node=new TreeNode(val);
            node->left=root;
            return node;
        }
        int count=1;
        queue<TreeNode*>q;
        q.push(root);
        vector<TreeNode*>a;
        while(count<=depth-1){
            int size=q.size();
            if(count==depth-1){
                for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                a.push_back(node);
             }
             break;
            }
            else{
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left != NULL){
                    q.push(node->left); 
                }
                if(node->right != NULL){
                    q.push(node->right);
                }
             }
            }
            count++;
        }
        for(int i = 0; i < a.size(); i++){
    TreeNode* parent_node = a[i];
    TreeNode* original_left = parent_node->left;
    TreeNode* original_right = parent_node->right;
    TreeNode* new_left_node = new TreeNode(val);
    parent_node->left = new_left_node;
    new_left_node->left = original_left; 
    TreeNode* new_right_node = new TreeNode(val);
    parent_node->right = new_right_node;
    new_right_node->right = original_right; 
}
        return root;
    }
};