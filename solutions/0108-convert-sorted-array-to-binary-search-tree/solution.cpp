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
    TreeNode* constructNode(int nodeVal)
    {
        TreeNode* node = new TreeNode(nodeVal);
        return node;
    }
    TreeNode* sortedArrayToBSTWithIndices(vector<int>& nums, int low, int high)
    {
        if ( low > high )
        {
            return nullptr;
        }
        int mid = ( low + high )/2;
        TreeNode* root = constructNode(nums[mid]);
        root->left = sortedArrayToBSTWithIndices(nums, low, (mid - 1));
        root->right = sortedArrayToBSTWithIndices(nums, (mid+1), high );
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root (sortedArrayToBSTWithIndices(nums, 0, (nums.size() - 1)));
        return root;
    }
};
