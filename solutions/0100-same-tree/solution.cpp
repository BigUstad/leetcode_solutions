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
    // detailedBfsHelper - A BFS Helper that prints "ALL" nodes even the non-existant ones.
    // Null nodes are appended in traversal as "L," or "R," signifying left-null or right-null node.
    void detailedBfsHelper(TreeNode* root, std::string& traversal, uint8_t height) {
        if (!root->left && !root->right) {
            traversal.append(std::to_string(root->val));
            return;
        }
        std::queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr); // Signifies end of level traversal
        height--;
        while(!q.empty()) {
            TreeNode* cur = q.front(); q.pop();
            if (!cur) {
                if (q.empty()) {
                    // All nodes processed
                    break;
                }
                // decrement height
                height--;
                q.push(nullptr);
                continue;
            } else {
                if (cur->val > -10001 && cur->val < 10001) {
                    traversal.append(std::to_string(cur->val));
                    traversal.append(",");
                } else if (cur->val == -10001) {
                    traversal.append("L,");
                } else if (cur->val == 10001) {
                    traversal.append("R,");
                }
            }
            if (cur->left) {
                q.push(cur->left);
            } else {
                // Leaf node, don't add null nodes for height = 1
                if (height > 0) {
                    q.push(new TreeNode(-10001));
                }
            }
            if (cur->right) {
                q.push(cur->right);
            } else {
                // Leaf node, don't add null nodes for height = 1
                if (height > 0) {
                    q.push(new TreeNode(10001));
                }
            }
        }
        // std::cout << "2. Traversal: " << traversal << "; height: " << height << std::endl;
    }
    // bfsHelper - A BFS Helper prints straight-forward traversal and also returns height as extra detail
    void bfsHelper(TreeNode* root, std::string& traversal, uint8_t& height) {
        std::queue<TreeNode*> q;
        height = 0;
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {
            traversal.append(std::to_string(root->val));
            return;
        }
        q.push(root);
        q.push(nullptr); // Signifies end of level traversal
        while(!q.empty()) {
            TreeNode* cur = q.front(); q.pop();
            if (!cur) {
                // increment height
                height++;
                if (q.empty()) {
                    // All nodes processed
                    break;
                }
                q.push(nullptr);
                continue;
            } else {
                traversal.append(std::to_string(cur->val));
                traversal.append(",");
            }
            if (cur->left) {
                q.push(cur->left);
            }
            if (cur->right) {
                q.push(cur->right);
            }
        }
        // std::cout << "1. Traversal: " << traversal << "; height: " << height << std::endl;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == q || !p && !q) {
            return true;
        }
        if (!p || !q) {
            return false;
        }
        std::string p_traversal, q_traversal;
        uint8_t p_height, q_height;
        bfsHelper(p, p_traversal, p_height);
        bfsHelper(q, q_traversal, q_height);
        if (p_traversal != q_traversal || p_height != q_height) {
            return false;
        }
        p_traversal.clear(); q_traversal.clear();
        detailedBfsHelper(p, p_traversal, p_height);
        detailedBfsHelper(q, q_traversal, q_height);
        return (p_traversal == q_traversal);
    }
};
