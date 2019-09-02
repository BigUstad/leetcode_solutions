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
    bool isSymmetric(TreeNode* root) {
        bool lRet = true;
        std::queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        while ( !q.empty() )
        {
            TreeNode* n1 = q.front();
            q.pop();
            TreeNode* n2 = q.front();
            q.pop();
            if ( n1 == nullptr && n2 == nullptr )
            {
                //std::cout << " Reached the end." << std::endl;
                lRet &= true;
            }
            if ( ( n1 == nullptr && n2 != nullptr) 
                || ( n2 == nullptr && n1 != nullptr) )
            {
                //std::cout << "Null node not expected: " << n1 << " " << n2 << std::endl;
                lRet &= false;
                break;
            }
            if ( n1 != nullptr && n2 != nullptr && (n1->val != n2->val) )
            {
                //std::cout << " Not equal: " << n1->val << " " << n2->val << std::endl;
                lRet &= false;
                break;
            }
            else
            {
                lRet &= true;
            }

            if (n1 != nullptr )
                q.push(n1->left);
            if (n2 != nullptr )
                q.push(n2->right);
            if (n1 != nullptr )
                q.push(n1->right);
            if (n2 != nullptr )
                q.push(n2->left);
        }
        //std::cout << " Q is empty. " << std::endl;
        return lRet;
    }
};
