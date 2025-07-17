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
    int minDepth(TreeNode* root) {
        if ( !root )
            return 0;
        if ( root && root->left == nullptr && root->right == nullptr)
            return 1;
        std::queue<TreeNode*> orderQ;
        orderQ.push(root);
        orderQ.push(nullptr);
        TreeNode* cur = nullptr;
        TreeNode* prev = nullptr;
        int minDepth = 0;
        int totalDepth = 0;
        bool stopMinDepth = false;
        
        while ( !orderQ.empty() )
        {
            cur = orderQ.front();
            orderQ.pop();
            if ( cur == nullptr)
            {
                if ( !stopMinDepth )
                    ++minDepth;
                ++totalDepth;
                if ( orderQ.size() > 0 )
                    orderQ.push(nullptr);
            }
            else if ( cur &&
                        cur->left == nullptr && cur->right == nullptr )
            {
                // Reached leaf. If first stop min depth count.
                if ( !stopMinDepth )
                {
                    stopMinDepth = true;
                    ++minDepth;
                }
            }
            else
            {
                if ( cur && cur->left != nullptr )
                    orderQ.push(cur->left);
                if ( cur && cur->right != nullptr )
                    orderQ.push(cur->right);
            }
        }
        return minDepth;
    }
};
