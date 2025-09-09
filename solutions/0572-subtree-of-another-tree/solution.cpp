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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) {
            return true;
        }
        if (root && !subRoot) {
            return true;
        }
        if (!root && subRoot) {
            return false;
        }
        std::string root_dfs_str;
        std::string subroot_dfs_str;
        postorderHelper(root, root_dfs_str);
        postorderHelper(subRoot, subroot_dfs_str);
        // std::cout << "root: " << root_dfs_str << ", subroot: " << subroot_dfs_str << std::endl;
        return (root_dfs_str.find(subroot_dfs_str) != std::string::npos);
    }
private:
    void postorderHelper(TreeNode* root, std::string& postorder) {
        std::stack<TreeNode*> s1;
        std::stack<TreeNode*> s2;

        s1.push(root);
        while (!s1.empty()) {
            TreeNode* current = s1.top();
            s1.pop();
            s2.push(current);

            if (current && current->left) {
                s1.push(current->left);
            } else if (current && !current->left) {
                s1.push(nullptr);
            }
            if (current && current->right) {
                s1.push(current->right);
            } else if (current && !current->right) {
                s1.push(nullptr);
            }
        }

        while (!s2.empty()) {
            if (s2.top()) {
                postorder.append(std::to_string(s2.top()->val));
            } else {
                postorder.append("nullptr");
            }
            s2.pop();
            postorder.append(",");
        }
    }
};
