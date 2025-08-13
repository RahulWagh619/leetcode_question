// Last updated: 8/13/2025, 3:35:45 PM
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
    string serialize(TreeNode* root) {
        string s="";
        if(root==NULL)return s;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                if(q.front()==NULL){
                    s+="null,";
                    q.pop();
                    continue;
                }
                TreeNode*node=q.front();
                s += to_string(node->val) + ",";
                q.pop();
                if(node->left!=NULL){
                     q.push(node->left);
                }
                else{
                    q.push(NULL);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
                else{
                    q.push(NULL);
                }
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       if(data.size()==0)return NULL;
       stringstream s(data);
       string str;
       getline(s,str,',');
       TreeNode*root=new TreeNode(stoi(str));
       queue<TreeNode*>q;
       q.push(root);
       while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            TreeNode*node=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="null"){
                node->left=NULL;
            }
            else{
                TreeNode*lefty=new TreeNode(stoi(str));
                node->left=lefty;
                q.push(lefty);
            }
            getline(s,str,',');
            if(str=="null"){
                node->right=NULL;
            }
            else{
                TreeNode*righty=new TreeNode(stoi(str));
                node->right=righty;
                q.push(righty);
            }
        }
       }
       return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));