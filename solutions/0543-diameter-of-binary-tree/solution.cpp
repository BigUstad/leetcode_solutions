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
    int dfsHelper(TreeNode* root, int& diameter) {
        if (!root) return 0; // edge length
        int left_edge_length = dfsHelper(root->left, diameter);
        int right_edge_length = dfsHelper(root->right, diameter);
        diameter = std::max(diameter, left_edge_length + right_edge_length);
        // std::cout << "At " << root->val << " d: " << diameter << std::endl;
        return std::max(left_edge_length, right_edge_length) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr ||
            (!root->left && !root->right)) {
            return 0;
        }
        int max_diameter = 0;
        dfsHelper(root, max_diameter);
        return max_diameter;
    }
};
