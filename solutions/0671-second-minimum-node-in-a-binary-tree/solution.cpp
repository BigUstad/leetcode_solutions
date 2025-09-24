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
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        if (!root->left && !root->right) return -1;

        prev_min = UINT32_MAX; cur_min = root->val;
        preorderHelper(root);
        return (prev_min == UINT32_MAX)? -1 : (int) prev_min;
    }
private:
    void preorderHelper(TreeNode* root) {
        if (!root) {
            return;
        }
        // Process root
        // Keep searching the subtree that has 'root' value. That's the min, I guess
        // std::cout << "cur_min: " << cur_min << " prev_min: " << prev_min << std::endl;
        if (cur_min < root->val && root->val < prev_min) {
            prev_min = root->val;
        } else if (cur_min == root->val) {
            preorderHelper(root->left);
            preorderHelper(root->right);
        }
    }
    uint32_t prev_min;
    int cur_min;


};
