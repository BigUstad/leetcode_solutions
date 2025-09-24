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
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root) {
            return {};
        }
        if (!root->left && !root->right) {
            return {(double)root->val};
        }
        std::vector<double> v_ret;
        std::queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        double level_sum = 0.0, level_count = 0.0;
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if (!cur) {
                v_ret.push_back((level_sum / level_count));
                // std::cout << q.size() << std::endl;
                level_sum = level_count = 0.0;
                if (!q.empty()) q.push(nullptr);
                continue;
            }
            level_sum += cur->val;
            ++level_count;
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        return v_ret;
    }
};
