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
    int maxDepth(TreeNode* root) {
        std::queue<TreeNode*> orderQ;
        unsigned int levelIdx=0;
        if ( !root )
            return 0;
        orderQ.push(root);
        orderQ.push(nullptr); // null indicates end of level in Q.
        while ( !orderQ.empty() )
        {
            TreeNode* node = orderQ.front();
            orderQ.pop();
            if ( node == nullptr)
            {
                levelIdx++;
                if ( orderQ.size() > 0 )
                    orderQ.push(nullptr);
            }
            else
            {
                if ( node->left )
                    orderQ.push(node->left);
                if ( node->right )
                    orderQ.push(node->right);
            }
        }
        return levelIdx;
    }
};
