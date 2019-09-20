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
    int minDiffInBST(TreeNode* root) {
        int min = INT_MAX;
        TreeNode* prev = nullptr;
        if ( !root)
            return min;
        // This function doesn't find min for root
        // So, i will put first min as difference between root & root's predecessor.
        //findDiffInOrderPrev(root, &prev, min );
        return findMinInOrder(root);
    }
    int findMinInOrder(TreeNode* root)
    {
        std::cout << " printInOrder" << std::endl;
        std::stack<TreeNode*> stk;
        //stk.push(root);
        std::vector<int> lst;
        TreeNode* cur = root;
        while ( !stk.empty() || cur != nullptr )
        {
            if ( cur != nullptr )
            {
                stk.push(cur);
                cur = cur->left;
            }
            else
            {
                if ( !stk.empty() )
                {
                    cur = stk.top();
                    stk.pop();
                }

                if ( cur != nullptr )
                {
                    //std::cout << " Add to list:" << cur->val << std::endl;
                    lst.push_back(cur->val);
                }

                cur = cur->right;
            }
        }
        int prev = 0;
        int index = 0;
        int min = INT_MAX;
        for ( auto i:lst )
        {
            if ( index++ > 0 )
            {
                std::cout << " Compare " << i << " " << prev << " " << min << std::endl;
                min = std::min( std::abs(i - prev), min);
            }
            //std::cout << i << " ";
            prev = i;
        }
        std::cout << "Min is: " << min << std::endl;
        return min;
    }
    void findDiffInOrderPrev(TreeNode* cur, TreeNode** prev, int& diffMin)
    {
        if ( cur == nullptr )
            return;
        //std::cout << " Traversing " << cur->val << std::endl;
        // Traverse left
        findDiffInOrderPrev(cur->left, &cur, diffMin);
        // Process Node
        if ( *(prev) != nullptr )
        {
			std::cout << " Touching " << cur->val << " Prev " << (*prev)->val;
            diffMin = std::min(std::abs(cur->val - (*prev)->val), diffMin);
            std::cout << " Min diff yet " << diffMin << "  " <<
                (std::abs(cur->val - (*prev)->val)) << std::endl;
		}
        else
        {
            // This could be root.
            std::cout << " Don't have Prev " << cur->val << std::endl;
        }
        //prev = &cur;

        // Traverse Right
        findDiffInOrderPrev(cur->right, &cur, diffMin);
    }
    void findPrevInOrder(TreeNode* root, int& min)
    {
        TreeNode* cur = root;
        TreeNode* prev = nullptr;
        if ( root->left != nullptr )
        {
            // Rightmost value of Left subtree
            cur = root->left;
            while (cur != nullptr )
            {
                prev = cur;
                cur = cur->right;
            }
            //Value of prev.
            if ( prev != nullptr)
            {
                std::cout << " Rightmost value of left subtree for root- " << prev->val << std::endl;
                min = std::abs(root->val - prev->val);
                prev = nullptr;//For findDiff...
                cur = root;
            }
        }
        if ( root->right != nullptr )
        {
            cur = root->right;
            // Rightmost value of Left subtree
            while (cur != nullptr )
            {
                prev = cur;
                cur = cur->left;
            }
            //Value of prev.
            if ( prev != nullptr)
            {
                std::cout << " Left-most value of Right subtree for root- " << prev->val << std::endl;
                min = std::min(std::abs(root->val - prev->val), min);
                prev = nullptr;//For findDiff...
                cur = root;
            }
        }        
        
    }
};
