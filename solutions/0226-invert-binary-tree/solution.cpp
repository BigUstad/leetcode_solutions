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
    TreeNode* invertTree(TreeNode* root) {
        if (!root || (!root->right && !root->left)) {
            return root;
        }
        std::queue<TreeNode*> q;
        TreeNode* cur = nullptr;
        q.push(root);
        while (!q.empty()) {
            cur = q.front(); q.pop();
            std::swap(cur->left, cur->right);
            if (cur->left) {
                q.push(cur->left);
            }
            if (cur->right) {
                q.push(cur->right);
            }
        }
        return root;
    }
};
