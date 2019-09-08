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
    bool isValidBST(TreeNode* root) {
        std::stack<TreeNode*> orderS;
       // vector<int> lRetV;
        TreeNode* cur = root;
        TreeNode* prev = nullptr;
        while ( !orderS.empty() || cur != nullptr)
        {
            if ( cur!= nullptr )
            {
                orderS.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = orderS.top();
                orderS.pop();
                //lRetV.push_back(cur->val);
                if ( prev && cur && prev->val >= cur->val )
                {
                    return false;
                }
                prev = cur;
                cur = cur->right;
            }
        }
        return true;
    }
};
