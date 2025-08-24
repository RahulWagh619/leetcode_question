/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)return NULL;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<Node*>a;
            for(int i=0;i<size;i++){
                Node*z=q.front();
                q.pop();
                if(z->left){
                    q.push(z->left);
                }
                if(z->right){
                    q.push(z->right);
                }
                a.push_back(z);
            }
            for(int i=0;i<a.size()-1;i++){
                //  a[i]->left=NULL;
                a[i]->next=a[i+1];
            }
            //  a[a.size()-1]->left=NULL;
            a[a.size()-1]->next=NULL;
        }
        return root;
    }
};