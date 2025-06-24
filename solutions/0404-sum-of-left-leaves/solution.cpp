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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) {
            return 0;
        }
        if (!root->left && !root->right) {
            return 0;
        }
        // True if the cur node is a left node
        std::stack<std::pair<TreeNode*, bool>> s;
        TreeNode* cur = root;
        int left_sum = 0;
        s.push(std::make_pair(cur, false));
        while (!s.empty()) {
            cur = s.top().first;
            if (s.top().second &&
                (!cur->left && !cur->right)) {
                left_sum += cur->val;
            }
            s.pop();
            if (cur->right) {
                s.push(std::make_pair(cur->right, false));
            }
            if (cur->left) {
                s.push(std::make_pair(cur->left, true));
            }
        }

        return left_sum;
    }
};
