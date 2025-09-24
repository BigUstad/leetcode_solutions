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
    bool isUnivalTree(TreeNode* root) {
        if (!root) return true;
        if (!root->left && !root->right) return true;
        return morrisTraversalHelper(root);
    }
private:
    bool morrisTraversalHelper(TreeNode* root) {
        TreeNode* curr = root;
        bool l_ret = true;
        int prev_val = 101;
        while (curr) {
            if (!curr->left) {
                // If no left child visit this node & go right
                // result.push_back(curr->val);
                if (prev_val < 100 && prev_val != curr->val) {
                    l_ret = false;
                }
                prev_val = curr->val;
                curr = curr->right;
            } else {
                // Find the inorder predecessor of curr
                TreeNode* prev = curr->left;
                while (prev->right &&
                    prev->right != curr) {
                    prev = prev->right;
                }
                // Make curr the right child of its inorder predecessor
                if (!prev->right) {
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    // Revert the changes made in tree structure.
                    prev->right = nullptr;
                    if (prev_val < 100 && prev_val != curr->val) {
                        l_ret = false;
                    }
                    prev_val = curr->val;
                    // result.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return l_ret;
    }
};
