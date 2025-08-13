// Last updated: 8/13/2025, 3:36:52 PM
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
TreeNode*helper(vector<int>& postorder, vector<int>& inorder,int start,int end,int &index){
    if(start>end)return NULL;
    int val=postorder[index];
    int i=start;
    for(;i<=end;i++){
        if(inorder[i]==val){
            break;
        }
    }
    index--;
    TreeNode*root=new TreeNode(val);
    root->right=helper(postorder,inorder,i+1,end,index);
    root->left=helper(postorder,inorder,start,i-1,index);
    return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
        int index=n-1;
        return helper(postorder,inorder,0,n-1,index);
    }
};