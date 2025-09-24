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
    vector<int> getLonelyNodes(TreeNode* root) {
        if (!root) return {};
        if (!root->left && !root->right) return {};
        std::vector<int> v_ret;
        iterativePreOrderHelper(root, v_ret);
        return v_ret;
    }
    void iterativePreOrderHelper(TreeNode* root, std::vector<int>& v) {
        std::stack<TreeNode*> s;
        // Pre-Order traversal with stack.
        // It is Root-> Left -> Right
        while (root) {
            // Root
            // Either or both children
            if (root->left || root->right) {
                // Adding only if there is one child
                if ((root->left && !root->right) ||
                    (!root->left && root->right)) {
                    v.push_back(
                        ((root->left)?root->left->val :
                            root->right->val));
                }
            }
            
            // Right first because, to put left on top
            if (root->right) {
                s.push(root->right);
            }
            // Left gets dealt with first
            if (root->left) {
                root = root->left;
            } else {
                if (!s.empty()) {
                    root = s.top();
                    s.pop();
                } else {
                    root = nullptr;
                }
            }
        }
    }
};
