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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> levelV;
        if ( !root )
            return levelV;
        std::queue<TreeNode*> orderQ;
        orderQ.push(root);
        orderQ.push(nullptr);
        vector<int> level;
        while ( !orderQ.empty() )
        {
            TreeNode* node = orderQ.front();
            orderQ.pop();
            if ( node == nullptr )
            {
                if ( orderQ.size() > 0 )
                    orderQ.push(nullptr);
                levelV.push_back(level);
                level.clear();
            }
            else
            {
                level.push_back(node->val);
                if ( node->left )
                    orderQ.push(node->left);
                if ( node->right )
                    orderQ.push(node->right);
            }
        }
        std::reverse(levelV.begin(), levelV.end());
        return levelV;
    }
};
