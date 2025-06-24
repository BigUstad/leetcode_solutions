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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return false;
        }
        if ((!root->left && !root->right) && root->val != targetSum) {
            return false;
        }
        if ((!root->left && !root->right) && root->val == targetSum) {
            return true;
        }
        std::stack<std::tuple<TreeNode*, int, int>> s;
        TreeNode* cur = root;
        int depth = 1;
        s.push(std::make_tuple(cur, cur->val, depth));
        while (!s.empty()) {
            cur = std::get<0>(s.top());
            int cur_sum = std::get<1>(s.top());
            int cur_depth = std::get<2>(s.top());
            if (!cur->right && !cur->left && cur_sum == targetSum) {
                return true;
            }
            s.pop();
            if (cur->right) {
                int right_cur_sum = (cur_sum + cur->right->val);
                s.push(std::make_tuple(cur->right, right_cur_sum, cur_depth + 1));
            }
            if (cur->left) {
                int left_cur_sum = (cur_sum + cur->left->val);
                s.push(std::make_tuple(cur->left, left_cur_sum, cur_depth + 1));
            }
        }
        return false;
    }
};
