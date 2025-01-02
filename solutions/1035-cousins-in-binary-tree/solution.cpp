/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void bfsHelper(TreeNode* root, int& x, int& y, unsigned short& xd,
                   unsigned short& yd) {
        // No need to process these cases.
        // Let isCousins return false
        if (root == nullptr)
            return;
        if (root->val == x || root->val == y) {
            return;
        }
        // Insert a nullptr when a level ends.
        // Increment depth every time a level ends (when a nullptr is seen)
        TreeNode* cur = root;
        unsigned short depth =
            1; // Starting with 1 as root isn't pushed onto the queue anyway.
        std::queue<TreeNode*> q;
        if (cur->left != nullptr) {
            // Return for same parent condition
            if (cur->left->val == x || cur->left->val == y)
                return;
            q.push(cur->left);
        }
        if (cur->right != nullptr) {
            // Return for same parent condition
            if (cur->right->val == x || cur->right->val == y)
                return;
            q.push(cur->right);
        }
        q.push(nullptr);
        while (!q.empty()) {
            bool level_end = false;
            TreeNode* front = q.front();
            if (front == nullptr) {
                // 1 level ended
                ++depth;
                // If this is the only element
                // Traversal has ended
                if (q.size() > 1) {
                    q.push(nullptr);
                }
            } else {
                // std::cout << " " << front->val;
                if (front->val == x)
                    xd = depth;
                if (front->val == y)
                    yd = depth;
            }
            // Return for same parent condition
            if (front != nullptr && (front->left != nullptr) &&
                (front->right != nullptr)) {
                if ((front->left->val == x || front->left->val == y) &&
                    (front->right->val == x || front->right->val == y)) {
                    xd = yd = 0;
                    return;
                }
            }
            if (front != nullptr && front->left != nullptr) {
                q.push(front->left);
            }
            if (front != nullptr && front->right != nullptr) {
                q.push(front->right);
            }
            q.pop();
        }
        std::cout << std::endl;
    }

    bool isCousins(TreeNode* root, int x, int y) {
        unsigned short xd = 0, yd = 0;
        bfsHelper(root, x, y, xd, yd);
        if (xd == 0 && yd == 0) {
            // Constraints say won't happen
            // Other edge cases
            return false;
        }
        return (xd == yd);
    }
};
