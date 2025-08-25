/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

 // Encodes a tree to a single string.
void helper(string&s,TreeNode*root){
    if(root==NULL){
         return;
    }
    s+=to_string(root->val);
     s += "#";
    helper(s,root->left);
    helper(s,root->right);
}
    string serialize(TreeNode* root) {
        string s="";
        if(root==NULL)return s;
        helper(s,root);
        return s;
    }
TreeNode*helper2(TreeNode*root,int value){
    if(root==NULL){
        TreeNode*node=new TreeNode(value);
        return node;
    }
    if(root->val>=value){
        root->left=helper2(root->left,value);
    }
    else{
        root->right=helper2(root->right,value);
    }
    return root;
}
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       int i=0;
       TreeNode*root=NULL;
       while(i<data.length()){
        string temp;
        while(i<data.length() && data[i]!='#'){
            temp+=data[i];
            i++;
        }
        root=helper2(root,stoi(temp));
        i++;
       }

    return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;