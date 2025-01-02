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
    std::string morrisTraversalHelper(TreeNode* root) {
        std::stringstream ss;
        TreeNode* curr = root;
        while (curr != nullptr) {
            if (curr->left == nullptr) {
                // If no left child visit this node & go right
                ss << "nullptr"; // left, the in-order precedent is nullptr
                ss << std::to_string(curr->val);
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
                    ss << "nullptr";
                } else {
                    // Revert the changes made in tree structure.
                    prev->right = nullptr;
                    ss << std::to_string(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ss.str();
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if ((p == nullptr && q != nullptr) ||
            (p != nullptr && q == nullptr)) 
            return false;
        std::string pbfs = morrisTraversalHelper(p);
        std::string qbfs = morrisTraversalHelper(q);
        if (pbfs.size() != qbfs.size()) {
            return false;
        }
        // Only analyzing strings of same size.
        return (pbfs.compare(qbfs) == 0);
    }
};
