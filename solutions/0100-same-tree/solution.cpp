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
    void buildTreeVec(TreeNode* head, vector<std::string>& vec)
    {
        std::stack<TreeNode*> orderStack;
        // head null check is done.
        orderStack.push(head);
        TreeNode* cur;
        while ( !orderStack.empty() )
        {
            cur = orderStack.top();
            orderStack.pop();
            if ( cur == nullptr )
            {
                vec.push_back("NULL");
                //std::cout << " Pushing " << "NULL."<< std::endl;
            }
            else
            {
                vec.push_back(std::to_string(cur->val)); 
                //std::cout << " Pushing " << std::to_string(cur->val) << std::endl;
                orderStack.push(cur->right);
                orderStack.push(cur->left);
            }
        }
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<std::string> tree1Vec;
        vector<std::string> tree2Vec;
        if ( !p && !q )
            return true;
        if ( p && !q || !p && q )
            return false;
        buildTreeVec(p, tree1Vec);
        buildTreeVec(q, tree2Vec);
        if ( tree1Vec.size() != tree2Vec.size() )
        {
            return false;
        }
        for ( int i=0, j=0; ( i < tree1Vec.size() && j < tree2Vec.size() );
                ++i, ++j)
        {
            if ( tree1Vec[i].compare(tree2Vec[j]) != 0 )
            {
                return false;
            }
        }
        tree1Vec.clear();
        tree2Vec.clear();
        return true;
    }    
};
