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
    void bfsHelper(TreeNode*& root, int& max_depth) {
        if (root == nullptr) {
            max_depth = 0;
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            max_depth = 1;
            return;
        }
        max_depth = 1;
        std::queue<TreeNode*> q;
        if (root->left != nullptr) {
            q.push(root->left);
        }
        if (root->right != nullptr) {
            q.push(root->right);
        }
        // Signals end of nodes in cur depth
        q.push(nullptr);
        // BFS level 2 depth nodes are all in queue now.
        while (!q.empty()) {
            TreeNode*& front = q.front();
            if (front == nullptr) {
                ++max_depth;
                // Not the last node
                // size == 1 means traversal has ended
                if (q.size() > 1) {
                    // Signals end of nodes in cur depth
                    q.push(nullptr);
                }
            } else {
                if (front->left != nullptr) {
                    q.push(front->left);
                }
                if (front->right != nullptr) {
                    q.push(front->right);
                }
            }
            q.pop();
        }
    }
    int maxDepth(TreeNode* root) {
        int max_depth = INT_MIN;
        bfsHelper(root, max_depth);
        return max_depth;
    }
};
