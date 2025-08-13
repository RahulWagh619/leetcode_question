// Last updated: 8/13/2025, 3:34:34 PM
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // map<x, map<level, multiset<int>>> to auto-sort by x, level, and values
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;  // node, {x, level}
        
        q.push({root, {0, 0}});
        
        while (!q.empty()) {
            auto [node, coords] = q.front(); q.pop();
            int x = coords.first;
            int level = coords.second;
            
            nodes[x][level].insert(node->val);
            
            if (node->left) {
                q.push({node->left, {x - 1, level + 1}});
            }
            if (node->right) {
                q.push({node->right, {x + 1, level + 1}});
            }
        }
        
        vector<vector<int>> result;
        
        for (auto& x_pair : nodes) {
            vector<int> col;
            for (auto& level_pair : x_pair.second) {
                col.insert(col.end(), level_pair.second.begin(), level_pair.second.end());
            }
            result.push_back(col);
        }
        
        return result;
    }
};
