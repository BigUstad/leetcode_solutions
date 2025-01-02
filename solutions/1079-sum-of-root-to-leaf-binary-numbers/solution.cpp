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
    int sumRootToLeaf(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int ret_sum = 0;
        std::stack<std::pair<TreeNode*, std::string>> s;
        s.push(std::make_pair(root, ""));
        while (!s.empty()) {
            auto cur = s.top();
            s.pop();

            // std::cout << "  " << cur.first->val;
            // Process cur node
            cur.second.append(std::to_string(cur.first->val));
            // Leaf node calculation
            if (cur.first->left == nullptr && cur.first->right == nullptr) {
                int sum_at_leaf = std::stoi(cur.second, nullptr, 2);
                ret_sum += sum_at_leaf;
                // std::cout << "(L) " << cur.second << std::endl;
            }
            // Push right node first so that left node will be processed before right
            if (cur.first->right != nullptr) {
                s.push(std::make_pair(cur.first->right, std::string(cur.second)));
            }
            // Push left node
            if (cur.first->left != nullptr) {
                s.push(std::make_pair(cur.first->left, std::string(cur.second)));
            }
        }
        //std::cout << std::endl;
        return ret_sum;
    }
};
