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
    int goodNodes(TreeNode* root) {
        std::unordered_map<TreeNode*, TreeNode*> parent_map;
        postorderHelper(root, parent_map);
        int l_ret_count = 0;
        for (auto p: parent_map) {
            // Key is root. No parent.
            if (!p.second) {
                ++l_ret_count;
                continue;
            };
            int cur_val = p.first->val;
            TreeNode* cur = p.second;
            bool yup = true;
            // std::cout << "Parents of: " << cur_val << " : ";
            while (cur) {
                // std::cout << cur->val << ", ";
                if(cur_val < cur->val) {
                    // std::cout << "False for: " << cur_val << ", with: " << cur->val << std::endl;
                    yup = false;
                }
                cur = parent_map[cur];
            }
            // std::cout << ". Ans: " << ((yup)?"Good":"Not Good") << std::endl;
            if (yup) ++l_ret_count;
        }
        return l_ret_count;
    }
private:
    void postorderHelper(TreeNode* root, std::unordered_map<TreeNode*, TreeNode*>& parent_map) {
        std::stack<TreeNode*> s1;
        s1.push(root);
        parent_map[root] = nullptr;
        while (!s1.empty()) {
            TreeNode* current = s1.top();
            s1.pop();
            bool p = parent_map[current];
            if (current && current->left) {
                parent_map[current->left] = current;
                s1.push(current->left);
            }
            if (current && current->right) {
                parent_map[current->right] = current;
                s1.push(current->right);
            }
        }
    }

};
