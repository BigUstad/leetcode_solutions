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
    void morrisTraversalHelper(TreeNode* root, std::vector<int>& result) {
        TreeNode* curr = root;
        while (curr != nullptr) {
            if (curr->left == nullptr) {
                // If no left child visit this node & go right
                result.push_back(curr->val);
                curr = curr->right;
            } else {
                // Find the inorder predecessor of curr
                TreeNode* prev = curr->left;
                while (prev->right != nullptr &&
                    prev->right != curr) {
                    prev = prev->right;
                }
                // Make curr the right child of its inorder predecessor
                if (prev->right == nullptr) {
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    // Revert the changes made in tree structure.
                    prev->right = nullptr;
                    result.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> nums;
        if (root == nullptr) return nums;
        if (root->left == nullptr && root->right == nullptr) {
            nums.push_back(root->val);
            return nums;
        }
        morrisTraversalHelper(root, nums);
        return nums;
    }
};
