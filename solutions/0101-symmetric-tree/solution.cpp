/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return true;
        }
        if (root->left == nullptr || root->right == nullptr) {
            return false;
        }
        std::queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty()) {
            TreeNode* lfront = q.front();
            q.pop();
            TreeNode* rfront = q.front();
            q.pop();
            if (lfront == nullptr && rfront == nullptr) {
                // Check is good
                continue;
            }
            if (lfront == nullptr || rfront == nullptr) {
                // Both null ok.
                // Either null - not symmetric
                return false;
            }
            if (lfront->val != rfront->val) {
                return false;
            }
            // For push, This direction --><--
            q.push(lfront->left);
            q.push(rfront->right);
            q.push(lfront->right);
            q.push(rfront->left);
        }
        return true;
    }
};
