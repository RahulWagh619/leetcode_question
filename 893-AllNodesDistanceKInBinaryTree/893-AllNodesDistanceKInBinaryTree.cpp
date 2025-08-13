// Last updated: 8/13/2025, 3:34:50 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    void parents(TreeNode *root, map<TreeNode *, TreeNode *> &mpp)
    {
        if (root == NULL)
            return;
        if (root->left != NULL)
        {
            mpp[root->left] = root;
            parents(root->left, mpp);
        }
        if (root->right != NULL)
        {
            mpp[root->right] = root;
            parents(root->right, mpp);
        }
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        map<TreeNode *, TreeNode *> mpp;
        if(k==0){
            ans.push_back(target->val);
            return ans;
        }
        parents(root, mpp);
        map<TreeNode *, bool> mpp2;
        int distance = 0;
        queue<TreeNode *> q;
        mpp2[target] = true;
q.push(target);
        while (!q.empty())
        {
            if (distance >= k)
                break;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                // TreeNode*value=mpp[node];
                if (mpp.count(node) && mpp[node] != NULL && mpp2.find(mpp[node]) == mpp2.end())
                {
                    TreeNode *value = mpp[node];
                    mpp2[value] = true;
                    q.push(value);
                    if (distance == k - 1)
                        ans.push_back(value->val);
                }
                if (node->left != NULL && mpp2.find(node->left) == mpp2.end())
                {
                    mpp2[node->left] = true;
                    q.push(node->left);
                    if (distance == k - 1)
                    {
                        ans.push_back(node->left->val);
                    }
                }
                if (node->right != NULL && mpp2.find(node->right) == mpp2.end())
                {
                    mpp2[node->right] = true;
                    q.push(node->right);
                    if (distance == k - 1)
                    {
                        ans.push_back(node->right->val);
                    }
                }
                q.pop();
            }
            distance++;
        }
        return ans;
    }
};