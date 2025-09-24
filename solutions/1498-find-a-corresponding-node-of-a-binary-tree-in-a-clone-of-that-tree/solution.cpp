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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* cloned_target = nullptr;
        int count_till_target = bfsHelper(original, target);
        bfsHelper(cloned, cloned_target, count_till_target);
        return cloned_target;
    }
private:
    // How many nodes did I count before I reached n.
    int bfsHelper(TreeNode* root, TreeNode*& n, int expected_count = INT_MIN) {
        std::queue<TreeNode*> q;
        q.push(root);
        int count = 0;
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            ++count;
            if (expected_count != INT_MIN && count == expected_count) {
                n = cur;
                return -1;
            } else if (expected_count == INT_MIN) {
                if (cur == n) {
                    break;
                }
            }
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        return count;
    }
};
