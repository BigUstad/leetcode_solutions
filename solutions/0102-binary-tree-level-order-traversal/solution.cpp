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
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::queue<TreeNode*> orderQ;
        vector<vector<int>> levelV;
        if ( !root )
            return levelV;
        orderQ.push(root);
        orderQ.push(nullptr);
        vector<int> level;
        /*level.push_back(root->val);
        levelV.emplace_back(level);
        level.clear();*/
        // 2 pow (l-1) entries in a level.
        unsigned int levelIdx = 0;
        unsigned int levelCount = 0;
        while ( !orderQ.empty() )
        {
            TreeNode* node = orderQ.front();
            orderQ.pop();
            /*if ( levelCount++ == pow(2, levelIdx) )
            {
                std::cout << " Inserting " << levelCount << " " << level.size() << std::endl;
                if ( level.size() > 0 )
                    levelV.emplace_back(level);
                level.clear();
                levelIdx++;
            }*/
            if ( node != nullptr )
            {
                level.push_back(node->val); 
                if ( node->left )
                    orderQ.push(node->left);
                if ( node->right )
                    orderQ.push(node->right);
            }    
            else
            {
                std::cout << " Inserting " << levelCount << " " << level.size() << std::endl;
                if ( level.size() > 0 )
                    levelV.emplace_back(level);
                level.clear();
                levelIdx++;
                if (orderQ.size() > 0 )
                    orderQ.push(nullptr);
            }
            std::cout << " Compare " << levelCount << " " << pow(2, levelIdx) << std::endl;
        }
        return levelV;
    }
};
