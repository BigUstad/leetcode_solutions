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
    vector<string> binaryTreePaths(TreeNode* root) {
        std::vector<std::string> v_ret;
        if (!root) return v_ret;
        if (!root->left && !root->right) {
            v_ret.push_back(std::to_string(root->val));
            return v_ret;
        }
        postorderHelper(root, v_ret);
        return v_ret;
    }
private:
    void postorderHelper(TreeNode* root, std::vector<std::string>& paths) {
        std::stack<TreeNode*> s;
        std::stack<std::string> p_s;
        s.push(root);
        p_s.push(std::to_string(root->val));
        while (!s.empty()) {
            root = s.top();
            s.pop();
            std::string r_path(p_s.top());
            p_s.pop();
            // Left - first
            if (root->left) {
                s.push(root->left);
                p_s.push(r_path + "->" + std::to_string(root->left->val));
            }
            // Right next
            if (root->right) {
                s.push(root->right);
                p_s.push(r_path + "->" + std::to_string(root->right->val));
            }
            // Process Node
            // leaf node check
            if (!root->left && !root->right) {
                // std::cout << r_path << std::endl;
                paths.push_back(r_path);
            }
        }
    }

};
