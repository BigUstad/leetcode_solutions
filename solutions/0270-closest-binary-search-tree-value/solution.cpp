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
    int closestValue(TreeNode* root, double target) {
        if (root->left == nullptr && root->right == nullptr) {
            return root->val;
        }
        double sdiff = std::abs(target - root->val);
        TreeNode* cur = root;
        int cv = root->val;
        while (cur != nullptr) {
            double dcv = (double)cur->val;
            double cdiff = std::abs(target - dcv);
            if (target == dcv) {
                cv = cur->val;
                break;
            }
            if (cur != root && cdiff <= sdiff) {
                // Choosing the smaller cv
                if ((cdiff < sdiff) ||
                    (cdiff == sdiff && cur->val < cv)) {
                    cv = cur->val;
                }
                sdiff = cdiff;
            }
            if (target < dcv) {
                cur = cur->left;
            } else if (target > dcv ) {
                cur = cur->right;
            }
        }
        return cv;
    }
};
