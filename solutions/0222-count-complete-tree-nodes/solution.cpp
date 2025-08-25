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
    int bfsHelper(TreeNode* root) {
        std::list<TreeNode*> q;
        q.push_back(root);
        int complete_node_count = 0;
        std::cout << "BFS: ";
        while (!q.empty()) {
            TreeNode* cur = q.front(); q.pop_front();
            std::cout << cur->val << "\t";
            ++complete_node_count;
            if (cur->left) {
                q.push_back(cur->left);
            }
            if (cur->right) {
                q.push_back(cur->right);
            }
        }
        std::cout << std::endl;
        return complete_node_count;
    }
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        if (!root->left && !root->right) {
            return 1;
        }
        return bfsHelper(root);
    }
};
