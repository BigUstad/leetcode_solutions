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
    int findTilt(TreeNode* root) {
        if (!root) {
            return 0;
        }
        if (!root->left && !root->right) {
            return root->val;
        }
        int res = 0;
        std::pair<int, int> p = dfsHelper(root, res);
        return res;
    }
private:
    std::pair<int, int> dfsHelper(TreeNode* root, int& res) {
        if (!root) {
            return {0, 0};
        }
        if (!root->left && !root->right) {
            return {root->val, root->val};
        }
        std::pair<int, int> l_pair = dfsHelper(root->left, res);
        std::pair<int, int> r_pair = dfsHelper(root->right, res);
        int level_sum = root->val + l_pair.first + r_pair.first;
        int level_diff = std::abs(l_pair.first - r_pair.first);
        res += level_diff;

        // std::cout << root->val << " <-> " << level_sum << std::endl;
        // std::cout << root->val << ": (L) " << left_sum << ". (R) " << right_sum << std::endl;
        // std::cout << root->val << ": (S) " << level_sum << ". (D) " << level_diff << std::endl;

        return {level_sum, level_diff};
    }
    void printNow(TreeNode* root, std::vector<int>& nums) {
        std::cout << root->val << ": ";
        for (auto& n: nums) {
            std::cout << "  " << n;
        }
        std::cout << std::endl;
    }
};
