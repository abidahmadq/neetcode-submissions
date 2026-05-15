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
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, -1001, 1001);
    }
    bool isValidBSTHelper(TreeNode* root, int left, int right) {
        if(root == NULL) {
            return true;
        }
        if(root->val <= left || root->val >= right) {
            return false;
        }
        return isValidBSTHelper(root->left, left, root->val) && isValidBSTHelper(root->right, root->val, right);
    }
};
