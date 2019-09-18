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
    int rangeSumBST(TreeNode* root, int L, int R) {
        sum = 0;
        searchBST(root, L, R);            
        return sum;
    }
    void searchBST(TreeNode* root, int L, int R)
    {
        std::string op = ( root )?std::to_string(root->val):"";
        std::cout << op << std::endl;
        if ( root == nullptr ) 
        {
            return;
        }
        if ( root->val >= L && root->val <= R)
        {
            //std::cout << " Touching " << root->val << " " << " Including" << std::endl;
            sum += root->val;
        }
        if (root->val > L)
        {
            searchBST(root->left, L, R);
        }
        if ( root->val < R)
        {
            searchBST(root->right, L, R);
        }

    }
public:
    int sum;
};

