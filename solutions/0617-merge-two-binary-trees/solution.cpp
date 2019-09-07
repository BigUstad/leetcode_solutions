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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        std::queue<std::pair<TreeNode*, TreeNode*>> orderQ;
        if ( !t1 && !t2 )
            return nullptr;
        if ( !t1 || !t2 )
        {
            return (( t1 )? t1 : t2);
        }
        TreeNode* head = nullptr;
        orderQ.push(std::make_pair(t1,t2));
        while ( !orderQ.empty() )
        {
            std::pair<TreeNode*, TreeNode*> curPair =
                orderQ.front();
            orderQ.pop();
            if ( curPair.first == nullptr || curPair.second == nullptr )
            {
                continue;
            }
            if ( curPair.first != nullptr && curPair.second != nullptr )
            {
                std::cout << " F: " << curPair.first->val << " S: " << curPair.second->val;
                curPair.first->val += curPair.second->val;
                std::cout << " S: " << curPair.first->val << std::endl;
            }
            else if ( curPair.first != nullptr && curPair.second == nullptr )
            {
                // Leave as is.
            }
            else if ( curPair.first == nullptr && curPair.second != nullptr )
            {
                // Shouldn't happen as we should have copied by now.
            }
            if ( !head )
                head = curPair.first;
            if ( curPair.first->left == nullptr && curPair.second->left != nullptr )
            {
                curPair.first->left = curPair.second->left;
            }
            else
            {
                orderQ.push( std::make_pair(curPair.first->left, curPair.second->left) );
            }
            if ( curPair.first->right == nullptr && curPair.second->right != nullptr )
            {
                curPair.first->right = curPair.second->right;
            }
            else
            {
                orderQ.push( std::make_pair(curPair.first->right, curPair.second->right) );
            }
            
        }
        return head;
    }
};
