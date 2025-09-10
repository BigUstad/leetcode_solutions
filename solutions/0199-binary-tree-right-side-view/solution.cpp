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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) {
            return {};
        }
        if (!root->left && !root->right) {
            return {root->val};
        }
        std::vector<int> v_ret;
        std::queue<TreeNode*> q;
        TreeNode* last = root;
        q.push(root);
        // Pushing nullptr to denote end of level.
        q.push(nullptr);
        v_ret.push_back(root->val);
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if (!cur && !q.empty()) {
                v_ret.push_back(last->val);
                // Last one left is the nullptr from "this" level.
                q.push(nullptr);
            } else {
                if (cur && cur->left) {
                    last = cur->left;
                    q.push(cur->left);
                }
                if (cur && cur->right) {
                    last = cur->right;
                    q.push(cur->right);
                }
            }
        }
        return v_ret;
    }
};
