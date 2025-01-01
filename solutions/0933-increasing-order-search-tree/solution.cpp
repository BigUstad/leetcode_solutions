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
    void inOrderHelper(TreeNode* root, std::vector<TreeNode*>& nodes) {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr) {
            nodes.push_back(root);
            return;
        }
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* cur = root->left;
        while(cur != nullptr || !s.empty()) {
            while(cur != nullptr) {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            // Process
            nodes.push_back(cur);
            cur = cur->right;
        }
    }
    TreeNode* increasingBST(TreeNode* root) {
        std::vector<TreeNode*> nodes; // nodes are in-order
        inOrderHelper(root, nodes);
        if (nodes.size() <= 0) return nullptr;
        if (nodes.size() == 1) return nodes[0];
        TreeNode* new_root = nodes[0];
        TreeNode* prev = nullptr;
        for (TreeNode* n: nodes) {
            n->left = n->right = nullptr;
            if (prev != nullptr) {
                prev->right = n;
            }
            prev = n;
        }
        return new_root;
    }
};
