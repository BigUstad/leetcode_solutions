/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrToBST_Helper(vector<int>& nums, TreeNode *root, int l, int h)
    {
        if (h < l || l < 0 || h < 0)
            return nullptr;
        int mid = l + (h - l)/2;
        cout << mid << endl;
        root = new TreeNode(nums[mid]);
        root->left = sortedArrToBST_Helper(nums, root, l, mid - 1);
        root->right = sortedArrToBST_Helper(nums, root, mid + 1, h);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0)
            return nullptr;
        if (nums.size() == 1)
        {
            TreeNode* root = new TreeNode(nums[0]);
            return root;
        }
        TreeNode* root = sortedArrToBST_Helper(nums, root, 0, (nums.size() - 1));
        return root;
    }
};
