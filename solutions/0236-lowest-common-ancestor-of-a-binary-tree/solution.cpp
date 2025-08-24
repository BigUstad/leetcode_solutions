/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return nullptr;
        }
        if (!root->left && !root->right) {
            return nullptr;
        }
        if (!p || !q) {
            return nullptr;
        }
        std::vector<TreeNode*> p_path;
        std::vector<TreeNode*> q_path;
        TreeNode* l_ret = nullptr;
        if (dfsHelper(root, p, p_path) && dfsHelper(root, q, q_path)) {
            // TODO: Find the actual LCA
            std::unordered_set<TreeNode*> both_paths;
            for (auto& t_p: p_path) {
                both_paths.insert(t_p);
            }
            for (auto& t_q: q_path) {
                auto q_itr = both_paths.find(t_q);
                if (q_itr != both_paths.end() && *q_itr != root) {
                    l_ret = *q_itr;
                }
            }
        }

        return (l_ret) ? l_ret : root;
    }
    bool dfsHelper(TreeNode* root, TreeNode* t, std::vector<TreeNode*>& path) {
        if (!root) return false;
        // Add current node.
        path.push_back(root);
        if (root == t) {
            return true;
        }
        // We are recursively searching left & right trees
        if (dfsHelper(root->left, t, path) || dfsHelper(root->right, t, path)) {
            return true;
        }
        // We release memory when we backtrack to the parent as target is not found.
        path.pop_back();
        return false;
    }
};
