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
    void postorderHelper(TreeNode* root, TreeNode* n, std::unordered_map<TreeNode*, TreeNode*>& parent_map) {
        std::stack<TreeNode*> s1;
        s1.push(root);
        while (!s1.empty()) {
            TreeNode* current = s1.top();
            s1.pop();
            if (current == n) {
                break;
            }
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

    TreeNode* getLowestCommonAncestor(TreeNode*& root, TreeNode*& p, TreeNode*& q,
                    std::unordered_map<TreeNode*, TreeNode*>& p_parent_map,
                    std::unordered_map<TreeNode*, TreeNode*>& q_parent_map) {
        std::unordered_set<TreeNode*> p_set;
        std::vector<TreeNode*> q_vec;
        TreeNode *cur = p;
        while (cur) {
            p_set.insert(cur);
            cur = p_parent_map[cur];
            if (cur == q) {
                // std::cout << "cur == q" << std::endl;
                return q;
            }
        }

        cur = q;
        while (cur) {
            q_vec.push_back(cur);
            cur = q_parent_map[cur];
            if (cur == p) {
                // std::cout << "cur == p" << std::endl;
                return p;
            }
        }
        // std::cout << "p_set size: " << p_set.size() << std::endl;
        // std::cout << "q_vec size: " << q_vec.size() << std::endl;
        for (auto& q: q_vec) {
            // std::cout << "Checking: " << q->val << std::endl;
            if (p_set.find(q) != p_set.end() && q != root) {
                return q;
            }
        }
        return root;
    }
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
        std::unordered_map<TreeNode*, TreeNode*> p_parent_map;
        std::unordered_map<TreeNode*, TreeNode*> q_parent_map;
        postorderHelper(root, p, p_parent_map);
        postorderHelper(root, q, q_parent_map);
        // std::cout << "p_parent_map size: " << p_parent_map.size() << std::endl;
        // std::cout << "q_parent_map size: " << q_parent_map.size() << std::endl;

        return getLowestCommonAncestor(root, p, q, p_parent_map, q_parent_map);
    }
};
