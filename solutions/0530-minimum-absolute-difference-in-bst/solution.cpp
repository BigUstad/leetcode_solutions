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
    int getMinimumDifference(TreeNode* root) {
        return getInOrderVec(root);
    }
    
    int getInOrderVec(TreeNode* root) {
        if ( root == nullptr )
            return -1;
        return iterativeInOrder(root);
    }
    int iterativeInOrder(TreeNode* root) {
        unsigned int minDiff(100000);
        unsigned int diff(100001);
        std::stack<TreeNode*> s;
        TreeNode* node(root);
        TreeNode* prev = nullptr;
        while ( !s.empty() || node != nullptr ) {
            while ( node != nullptr ) {
                s.push(node);
                node = node->left;
            }
            if ( !s.empty() ) {
                node = s.top();
                s.pop();
                if ( prev != nullptr ) {
                    diff = (node->val) - (prev->val);
                    if ( diff < minDiff )
                        minDiff = diff;
                }
                prev = node;
                node = node->right;
            }
        }
        return minDiff;
    }
    
};

